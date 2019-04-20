#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <regex.h>
#include <dirent.h>
#include <fcntl.h>
#include <linux/input.h>
#include <stdbool.h>


bool Input ( void )
{
    static int first = 1;
    static int mouseFd = -1;
    static int keyboardFd = -1;
    struct input_event ev[64];
    int rd;
    bool ret = false;
    // Set up the devices on the first call
    if(first)
    {
        DIR *dirp;
        struct dirent *dp;
        regex_t kbd,mouse;

        char fullPath[1024];
        static char *dirName = "/dev/input/by-id";
        int result;

        if(regcomp(&kbd,"event-kbd",0)!=0)
        {
            printf("regcomp for kbd failed\n");
            return true;
        }
        if(regcomp(&mouse,"event-mouse",0)!=0)
        {
            printf("regcomp for mouse failed\n");
            return true;
        }

        if ((dirp = opendir(dirName)) == NULL)
        {
            perror("couldn't open '/dev/input/by-id'");
            return true;
        }

        // Find any files that match the regex for keyboard or mouse

        do {
            errno = 0;
            if ((dp = readdir(dirp)) != NULL)
            {
                printf("readdir (%s)\n",dp->d_name);
                if(regexec (&kbd, dp->d_name, 0, NULL, 0) == 0)
                {
                    printf("match for the kbd = %s\n",dp->d_name);
                    sprintf(fullPath,"%s/%s",dirName,dp->d_name);
                    keyboardFd = open(fullPath,O_RDONLY | O_NONBLOCK);
                    printf("%s Fd = %d\n",fullPath,keyboardFd);
                    printf("Getting exclusive access: ");
                    result = ioctl(keyboardFd, EVIOCGRAB, 1);
                    printf("%s\n", (result == 0) ? "SUCCESS" : "FAILURE");

                }
                if(regexec (&mouse, dp->d_name, 0, NULL, 0) == 0)
                {
                    printf("match for the kbd = %s\n",dp->d_name);
                    sprintf(fullPath,"%s/%s",dirName,dp->d_name);
                    mouseFd = open(fullPath,O_RDONLY | O_NONBLOCK);
                    printf("%s Fd = %d\n",fullPath,mouseFd);
                    printf("Getting exclusive access: ");
                    result = ioctl(mouseFd, EVIOCGRAB, 1);
                    printf("%s\n", (result == 0) ? "SUCCESS" : "FAILURE");
                }
            }
        } while (dp != NULL);

        closedir(dirp);
        regfree(&kbd);
        regfree(&mouse);

        first = 0;
        if((keyboardFd == -1) || (mouseFd == -1)) return true;
    }

    // Read events from mouse
    rd = read(mouseFd,ev,sizeof(ev));
    if(rd > 0)
    {
        int count,n;
        struct input_event *evp;

        count = rd / sizeof(struct input_event);
        n = 0;
        while(count--)
        {
            evp = &ev[n++];
            if(evp->type == 1)
            {
                if(evp->code == BTN_LEFT)
                {
                    if(evp->value == 1)   // Press
                        printf("Left button pressed\n");
                    else printf("Left button released\n");
                }
            }
            else if(evp->type == 2)
            {
                if(evp->code == 0)
                {
                    // Mouse Left/Right
                    printf("Mouse moved left/right %d\n",evp->value);
                }
                else if(evp->code == 1)
                {
                    // Mouse Up/Down
                    printf("Mouse moved up/down %d\n",evp->value);
                }
            }
        }
    }

    // Read events from keyboard
    rd = read(keyboardFd,ev,sizeof(ev));
    if(rd > 0)
    {
        int count,n;
        struct input_event *evp;
        count = rd / sizeof(struct input_event);
        n = 0;
        while(count--)
        {
            evp = &ev[n++];
            if(evp->type == 1)
            {
                if(evp->value == 1)
                {
                    if(evp->code == KEY_LEFTCTRL)
                    {
                        printf("Left Control key pressed\n");
                    }
                    if(evp->code == KEY_LEFTMETA )
                    {
                        printf("Left Meta key pressed\n");
                    }
                    if(evp->code == KEY_LEFTSHIFT)
                    {
                        printf("Left Shift key pressed\n");
                    }
                }
            if((evp->code == KEY_Q) && (evp->value == 1))
                ret = true;;
            }
        }
    }
    return(ret);
}

int main(int argc,char **argv)
{
    int loops;
    while(Input() == false)
    {
        loops += 1;
    }
    printf(" %d loops \n",loops);
    return(1);
}

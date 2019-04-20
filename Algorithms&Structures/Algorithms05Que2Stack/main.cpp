#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

struct myqueue
{
    stack< pair<int,int> > s1, s2;
    int find_max()
    {
        int max_el;
        if(s1.empty() || s2.empty())
            max_el = s1.empty() ? s2.top().second : s1.top().second;
        else
            max_el = std::max(s1.top().second, s2.top().second);
        return max_el;
    }
    void push(int var)
    {
        int maxima = s1.empty() ? var : max(var, s1.top().second);
        s1.push(make_pair(var,maxima));
    }
    int pop()
    {
        if(s2.empty())
            while(!s1.empty())
            {
                int element = s1.top().first;
                s1.pop();
                int maxima = s2.empty() ? element : max(element, s2.top().second);
                s2.push(make_pair(element,maxima));
            }
        int result = s2.top().first;
        s2.pop();
        return result;
    }
};

int main()
{

    int n, m, var;
    cin >> n;
    int input_arr[n];
    for(int i=0 ; i<n; i++)
    {
        cin >> var;
        input_arr[i] = var;
    }
    cin >> m;
    myqueue que;

    for(int i=0; i<m;i++)
        que.push(input_arr[i]);
    cout<< que.find_max()<<" ";
    for(int i=m;i<n;i++)
    {
        que.pop();
        que.push(input_arr[i]);
        cout<<que.find_max()<<" ";
    }
    return 0;
}

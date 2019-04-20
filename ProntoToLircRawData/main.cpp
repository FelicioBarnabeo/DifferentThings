#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct ProntoCode
{

    string key_name;
    vector<int> code;
};

struct Remote
{
    string remote_name;
    vector<ProntoCode> raw;
};

int main(int argc, char *argv[])
{
    vector<Remote> remotes;
    Remote newremote;
    ProntoCode code;
    fstream fin("PRONTO.txt",fstream::in);
    string raw;

    //Read pronto remotes with pronto codes and make database of remotes
    while(getline(fin,raw))
    {
        //std::cout<<raw<<endl;
        if(raw.find("remote ")!=std::string::npos)
        {

            newremote.remote_name = raw;
            continue;
        }
        if(raw.find("end remote")!= std::string::npos){
            newremote.raw.push_back(code);
            code.code.clear();
            code.key_name.clear();
            remotes.push_back(newremote);
            newremote.raw.clear();
            newremote.remote_name.clear();
            continue;
        }
        if(raw.find("name")!=std::string::npos)
        {
            if(!code.code.empty())
                newremote.raw.push_back(code);
            code.key_name = raw;
            code.code.clear();
            continue;
        }
        if(raw.empty())
            continue;
        istringstream line(raw);
        int x;
        line>>hex;
        while(line >> x){
            code.code.push_back(x);
        }
    }

    fin.close();

     ofstream out("msopRawData.txt",fstream::out);

    //Print out remotes from database
    for(auto var: remotes)
    {
        std::cout<<"HOME"<<endl;
        out<<"begin remote"<<endl;
        for(auto jar: var.raw){

            out<<endl<<jar.key_name<<endl;
            int i = 0;
            out<<"    ";
            for(int j = 4;j<jar.code.size()-1;j++){
                i++;
                out<< int(jar.code[j]*27.7) << "     ";
                if(!(i%6)) out<<endl<<"    ";
            }
            out<<endl;
        }
        out<<"end remote"<<endl;
        std::cout<<"ENDING";
    }

    out.close();

    return 0;
}

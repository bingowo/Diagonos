#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("ProgWithComments.cpp");
    ofstream fout;
    fout.open("MyProgWithoutComments.cpp");
    char c;
    int state=0;
    while(fin.get(c)){
        switch(state)
        {
            case 0:
                if(c=='/')
                    state=1;
                else if(c=='\'')
                    state=6;
                else if(c=='\"')
                    state=8;
                else
                    fout << c;
                break;
            case 1:
                if(c=='*')
                    state=2;
                else if(c=='/')
                    state=4;
                else
                {
                    fout << '/' << c;
                    state=0;
                }
                break;
            case 2:
                if(c=='*')
                    state=3;
                else
                    state=2;
                break;
            case 3:
                if(c=='/')
                    state=0;
                else if(c=='*')
                    state=3;
                else
                    state=2;
                break;
            case 4:
                if(c=='\\')
                    state=5;
                else if(c=='\n')
                {
                    state=0;
                    fout << c;
                }
                break;
            case 5:
                if(c=='\\')
                    state=5;
                else
                    state=4;
                break;
            case 6:
                if(c=='\\')
                    state=7;
                else if(c=='\'')
                {
                    state=0;
                    fout << c;
                }
                break;
            case 7:
                state=6;
                break;
            case 8:
                if(c=='\\')
                    state=9;
                else if(c=='\"')
                {
                    state=0;
                    fout << c;
                }
                break;
            case 9:
                state=8;
                break;
        }
        if(state==6||state ==7||state==8||state==9){
            fout << c;
        }
    }
    return 0;
}
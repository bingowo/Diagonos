#include <iostream>
#include <string>
using namespace std;

int main()
{
    char ch=cin.get();
    int flag = 0;
    while(!cin.eof())
    {
        switch(flag)
        {
            case 0:
                if(ch=='\\')
                {
                    flag=2;cout.put(ch);
                }
                else if(ch == '"')
                {
                    flag = 1;cout.put(ch);
                }
                else if(ch=='/')
                {
                    flag=3;
                }
                else cout.put(ch);
                break;
            case 1:
                if(ch=='\\') flag=7;
                else if(ch=='"') flag=0;
                cout.put(ch);
                break;
            case 2:
                cout.put(ch);
                flag=0;
                break;
            case 3:
                if(ch=='/')
                {
                    flag=5;
                }
                else if(ch=='*')
                {
                    flag=4;
                }
                else
                {
                    flag=0;cout.put(ch);
                }
                break;

            case 4:
                if(ch=='*') flag=6;
                break;
            case 5:
                if(ch=='\n')
                {
                    flag=0;cout.put(ch);
                }
                break;
            case 6:
                if(ch=='*') flag=6;
                else if(ch=='/') flag=0;
                else flag=4;
                break;
            case 7:
                cout.put(ch);
                flag=1;
                break;
        }
       cin.get(ch);
    }
    return 0;
}

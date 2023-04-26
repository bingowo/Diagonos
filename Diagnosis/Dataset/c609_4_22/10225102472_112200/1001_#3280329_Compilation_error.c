#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin;//("ProgWithComments.cpp");
    fin.open("ProgWithComments.cpp");
    ofstream fout;//("ProgWithoutComments.cpp");
    fout.open("ProgWithoutComments.cpp");

    char ch;
    int flag {};

    while(fin.get(ch))
    {
        switch(flag)
        {
        case 0:
            if(ch == '"')
            {
                flag = 1;
                fout << ch;
                break;
            }

            else if(ch == '\'')
            {
                flag = 2;
                fout << ch;
                break;
            }

            else if(ch == '\\')
            {
                fout << ch;
                fin.get(ch);
                fout << ch;
                break;
            }

            else if(ch == '/')
            {
                char first;
                fin.get(first);

                if(first == '/')
                {
                    string line;
                    getline(fin, line);
                    fout << '\n';
                    break;
                }

                else if(first == '*')
                {
                    char second;
                    fin.get(second);
                    first = second;
                    while(fin.get(second))
                    {
                        if(first == '*' && second == '/')
                        {
                            break;
                        }
                        first = second;
                    }
                    break;
                }
                else
                {
                    fout << ch << first;
                    break;
                }
            }

            else
            {
                fout << ch;
                break;
            }

        case 1:
            if(ch == '\\')
            {
                fout << ch;
                fin.get(ch);
                fout << ch;
                break;
            }

            if(ch == '"')
            {
                fout << ch;
                flag = 0;
                break;
            }

            fout << ch;
            break;

        case 2:
            if(ch == '\\')
            {
                fout << ch;
                fin.get(ch);
                fout << ch;
                break;
            }

            if(ch == '\'')
            {
                fout << ch;
                flag = 0;
                break;
            }

            fout << ch;
            break;
        }
    }

    fin.close();
    fout.close();

    return 0;
}
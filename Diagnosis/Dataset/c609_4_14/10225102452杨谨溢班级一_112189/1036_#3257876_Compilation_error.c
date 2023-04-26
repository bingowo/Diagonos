#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int main(int argc,char* argv[])
{
    ifstream keywords(argv[1]);
    ifstream text(argv[2]);
    ofstream result(argv[3],std::ios_base::out);
    vector <string> keys;
    string s;
    while(keywords)
    
    keywords.close();
    text.close();
    result.close();
    return 0;
}

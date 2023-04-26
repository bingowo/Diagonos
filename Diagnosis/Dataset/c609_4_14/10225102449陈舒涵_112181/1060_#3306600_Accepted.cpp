#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    vector<char> ans;
    int i = 0;
    while (i < len){
        ans.push_back(s[i]);
        int k = i + 1;
        while (k < len && s[k] == s[i]){
            k ++;
        }
        if (k < len && s[k] > s[i]){
            ans.push_back(s[i]);
        }
        i ++;
    }
    for (auto it = ans.begin(); it != ans.end(); it ++){
        cout << *it;
    }
    return 0;
}
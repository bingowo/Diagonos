#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;

int scoreOfParentheses(string &S)
{
    stack<int> s;
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == '(')
        {
            s.push_back(0);
        }
        else
        {
            int score = 0;
            while (s.top() != 0)
            {
                score += s.top();
                s.pop();
            }
            s.pop();
            int newScore = score == 0 ? 1 : score * 2;
            s.push_back(newScore);
        }
    }
    int totalScore = 0;
    while (!s.empty())
    {
        totalScore += s.top();
        s.pop();
    }
    return totalScore;
}

int main()
{
    string S;
    cin >> S;
    cout << scoreOfParentheses(S) << endl;
    return 0;
}
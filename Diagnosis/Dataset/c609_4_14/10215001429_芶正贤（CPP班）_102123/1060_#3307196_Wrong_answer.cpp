#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include<algorithm>
using namespace std;

vector<string> expandString(const string& str)
{
    vector<string> result;
    if (str.empty())
    {
        result.push_back("");
        return result;
    }

    stack<pair<const char*, int>> s;
    s.push(make_pair(str.c_str(), str.size()));

    while (!s.empty())
    {
        const char* ptr = s.top().first;
        int len = s.top().second;
        s.pop();

        if (len == 0)
        {
            result.push_back("");
        }
        else
        {
            char c = *ptr;
            const char* remaining = ptr + 1;
            int remaining_len = len - 1;
            s.push(make_pair(remaining, remaining_len));

            for (const string& sub : result)
            {
                s.push(make_pair(ptr, remaining_len));
                s.push(make_pair(remaining, remaining_len));
                string temp = c+sub;
                result.push_back(temp);
                result.push_back(c + temp);
            }
        }
    }

    return result;
}

int main()
{
    string stand;
    cin >> stand;
    vector<string> arr = expandString(stand);
    string min = *min_element(arr.begin(), arr.end());
    cout << min << endl;
    return 0;
}

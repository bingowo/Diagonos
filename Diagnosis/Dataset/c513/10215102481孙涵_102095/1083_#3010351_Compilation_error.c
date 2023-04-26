#include<iostream>

using namespace std;

int main()
{
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
    
        int n;
        cin >> n;
        cout << "case #" << i << ":"<<endl;
        int count = 0;
        for(int i = 1; i <= n; i++)
        {
    
            int temp = i;
            while(temp % 5 == 0)
            {
    
                temp /= 5;
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}

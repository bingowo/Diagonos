#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp1(const int a, const int b)
{
    return a<b;
}
bool cmp2(const int a, const int b)
{
    return a>b;
}
int main()
{
    char n; cin >> n;
    int k=0;
    vector<int> number1(110),number2(110);
    while(cin >> number1[k]) k+=1;
    if(n=='A')
    {
        sort(number1.begin(),number1.begin()+k,cmp1);
        number2.resize(unique_copy(number1.begin(),number1.begin()+k,number2.begin())-number2.begin());
    }
    else
    {
        sort(number1.begin(),number1.begin()+k,cmp2);
        number2.resize(unique_copy(number1.begin(),number1.begin()+k,number2.begin())-number2.begin());
    }
    auto j=number2.begin();
    for(j=number2.begin();j!=number2.end()-1;j++)
        cout << *j << ' ';
    cout << *j << endl;
    return 0;
}

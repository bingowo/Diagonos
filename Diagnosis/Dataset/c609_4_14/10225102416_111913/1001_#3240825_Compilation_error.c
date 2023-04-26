#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

void StackSort(stack<int>& s)
{ // TODO: ...

}

void display(const stack<int>& s)
{
    stack<int> t{s};
    while (!t.empty()) cout<<t.top()<<endl,t.pop();
    cout<<endl;
}

int main(int argc,char**argv)
{
    const int n{20};
    srand((unsigned)time(0));
    stack<int> s;
    for (int i{};i<n;i++) s.push(rand()%100);
    cout<<"Before sorting:"<<endl<<endl;  display(s);
    cout<<"After sorting:"<<endl; StackSort(s); display(s);
    return 0;
}

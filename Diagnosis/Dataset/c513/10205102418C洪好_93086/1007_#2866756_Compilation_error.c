//#include <bits/stdc++.h>
//using namespace std;
#include<stdio.h>
typedef long long ll;
int T, cnt;
stack<int> myStack;
int a[100];
void getBinary(ll num)
{
    while(num)
    {
        myStack.push(num%2);
        num/=2;
    }
}
int main()
{
    //cin>>T;
    scanf("%d",&T);
    while(T--)
    {
        ll num;
        //cin>>num;
        scanf("%d",&num);
        getBinary(num);
        int l=0;
        while(!myStack.empty()){
            a[l++]=myStack.top();
            myStack.pop();
        }
        int len=1;
        int maxi=len;
        for(int i=1;i<l;++i){
            if(a[i]!=a[i-1]) len++;
            else {
                if(a[i]==0) {
                    len=0;
                    continue;
                }
                else len=1;
            }
            if(maxi<len) maxi=len;//after every loop, if true, we update maxi
        }
        printf("case #%d:\n",cnt++);
        //cout<<maxi<<endl;
        printf("%d\n",maxi);
    }
    return 0;
}
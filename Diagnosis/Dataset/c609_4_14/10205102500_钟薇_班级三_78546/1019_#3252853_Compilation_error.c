#include<bits/stdc++.h>
using namespace std;
struct num{
    int a; // 输入的数本身 
    int g; //输入的数的个位数 
}s[1000000];
// https://baike.baidu.com/item/sort%E5%87%BD%E6%95%B0/11042699?fr=aladdin
bool cmp(num a,num b){
    if(a.g>b.g)
        return false;
    if(a.g<b.g)
        return true;
    if(a.a>b.a)
        return false;
    return true;
}
 
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a;
        s[i].g=s[i].a%10;
    }
    sort(s+1,s+1+n,cmp);
    for(int i=1;i<=n;i++){
        cout<<s[i].a<<" ";
        
    }
    return 0;
}

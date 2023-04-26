#include<cstdio>
#include<iostream>
#include<cstring>
const int maxn=1000;
using namespace std;
int t[maxn],A[maxn];
char str1[maxn],str2[maxn];
int n,m;
void solve(char *str1,char *str2,int n,int m)
{
    int i,len,k;
    len=strlen(str1);
    for(i=len;i>=0;i--)
    {
        t[len-1-i]=str1[i]-(str1[i]<58?48:str1[i]<97?55:61);
        //小于58说明是48-57是数字
        //小于97是65-90为大写英文字母
        //大于97是97-122为小写英文字母！
        //同时也说明了0-9存的是数字
        //10-25存的是大写字母
        //26-61存的是小写字母
    }
    for(k=0;len;)
    {
        for(i=len;i>=1;i--)
        {
            t[i-1]+=t[i]%m*n;
            t[i]/=m;
        }
        A[k++]=t[0]%m;
        t[0]/=m;
        while(len>0&&!t[len-1])
        {
            len--;
         }
    }
    str2[k]=NULL;
    for(i=0;i<k;i++)
    {
        str2[k-1-i]=A[i]+(A[i]<10?48:A[i]<36?55:61);
    }
}
int main()
{
    int m;
    while(cin>>str1>>m)
    {
        if(str1[0]=='-')
        {
            solve(str1+1,str2,10,m);
            cout<<"-"<<str2<<endl;
        }
        else
        {
            solve(str1,str2,10,m);
            cout<<str2<<endl;
        }
    }
}
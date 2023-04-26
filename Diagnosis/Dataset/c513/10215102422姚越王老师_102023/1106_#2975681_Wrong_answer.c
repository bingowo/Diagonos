#include<stdio.h>
#include<string.h>
#define C 5000
#define N 100000007
int find_diff(char a,char b,char c)
{
    if(a==b&&b==c)return 1;
    else if(a==b||b==c||a==c)return 2;
    return 3;
}
int main()
{
    char s[1010],a,b,c;scanf("%s",s);
    int i,ans[1010]={0},cnt=0,len=strlen(s);
    if(len==1){printf("1");return 0;}
    for(i=0;s[i];++i)
    {
        if(len>1&&!i)
        {
            a=s[0];b=s[1];
            if(a==b)ans[cnt++]=1;
            else ans[cnt++]=2;
        }
        else if(len>1&&i==len-1)
        {
            a=s[i];b=s[i-1];
            if(a==b)ans[cnt++]=1;
            else ans[cnt++]=2;
        }
        else
        {
            a=s[i-1];b=s[i];c=s[i+1];
            ans[cnt++]=find_diff(a,b,c);
        }
    }
    int A=ans[0];
    for(i=0;i<cnt;++i)A=(A*ans[i]%N)%N;
    printf("%d",A);
}
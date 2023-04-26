#include<stdio.h>
#include<string.h>
#define C 5000
int find_diff(char a,char b,char c)
{
    if(a==b&&b==c)return 1;
    else if(a==b||b==c||a==c)return 2;
    return 3;
}
void multi(int* A,int n)
{
    int tmp,carry=0;
    for(int i=C-1;i>-1;--i)
    {
        tmp=A[i]*n+carry;
        if(tmp>=10){A[i]=tmp%10;carry=tmp/10;}
        else {A[i]=tmp;carry=0;}
    }
    return;
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
    int A[C]={0};A[C-1]=1;
    for(i=0;i<cnt;++i)multi(A,ans[i]);
    for(i=0;i<C;++i)if(A[i])break;
    for(i;i<C;++i)printf("%d",A[i]);
    return 0;
}
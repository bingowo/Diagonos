#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int p[30]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};
int ans[30]={0};
void turn(char s[],int t[], int n)
{
    int len=strlen(s);
    for(int i=len-1;i>0;i--)
    {
        if(s[i]==',') continue;
        if(s[i-1]==',')
        {
            t[n]=s[i]-'0';n--;
        }
        else
        {
            t[n]=(s[i-1]-'0')*10+(s[i]-'0');n--;i--;
        }
    }
    if(s[1]==',' || s[1]=='\0') t[n]=s[0]-'0';
}
void add(int a[],int b[],int n)
{
    int carry=0,k=0;
    for(int i=n;i>=0;i--)
    {
        ans[i+1]=(a[i]+b[i]+carry)%p[k];
        carry=(a[i]+b[i]+carry)/p[k];
        k++;
    }
    ans[0]=carry;
}
int main()
{
    int T;
    scanf("%d",&T);
    char s[60],t[60];
    for(int cas=0;cas<T;cas++)
    {
        scanf("%s %s",s,t);
        int x[30]={0},y[30]={0};
        int len1=0;int len2=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]==',') len1++;
        }
        for(int i=0;i<strlen(t);i++)
        {
            if(t[i]==',') len2++;
        }
        len1++;len2++;
        int len=len1>len2?len1:len2;
        turn(s,x,len-1);
        turn(t,y,len-1);
        //for(int i=0;i<len;i++) printf("%d,",x[i]);
        add(x,y,len-1);
        printf("case #%d:\n",cas);
        if(ans[0]!=0) printf("%d,",ans[0]);
        for(int i=1;i<len;i++) printf("%d,",ans[i]);
        printf("%d\n",ans[len]);
    }
}

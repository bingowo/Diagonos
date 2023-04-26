#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int slo(char s[])
{
    int t,a[200],id=1,i=0;
    memset(a,0,200);
    a[0]=-2;
    while(s[i])
    {
        if(s[i]=='(')
        {
             t=1;
             if(id==1)
                a[id++]=t;
             else if(t-a[id-1]==-1)
                a[id++]=t;
             else
                break;
        }
        else if(s[i]=='[')
        {
            t=2;
             if(id==1)
                a[id++]=t;
             else if(t-a[id-1]==-1)
                a[id++]=t;
             else
                break;
        }
        else if(s[i]=='{')
        {
           t=3;
             if(id==1)
                a[id++]=t;
             else if(t-a[id-1]==2)
                a[id++]=t;
             else
                break;
        }
        else if(s[i]==')')
        {
            t=1;
            if(t==a[id-1])
                id--;
            else
                break;

        }
        else if(s[i]==']')
        {
            t=2;
            if(t==a[id-1])
                id--;
            else
                break;
        }
        else if(s[i]=='}')
        {
            t=3;
            if(t==a[id-1])
                id--;
            else
                break;
        }
        i++;
    }
    if(id!=1)
        return -1;
    else
        return 1;
}
int main()
{
    int n,i,t;
    char s[200];
    scanf("%d",&n);
    for(int j=0; j<n; j++)
    {
        scanf("%s",s);
        t=slo(s);
        if(t==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
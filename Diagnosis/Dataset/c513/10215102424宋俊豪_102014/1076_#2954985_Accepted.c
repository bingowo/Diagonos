#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int slo(char s[])
{
    int t,a[200],id=0,i=0;
    memset(a,0,200);
    a[0]=-1;
    while(s[i])
    {
        if(s[i]=='(')
        {
             t=1;
             if(id==0)
                a[++id]=t;
             else if(t-a[id]==-1)
                a[++id]=t;
             else
                break;
        }
        else if(s[i]=='[')
        {
            t=2;
            if(id==0)
                a[++id]=t;
             else if(t-a[id]==-1)
                a[++id]=t;
             else
                break;
        }
        else if(s[i]=='{')
        {
           t=3;
             if(id==0)
                a[++id]=t;
             else if(t-a[id]==2)
                a[++id]=t;
             else
                break;
        }
        else if(s[i]==')')
        {
            t=1;
            if(id==0)
                break;
            else if(t==a[id])
                id--;
            else
                break;
        }
        else if(s[i]==']')
        {
            t=2;
            if(id==0)
                break;
            else if(t==a[id])
                id--;
            else
                break;
        }
        else if(s[i]=='}')
        {
            t=3;
            if(id==0)
                break;
            else if(t==a[id])
                id--;
            else
                break;
        }
        i++;
    }
    if(id!=0||i!=strlen(s))
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

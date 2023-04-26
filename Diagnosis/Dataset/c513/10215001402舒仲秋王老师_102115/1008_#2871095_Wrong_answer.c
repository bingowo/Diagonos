#include <stdio.h>
#include <stdlib.h>

void atob(int a,int t[])
{
    int b,i;
    for(i=0;a!=0;i++)
    {
        b=a%2;
        t[i]=b;
        a/=2;
    }
    t[i]=2;
}

int cmp(int a,int b)
{
    int flag,A[100],B[100],i,c;
    if(a<b) {c=a;a=b;b=c;}
    atob(a,A),atob(b,B);
    for(i=0;A[i]!=2;i++)
    {
        if(B[i]!=2)
        {
            if(A[i]!=B[i]) flag+=1;
        }
        else
        {
            for(;A[i]!=2;i++) flag+=1;
            break;
        }
    }
    return flag;
}

int main()
{
    int n,A[100],B[100],i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&A[i],&B[i]);
    }
    for(i=0;i<n;i++) printf("%d\n",cmp(A[i],B[i]));
    return 0;
 }

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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

int GCD(int m,int n)
{
    int q,p;
    if(m<=n) {p=m;q=n;}
    else {q=m;p=n;}
    int ret;
    if(p==1) ret=1;
    else if(q%p==0) ret=p;
    else ret=GCD(p,q%p);
    return ret;
}

void midu(char s[],int ret[])
{
    int l=strlen(s),S[100][100],i,j,sum0=0,sum1=0;
    for(i=0;i<l;i++)
    {
        atob((int)s[i],S[i]);
    }
    for(i=0;i<l;i++)
    {
        for(j=0;S[i][j]!=2;j++)
        {
            if(S[i][j]==1) sum1+=1;
        }
    }
    sum0=8*l-sum1;
    ret[0]=sum1/GCD(sum1,sum1+sum0),ret[1]=(sum1+sum0)/GCD(sum0,sum0+sum1);
}

int main()
{
    char s[100][100];int ret[2],n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;s[i][j]=getchar()&&s[i][j]!='\n';j++);
    }
    for(i=0;i<n;i++)
    {
        printf("case #%d\n",i);
        midu(s[i],ret);
        printf("%d/%d\n",ret[0],ret[1]);
    }
    return 0;
}

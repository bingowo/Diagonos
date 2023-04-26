#include<stdio.h>
#include<math.h>

int main()
{
    int n,m,i=0,j=0,a=0,b=0,rest=0;
    char ans[10000];
    scanf("%d%d",&n,&m);
    if(n==0) printf("0");
    else if(n>0)
    {
        while(n)
        {
            if(n%m==0)
            {
                ans[i++]='0';
                n/=m;
            }
            else if(n>0)
            {
                a=n;
                n/=m;
                b=a-n*m+rest;
                if(b>abs(m))
                {
                    b%=abs(m);
                    rest/=b;
                }
                if(b>=10) ans[i++]=b+'A'-10;
                else ans[i]=b+'0';
            }
            else if(n<0)
            {
                a=n;
                n/=m+1;
                b=a-m*n+rest;
                if(b>abs(m))
                {
                    b%=abs(m);
                    rest/=abs(m);
                }
                if(b>=10) ans[i++]=b+'A'-10;
                else ans[i++]=b+'10';
            }
        }
        for(j=i-1;j>=0;j--) printf("%c",ans[j]);
    }
    return 0;
}

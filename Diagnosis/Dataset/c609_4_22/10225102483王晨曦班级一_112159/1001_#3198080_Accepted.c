#include <stdio.h>
#include <stdlib.h>
#define N 10000
void interchange(int a,int b)
{
    char c[N],h[N]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int cnt=0,r;
            while(a>0)
            {
                r=a%b;
                c[cnt]=h[r];
                a=a/b;
                cnt++;
            }
            for(int i=(cnt-1);i>=0;i--) printf("%c",c[i]);
            printf("\n");
}

int main()
{
    int n,a[N],b[N];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        scanf("%d",&b[i]);
    }
    for(int k=0;k<n;k++)
    {
        if(a[k]<0)
            {
                a[k]=(-1)*a[k];
                printf("-");
            }
        if(b[k]>=10) interchange(a[k],b[k]);
        else if(b[k]==8) printf("%o",a[k]);
        else
        {
            int cnt=0,c[N];
            while(a[k]>0)
            {
                c[cnt]=a[k]%b[k];
                a[k]=a[k]/b[k];
                cnt++;
            }
            for(int i=(cnt-1);i>=0;i--) printf("%d",c[i]);
            printf("\n");
        }
    }
    return 0;
}
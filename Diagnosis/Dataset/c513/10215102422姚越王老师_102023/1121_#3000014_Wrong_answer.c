#include<stdio.h>
#include<string.h>
#define N 11
#define C 3000
int main()
{
    int n,i,j;scanf("%d",&n);
    int a[N];
    for(i=0;i<n;++i)scanf("%d",&a[i]);
    int len=0;
    for(i=0;i<n;++i)len+=a[i];
    int b[C],c[C];
    memset(b,0,4*C);
    memset(c,0,4*C);
    b[len]=1;
    for(i=0;i<n;++i)
    {
        for(j=0;j<=2*len;++j)
        {
            if(b[j])
            {
                if(j-a[i]>=0&&c[j-a[i]]==0)
                {
                    b[j-a[i]]=1;
                    c[j-a[i]]=1;
                }
                if(j+a[i]<=2*len&&c[j+a[i]]==0)
                {
                    b[j+a[i]]=1;
                    c[j+a[i]]=1;
                }
            }
            
        }
        memset(c,0,4*C);
    }
    for(i=len+1;i<2*len+1;++i)printf("%d",b[i]);
    return 0;
}
#include<stdio.h>
#include<string.h>
#define N 11
int main()
{
    int n,i,j;scanf("%d",&n);
    int a[N];
    for(i=0;i<n;++i)scanf("%d",&a[i]);
    int len=0;
    for(i=0;i<n;++i)len+=a[i];
    int b[2*len+1],c[2*len+1];
    b[len]=1;
    for(i=0;i<n;++i)
    {
        for(j=0;j<2*len+1;++j)
        {
            if(b[j]&&c[j]==0)
            {
                b[j-a[i]]=1;
                b[j+a[i]]=1;
                c[j-a[i]]=1;
                c[j+a[i]]=1;
            }
        }
        memset(c,0,8*len+4);
    }
    for(i=len+1;i<2*len+1;++i)printf("%d",b[i]);
    return 0;
}
#include<stdio.h>
#include<string.h>
#include <math.h>
int conversion(int x,int k,int f[1000])
{
    int n=abs(x),p=0;
    char out[1000],yu;
    int i=0;
    while(n>0)
    {
        out[i++]=n%k;
        n/=k;
    }
    for(int j=i-1;j>=0;j--)
    {

           f[p]=out[j];
           p++;
    }

}
void main()
{

    int x,i=0,n,z,k;
    scanf("%d",&n);
    int a[1000];
    int y[1000];
    for(i=0;i<n;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d",&x);
        conversion(x,2,y);
        int z;
        z=sizeof(y)/sizeof(int);
        int sum[100],o=0;
        int max;
        for(k=0;k<z;k++)
        {
            if(y[k+1]!=y[k])
            {
                sum[o]++;
            }
            if(y[k+1]=y[k]&&y[k+2]!=y[k+1])
            {
                o++;
            }
        }
        int p;
        for(int p=0;p<o;p++)
        {
            if(sum[p]>max)
            {
                max=sum[p];
            }
        }
        printf("%d",max);
        if(i!=n-1) printf("\n");


    }

}

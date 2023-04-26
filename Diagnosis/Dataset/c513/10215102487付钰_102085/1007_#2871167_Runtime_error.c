#include<stdio.h>
#include<string.h>
long long int* conversion(int x,int k)
{
    int n=abs(x),p=0;
    char out[1000],yu;
    int i=0;
    long long int f[1000];
    while(n>0)
    {
        out[i++]=n%k;
        n/=k;
    }
    for(int j=i-1;j>=0;j--)
    {
           yu=(char)('0'+out[j]);
           f[p]=atoi(yu);
           p++;
    }
    return f;
}
void main()
{

    int x,i=0,n,z,k;
    scanf("%d",&n);
    int a[1000];
    long long int* y;
    for(i=0;i<n;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d",&x);
        y=conversion(x,2);
        z=strlen(y);
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
            if(sum[p]>sum[p+1])
            {
                max=sum[p];
            }
        }
        printf("%d",max);
        if(i!=n-1) printf("\n");


    }

}

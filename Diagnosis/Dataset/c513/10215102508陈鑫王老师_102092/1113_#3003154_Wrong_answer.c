#include<stdio.h>
#include<stdlib.h>
int main()
{
    int k,n;
    scanf("%d %d",&k,&n);
    int a[100]={0};
    for(int i=0;i<n;i++)
    {
        if(i==0)a[i]=0;
        else if(i==1)a[i]=1;
        else
        {
            if(i<k)
            {
                for(int j=i-1;j>=0;j--)
                {
                    a[i]+=a[j];
                }
            }
            else
            {
                for(int j=i-1;j>=i-k;j--)
                    a[i]+=a[j];
            }
        }

    }
    printf("%d",a[n-1]);
    return 0;
}

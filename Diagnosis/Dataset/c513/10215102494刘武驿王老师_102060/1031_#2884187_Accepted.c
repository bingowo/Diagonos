#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[2000],b[2000];
    for(int i=0;i<n;i++)
    {
        int len;
        scanf("%d",&len);
        int tmplen=len;
        for(int x=0;x<len;x++) scanf("%d",&a[x]);
        for(int x=0;x<len;x++) scanf("%d",&b[x]);
        long long int res=0;
        int max,min,x,maxnu,minnu;
        while(tmplen)
        {
            for(x=0;x<len;x++)
            {
                if(a[x]!=10001)
                {
                max=a[x];
                maxnu=x;
                }
            }
            for(x=0;x<len;x++)
            {
                if(b[x]!=10001)
                {
                    min=b[x];
                    minnu=x;
                }
            }
            for(x=0;x<len;x++) if(a[x]!=10001&&a[x]>max)
            {
                max=a[x];
                maxnu=x;
            }
            a[maxnu]=10001;
            for(x=0;x<len;x++) if(b[x]!=10001&&b[x]<min)
            {
                min=b[x];
                minnu=x;
            }
            b[minnu]=10001;
            res+=max*min;
            tmplen--;
        }
        printf("case #%d:\n%lld\n",i,res);
    }
}

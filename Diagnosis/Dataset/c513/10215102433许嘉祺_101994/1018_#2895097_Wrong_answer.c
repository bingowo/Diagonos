#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char s[170];
    char a[200],b[200];
    int c[27]= {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int d[100];//存放位上的数
    int k=0;
    scanf("%s",s);
    int t=0;
    int n=1;
    for (int i=0; i<strlen(s); i++)
    {
        if (s[i]!=',') t=t*10+s[i]-'0';
        else
        {
            d[n]=t;
            n++;
            t=0;
        }
    }
    d[n]=t;
    memset(b,0,sizeof(b));
    for (int i=n; i>=1; i--)
    {
        int j=0;
        while (d[n-i+1]>0)
        {
            b[j]=b[j]+d[n-i+1]%10;
            d[n-i+1]=d[n-i+1]/10;
            j++;
        }
        if (k<j-1) k=j;
        if (c[i-1]<10)
            for (int l=0; l<k+1; l++)
            {
                b[l]=b[l]*c[i-1];

            }
        else
        {
            k=k+1;
            for (int l=k; l>=1; l--)
            {
                b[l]=b[l]*(c[i-1]%10)+b[l-1]*(c[i-1]/10);

            }
            b[0]=b[0]*(c[i-1]%10);
        }
        int l=0;
        while (l<=k||b[l+1]>0)
            {
                if (b[l]>=10)
                {
                    b[l+1]=b[l+1]+b[l]/10;
                    b[l]=b[l]%10;
                }
                l++;
            }
        if(l>k&&b[l]>0) k=l;

    }
    for (int i=k;i>=0;i--)
            printf("%d",b[i]);
    return 0;
}
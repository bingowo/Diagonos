#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    char s[100];
    int T,i=0,j=0,t=0;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int l=0;
        int a[20][8]={0};
        int b[40][6]={0};
        int c[1000]={0};
        int d[40][8]={0};
        scanf("%s",s);
        l=strlen(s);
        ///进制转化
        for(j=0;j<l;j++)
        {
            int k=0,d=0,w=0,q=0;
            q=s[j];
            while(q!=0)
            {
                a[j][k]=q%2;
                q/=2;
                k++;
            }
            for(k=0;k<4;k++)
            {
                w=a[j][k];
                a[j][k]=a[j][7-k];
                a[j][7-k]=w;
            }
        }
        int h=0,u=0,r=0;
        ///转换成每个数组六个
        for(j=0;j<l;j++)
        {
            for(u=0,r=a[j][0];r<a[j][7];r++,u++)
                c[u]=a[j][r];
        }
        if(l%3==0) h=0;
        else
        {
            h=l%3;
            h=h+1;
            for(;u<8*h;u++)
                c[u]=0;
        }



    }
}

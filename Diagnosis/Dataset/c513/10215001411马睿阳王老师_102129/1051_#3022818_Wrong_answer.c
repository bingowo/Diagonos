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
            for(r=a[j][0];r<=7;r++,u++)
                {c[u]=a[j][r];}
        }
        u=u-1;
        int x=0;
        if(l%3==0) h=0;
        else
        {
            h=u/6;
            h=h+1;
            x=u+1;
            for(u=x;u<6*h;u++)
                c[u]=0;
        }
        int y=0,z=0,f=0;
        f=u;
        u=0;
        while(u<f)
        {
            for(x=0;x<6;x++,u++)
           {
            b[z][x]=c[u];
           }
           z=z+1;
        }
        for(x=0;x<z;x++)
        {
            d[x][0]=0;
            d[x][1]=0;
            for(y=0;y<8;y++)
            {
               d[x][y+2]=b[x][y];
            }
        }
    }
}

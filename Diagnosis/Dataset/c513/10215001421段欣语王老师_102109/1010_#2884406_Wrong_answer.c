#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[1000],a[1000];
    scanf("%s",s);
    printf("0001");
    int len=strlen(s);
    int d[10]={0};
    int m=-1;
    while(len!=0&&m<=10)
    {
        d[++m]=len%2;
        len/=2;
    }
    for(int l=9;l>=0;l--)
        printf("%d",d[l]);
    if(len%3==0)
    {
        for(int i=0;i+3<len;i+=3)
        {
            if(s[i+1]&&s[i+2])
          {
            a[i]=s[i];
            a[i+1]=s[i+1];
            a[i+2]=s[i+2];
            int c[10]={0};
            int j=-1,num=atoi(a);
            while(num!=0&&j<=10)
            {
                c[++j]=num%2;
                num/=2;
             }
             for(int k=9;k>=0;k--)
                 printf("%d",c[k]);
          }
        }
    }
    if(len%3==1)
    {
        for(int i=0;i+1<len;i+=3)
    {
        while(s[i+1]&&s[i+2])
        {
            a[i]=s[i];
            a[i+1]=s[i+1];
            a[i+2]=s[i+2];
            int c[10]={0};
            int j=-1,num=atoi(a);
            while(num!=0&&j<=10)
            {
                c[++j]=num%2;
                num/=2;
             }
             for(int k=9;k>=0;k--)
                 printf("%d",c[k]);
        }
        }
        int c[4]={0};
            int j=-1,num=atoi(s[len]);
            while(num!=0&&j<=4)
            {
                c[++j]=num%2;
                num/=2;
             }
             for(int k=3;k>=0;k--)
                 printf("%d",c[k]);
    }
    if(len%3==2)
    {
        for(int i=0;i+2<len;i+=3)
    {
        while(s[i+1]&&s[i+2])
        {
            a[i]=s[i];
            a[i+1]=s[i+1];
            a[i+2]=s[i+2];
            int c[10]={0};
            int j=-1,num=atoi(a);
            while(num!=0&&j<=10)
            {
                c[++j]=num%2;
                num/=2;
             }
             for(int k=9;k>=0;k--)
                 printf("%d",c[k]);
        }
    }
            int c[7]={0};
            char F[100];
            F[0]=s[len-2];
            F[1]=s[len-1];
            int j=-1,num=atoi(F);
            while(num!=0&&j<=7)
            {
                c[++j]=num%2;
                num/=2;
             }
             for(int k=6;k>=0;k--)
                 printf("%d",c[k]);
    }
    return 0;
}

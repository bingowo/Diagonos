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
    for(int i=0;s[i];i+=3)
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
        if(s[i+2]=='\0'&&s[i+1])
        {
            a[i]=s[i];
            a[i+1]=s[i+1];
            int c[7]={0};
            int j=-1,num=atoi(a);
            while(num!=0&&j<=7)
            {
                c[++j]=num%2;
                num/=2;
             }
             for(int k=6;k>=0;k--)
                 printf("%d",c[k]);
        }
        if(s[i+1]=='\0'&&s[i+2]=='\0')
        {
            if(s[i+2]=='\0'&&s[i+1])
           {
            a[i]=s[i];
            a[i+1]=s[i+1];
            int c[7]={0};
            int j=-1,num=atoi(a);
            while(num!=0&&j<=7)
            {
                c[++j]=num%2;
                num/=2;
             }
             for(int k=6;k>=0;k--)
                 printf("%d",c[k]);
            }
        }
    }
    return 0;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    char c[64];
    c[63]='/';
    c[62]='+';
    for (int i=0; i<26; i++)
    {
        c[i]='A'+i;
        c[i+26]='a'+i;
    }
    for (int i=0; i<10; i++) c[52+i]='0'+i;
    for (int i=0; i<t; i++)
    {
        int count=0;
        char s[200];
        scanf("%s",s);
        int len=0;
        int a[6];
        printf("case #%d:\n",i);
        memset(a,0,sizeof(a));
        for (int j=0; j<strlen(s); j++)
            for (int k=7; k>=0; k--)
            {
                a[len++]=(s[j]>>k)&1;
                if (len==6)
                {
                    int sum=0;
                    for (int l=0; l<6; l++)
                        sum=sum*2+a[l];
                        count++;
                    printf("%c",c[sum]);
                    len=0;

                }
            }

        if (len!=0)
        {   int sum=0;
            for (int l=0; l<6; l++)
            if (l<len)
                sum=sum*2+a[l];
            else sum=sum*2;
            count++;
            printf("%c",c[sum]);
        }
        while (count%4!=0) {printf("=");count++;}
        printf("\n");
    }
    return 0;
}
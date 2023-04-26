#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        char c[5],s[101];
        int i,a[4]={0};
        gets(s);
        for(i=0;i<strlen(s);i+=4)
        {
            if(s[i]!='!')
                c[0]=s[i];
            else
                a[0]++;
        }
        for(i=1;i<strlen(s);i+=4)
        {
            if(s[i]!='!')
                c[1]=s[i];
            else
                a[1]++;
        }
        for(i=2;i<strlen(s);i+=4)
        {
            if(s[i]!='!')
                c[2]=s[i];
            else
                a[2]++;
        }
        for(i=3;i<strlen(s);i+=4)
        {
            if(s[i]!='!')
                c[3]=s[i];
            else
                a[3]++;
        }
        c[4]='\0';
        for(i=0;i<4;i++)
        {
            if(c[i]=='R')
            {
                printf("%d ",a[i]);
                break;
            }
        }
        if(i==4)
            printf("1 ");
        for(i=0;i<4;i++)
        {
            if(c[i]=='B')
            {
                printf("%d ",a[i]);
                break;
            }
        }
        if(i==4)
            printf("1 ");
        for(i=0;i<4;i++)
        {
            if(c[i]=='Y')
            {
                printf("%d ",a[i]);
                break;
            }
        }
        if(i==4)
            printf("1 ");
        for(i=0;i<4;i++)
        {
            if(c[i]=='G')
            {
                printf("%d\n",a[i]);
                break;
            }
        }
        if(i==4)
            printf("1\n");
    }
    return 0;
}

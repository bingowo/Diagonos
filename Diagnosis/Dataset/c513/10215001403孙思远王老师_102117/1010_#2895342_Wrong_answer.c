#include <stdio.h>
#include <stdlib.h>
#include <string.h>


long long int tentwo(int i)
{
    long long int a=0,j=1;
    while(i)
    {
        a=i%2*j+a;
        i/=2;
        j*=10;
    }
    return a;
}

int main()
{
    int s[501];
    int i;
    long long int a;
    gets(s);
    i=strlen(s);
    printf("0001");
    a=tentwo(i);
    printf("%010d",a);
    int ss[4];
    int m=0;
    if(i%3==0)
    {while(m<i)
        {
            int j;
            for(j=0;j<3;j++,m++)
            {
                ss[j]=s[m];
            }
            a=tentwo(atoi(ss));
            printf("%010lld",a);
        }
    }
    else if(i%3==1)
    {while(m<i-1&&i>3)
        {
            int j;
            for(j=0;j<3;j++,m++)
            {
                ss[j]=s[m];
            }
            a=tentwo(atoi(ss));
            printf("%010lld",a);
        }
        int ss1[2];
        ss1[0]=s[i-1];
        a=tentwo(atoi(ss1));
        printf("%04lld",a);
    }
    else if(i%3==2)
    {while(m<i-2&&i>3)
        {
            int j;
            for(j=0;j<3;j++)
            {
                ss[j]=s[m];
                m++;
            }
            a=tentwo(atoi(ss));
            printf("%010lld",a);
        }
        int ss1[2];
        ss1[0]=s[i-2];
        ss1[1]=s[i-1];
        a=tentwo(atoi(ss1));
        printf("%07lld",a);
    }

    return 0;
}

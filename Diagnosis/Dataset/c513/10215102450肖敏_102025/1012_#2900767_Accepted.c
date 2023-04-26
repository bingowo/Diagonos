#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    long long int a = 0,b = 0,qr=1,qi=1,sum = 0;
    int r = 0,flag = 0,m = 0,n,i;
    char s[100],p[300];
    memset(p,300,0);
    scanf("%s",s);
    int len = strlen(s);

    for(i = 0;i <len;i ++)
    {
        if(isdigit(s[i]))
        {
            sum = sum * 10 + s[i] - '0';
            continue;
        }
        else if(s[i] == 'i')
        {
            if(flag)
            {
                if(sum == 0)
                    sum = 1;
                b = -sum;
                flag = 0;
                sum = 0;
            }
            else{
                if(sum == 0)
                    sum = 1;
                b = sum;
                sum = 0;
            }
        }
        else if(s[i] == '+')
        {
            if(flag)
            {
                a = -sum;
                sum = 0;
                flag = 0;
            }
            else
            {
                a = sum;
                sum = 0;
            }
        }
        else
        {
            if(i != 0)
            {
                if(flag)
                {
                    a = -sum;
                    sum= 0;
                }
                else
                {
                    a = sum;
                    sum = 0;
                }
            }
            flag = 1;
        }
    }
    if(s[len - 1] != 'i')
    {
        if(flag)
            a = -sum;
        else a = sum;
    }

    while(qr != 0 || qi != 0)
    {
        if((a+b)%2 == 0)
            r = 0;
        else
            r = 1;
        p[m ++ ] = r;
        qr = -(a-b-r)/2;
        qi = -(a+b-r)/2;
        a = qr;
        b = qi;
    }

    for(n = m-1;n >= 0;n --)
        printf("%d",p[n]);
    printf("\n");
    return 0;

}

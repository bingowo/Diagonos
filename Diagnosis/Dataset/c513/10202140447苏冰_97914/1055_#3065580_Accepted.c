#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char s[1000001];
int main()
{
    scanf("%s",s);
    int a[200]={0};
    char* p=s;
    char* q=s;
    char* r=s;
    int len=0,max=0,flag=0;
    while(*p!='\0')
    {
        if(a[*p]==0)
        {
            a[*p]=1;
            p++;
            len++;
        }
        else
        {
            flag=1;
            memset(a,0,sizeof(a));
            if(len>max)
            {
                max=len;
                q=p-max;
            }
            r++;
            p=r;
            len=0;
        }
    }
    if(flag==0) printf("%s\n",s);
    else
    {
        for(int i=0;i<max;i++)
        {
            printf("%c",*q);
            q++;
        }
    }
    return 0;
}



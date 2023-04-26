#define _CRT_SECURE_NO_WARNINGS 1
/* strchr example */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

char s[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K'};

int mod(char*n,int a,int b)
{
    if(a<0)
    {
        int m = a%b;
        int p =a/b;
        if(m<0)
        {
            p+=1;
            m = m-b;
        }
        *n = s[m];
        return p;
    }
    else
    {
    int p = a/b;
    int m= a%b;
    *n = s[m];
    return p;
    }

}

int main()
{
    char res[300] = {0};
    int a,b;
    scanf("%d%d",&a,&b);
    char *p = res;
    while(a!=0)
    {
        a = mod(p,a,b);
        p++;
    }
    char *p1=res;
    if(p==res)printf("0");
     p--;
    while(p>=p1)
    {
        printf("%c",*p);
        p--;
    }
   return 0;
}

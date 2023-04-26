#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 90

void reverse(char* s)
{
    int i,j; char tmp;
    for (i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
    }
}

int main()
{
    int T; long n,m,a,b;
    scanf("%d",&T);
    char s1[MAX]={0}, s2[MAX]={0}, s[MAX]={0};
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s);
        char* pos1=strstr(s,s1);
        char* pos2=strstr(s,s2);
        if (pos1)
        {
            n=pos1-s+strlen(s1);
//            printf("%ld\n",n);
        }
        else
        {
            printf("0\n");
            break;
        }
        if (pos2)
        {
            m=pos2-s+strlen(s2);
//            printf("%ld\n",m);
        }
        else
        {
            printf("0\n");
            break;
        }
        reverse(s);
        reverse(s1);
        reverse(s2);
        char* pos3=strstr(s,s1);
        char* pos4=strstr(s,s2);
        if (pos3)
        {
            a=pos3-s;
            a=strlen(s)-a-strlen(s1);
//            printf("%ld\n",a);
        }
        else
        {
            printf("0\n");
            break;
        }
        if (pos4)
        {
            b=pos4-s;
            b=strlen(s)-b-strlen(s2);
//            printf("%ld\n",b);
        }
        else
        {
            printf("0\n");
            break;
        }
        printf("%ld\n",(b-n));
    }
    return 0;
}

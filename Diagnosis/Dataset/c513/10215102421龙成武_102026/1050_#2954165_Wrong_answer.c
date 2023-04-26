#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isfor(char a);
int compar(const void* p1, const void* p2);
int main()
{
    int i, j, k,x, T,res,temp1,temp2;
    char s[81],s1[81],s2[81],*p1,*p2;
    scanf("%d", &T);
    for(x=0;x<T;x++)
    {
        scanf("%s",s1);scanf("%s",s2);scanf("%s",s);
        res=0;
        p1=strstr(s,s1);
        p2=strstr(s,s2);
        if(p1==NULL||p2==NULL);
        else
        {
            for(i=1;i<strlen(s);i++)
            {
                p2=strstr(s+i,s2)==NULL? p2:strstr(s+i,s2);
            }
            temp1=(p2-1)-(p1+strlen(s1)-1);
            for(i=1;i<strlen(s);i++)
            {
                p1=strstr(s+i,s1)==NULL? p1:strstr(s+i,s1);
            }
            temp2=(p1-1)-(p2+strlen(s2)-1);
            res=temp1>temp2? temp1:temp2;
        }
        printf("case #%d:\n",x);
        printf("%d\n",res);
    }

    return 0;
}


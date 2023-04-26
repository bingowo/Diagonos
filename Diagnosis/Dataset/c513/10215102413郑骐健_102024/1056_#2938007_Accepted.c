#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char s[5200];
int cmp(const void *p1,const void*p2)
{
    char*p_1 = *(char**)p1;
    char*p_2 = *(char**)p2;
    if(strlen(p_1)==strlen(p_2))return -1;
    else return strlen(p_2)-strlen(p_1);
}
int stcmp(char *s,char *p,int p1)//比较字符是否相等
{
    int n = strlen(p);
    for(int i =0;i<n;i++)
    {
        if(s[p1+i]!=p[i])return 0;
    }
    return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    char **p1 = (char **)malloc(sizeof(char*)*5000);
    for(int i =0;i<n;i++)
    {
        p1[i] = (char*)malloc(sizeof(char)*17);
        scanf("%s",p1[i]);
    }
    scanf("%s",s);
    qsort(p1,n,sizeof(char*),cmp);
    int p_s = 0;
    int p_1 = 0;
    while(p_s!= strlen(s))
    {
        if(stcmp(s,p1[p_1],p_s)&&strlen(s)-p_s >=strlen(p1[p_1]))
        {
            p_s+=strlen(p1[p_1]);
            if(p_s==strlen(s))printf("%s\n",p1[p_1]);
            else printf("%s ",p1[p_1]);

            p_1 =0;
        }
        else
        {
         p_1+=1;
         if(p_1 ==n)
         {
             if(p_s==strlen(s)-1)
             {
                 printf("%c\n",s[p_s]);
                break;
             }
             else
             {
                 printf("%c ",s[p_s]);
                 p_1=0;
             }
               p_s+=1;
         }
        }
    }

     for(int i =0;i<n;i++)
    {
        free(p1[i]);
    }
    free(p1);
    return 0;
}


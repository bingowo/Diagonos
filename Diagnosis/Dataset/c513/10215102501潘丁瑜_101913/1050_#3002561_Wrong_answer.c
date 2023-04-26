#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int FindFromLeft(char*s,char*s1)
{
    char *p=strstr(s,s1);
    return p==0?-1:p-s;
}

int FindFromRight(char *s,char *s1)
{
    char *p=s,*p1=0;
    while((p1=strstr(p,s1))!=0) p=p1+1;
    return p-s-1;
}

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        char s1[81]={0};
        char s2[81]={0};
        char s[81]={0};
        int max=0,x,y;
        scanf("%s%s%s",s1,s2,s);
        x=FindFromLeft(s,s1);
        y=FindFromRight(s,s2);
        if(x!=-1 && y!=-1)
        {
            max= (max>(y-x-strlen(s1))?max:(y-x-strlen(s1)));
            x=FindFromLeft(s,s2);
            y=FindFromRight(s,s1);
            max =(max>(y-x-strlen(s2))?max:(y-x-strlen(s2)));
        }
        printf("case #%d:\n",i);
        printf("%d\n",max);
    }
    return 0;
}

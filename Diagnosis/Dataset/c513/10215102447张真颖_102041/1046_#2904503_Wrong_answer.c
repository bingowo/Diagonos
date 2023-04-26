#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    char s1[]="the",s2[]="a",s3[]="an",s4[]="of",s5[]="for",s6[]="and";
    for(int i=0;i<T;i++)
    {
        int sum=0;
        char ch=0;
        do
        {
            char s[101]="";
            scanf("%s",s);
            for(int i=0;i<strlen(s);i++)
            {
                if(s[i]<'a') s[i]+=32;
            }
            if(strcmp(s,s1)&&strcmp(s,s2)&&strcmp(s,s3)&&strcmp(s,s4)&&strcmp(s,s5)&&strcmp(s,s6)) sum+=1;
        }while((ch=getchar())!='\n');
        printf("case #:%d\n%d\n",i,sum);
    }

    return 0;
}
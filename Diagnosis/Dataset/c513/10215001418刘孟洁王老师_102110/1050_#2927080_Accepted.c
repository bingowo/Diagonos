#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main()
{
    int n,i,j,k,m,x,r1,r2;
    char s1[87],s2[87],s[87];
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%s%s%s",s1,s2,s);
         if(strcmp(s1,s2) == 0&&strcmp(s1,s) == 0){printf("case #%d:\n0\n",i);continue;}//若三者一模一样；
        for(j = 0;j < strlen(s); j++)
        {
            for(k = 0,m = j; k < strlen(s1); k++,m++)
            {
                if(s1[k] != s[m])break;
            }
            if(k == strlen(s1))break;
        }
        r1 = j+strlen(s1);
        for(x = strlen(s)-1; x >= 0; x--)
        {
            for(k = strlen(s2)-1,m = x; k >= 0; m--,k--)
            {
                if(s2[k] != s[m])break;
            }
            if(k == -1)break;
        }
        r2 = x-strlen(s2);
        if(r2 < r1)//若出现s1在s2后面的情况，就将s1、s2调换一下即可；
        {
             for(j = 0;j < strlen(s); j++)
        {
            for(k = 0,m = j; k < strlen(s2); k++,m++)
            {
                if(s2[k] != s[m])break;
            }
            if(k == strlen(s2))break;
        }
        r1 = j+strlen(s2);
        for(x = strlen(s)-1; x >= 0; x--)
        {
            for(k = strlen(s1)-1,m = x; k >= 0; m--,k--)
            {
                if(s1[k] != s[m])break;
            }
            if(k == -1)break;
        }
        r2 = x-strlen(s1);
        }
        printf("case #%d:\n",i);
        if((j == strlen(s))||(x == -1))printf("0\n");
        else printf("%d\n",r2-r1+1);
        }
        return 0;
}

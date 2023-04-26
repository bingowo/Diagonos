#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int cmp(void*a,void*b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int n;
    char str[200];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char alp[200];
        gets(str);
        int num=0;
        for(int j=0;j<strlen(str);j++)
        {
            if(isalpha(str[j])) alp[num++]=str[j];
        }
        qsort(alp,num,sizeof(char),cmp);
        alp[num]='\0';
        num=0;
        printf("case #%d:\n",i);
        for(int j=0;j<strlen(str);j++)
        {
            if(isalpha(str[j])) print("%c",alp[num++]);
            else printf("%c",str[j]);
        }
        printf("\n");
    }
}
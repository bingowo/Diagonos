#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* x,const void* y)
{
    int a=*(int*)x,b=*(int*)y;
    return b-a;
}
int main()
{
    char s[51];
    scanf("%s",s);
    int len=strlen(s);
    int l[50];
    int flag=0;
    for(int i=0; i<len; i++)
    {
        int j=0;
        for(j=0; j<len; j++)
        {
            while(s[i]!=s[i+j+1]) l[flag]++;
        }
        if(s[i]==s[i+j+1]&&j!=0)
        {
            flag++;
            continue;
        }

    }
    qsort(l,flag,sizeof(int),cmp);
    printf("%d",l[0]);
    return 0;
}

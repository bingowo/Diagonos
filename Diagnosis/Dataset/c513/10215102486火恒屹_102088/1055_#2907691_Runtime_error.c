#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    return strcmp((char *)a,(char *)b);
}

int mystrchr(char *a,char b)
{
    for(int i=0;i<strlen(a);i++)
    {
        if(b==a[i])
            return 1;
    }
    return -1;
}
void mystrcpy(char*a,char*b)
{
    for(int i=0;i<strlen(a);i++)
        a[i]=0;
    for(int i=0;i<strlen(b);i++)
        a[i]=b[i];
}

int main()
{
    char s[1000001]={'\0'};
    scanf("%s",&s);
    char longest[1000001]={'\0'};
    char wait[1000001]={'\0'};
    char zero[2]={'\0'};
    for(int i=0;i<strlen(s);i++)
    {
        mystrcpy(wait,zero);
        int j=1;
        wait[0]=s[i];//printf("1%s\n",wait);
        while(mystrchr(wait,s[i+j])==-1)
        {
            wait[j]=s[i+j];
            j++;
        }
        //printf("2%s\n",wait);
        if(strlen(wait)>strlen(longest))
            mystrcpy(longest,wait);
        //printf("3%s\n",longest);
    }
    printf("%s",longest);
    return 0;
}

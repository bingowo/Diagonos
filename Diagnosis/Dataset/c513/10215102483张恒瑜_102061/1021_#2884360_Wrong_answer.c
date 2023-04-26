#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char sort[30]={'\0'};

int find(char a)
{
    int i;
    if(a>='a' && a<='z') a-=('a'-'A');
    for(i=0;i<30;i++)
    {
        if(a==sort[i]) return i;
    }
}
int cmp(const void* a, const void* b)
{
    char *a0=(char*)a;char *b0=(char*)b;
    int i=0;
    while(i<strlen(a0) && i<strlen(b0))
    {
        if(find(a0[i])!=find(b0[i])) return find(a0[i])-find(b0[i]);
        else i++;
    }
    return strlen(b0)-strlen(a0);
}

int main()
{
    
    while (scanf("%s",sort)!=EOF)
    {
        getchar();
        char str[30][30];
        int i=0,j=0,num=0;
        char c;
        while (c=getchar())
        {
            if(c=='\n') break;
            else if (c==' ') {i++;j=0;}
            else {str[i][j]=c;j++;}
        }
        num=i+1;

        qsort(str,num,sizeof(str[0]),cmp);
        for(i=0;i<num;i++)
        {
            i==num-1 ? printf("%s\n",str[i]) : printf("%s ",str[i]);
        }
    }
    return 0;
}
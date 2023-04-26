#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SPACE 1
#define CH 2

int cmp(const void* a, const void* b)
{
    int a0=*(char*)a,b0=*(char*)b;
    if(a0<'A' || a0>'Z') a0=1000;
    if(b0<'A' || b0>'Z') b0=1000;
    return a0-b0;
}

int main()
{
    int T,t=0;
    scanf("%d",&T);
    while (T--)
    {
        getchar();
        char input[220]={'\0'},cpy[220]={'\0'};
        scanf("%[^\n]",&input);
        strcpy(cpy,input);
        int index[220]={0},i,j;
        for(i=0;i<strlen(input);i++)
        {
            if(input[i]==' ') index[i]=SPACE;
            else if(input[i]>='A' && input[i]<='Z') index[i]=CH;
            else index[i]=0;
        }
        qsort(input,strlen(input),sizeof(input[0]),cmp);
        printf("case #%d:\n",t);
        for(i=0,j=0;i<strlen(input);i++)
        {
            if(index[i]==SPACE) printf(" ");
            else if(index[i]==0) printf("%c",cpy[i]);
            else printf("%c",input[j++]);
        }
        printf("\n");
        t++;
    }
    return 0;
}
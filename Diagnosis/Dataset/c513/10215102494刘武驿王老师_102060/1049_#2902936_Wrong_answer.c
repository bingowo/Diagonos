#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int cmp(void *a,void *b)
{
    return strcmp((char *)a,(char *)b);
}
int main()
{
    int n;
    scanf("%d",&n);
    char w=getchar();
    for(int i=0;i<n;i++)
    {
        char words[501][501];
        char sent[1000];
        gets(sent);
        int j=0,q=0,m=0;
        for(j=0;j<strlen(sent);j++)
        {
            if(sent[j]=='!')
            {
                words[m][q]='\0';
                m++;
                q=0;
                continue;
            }
            if((sent[j]==' '||sent[j]=='.')||(sent[j]=='?'||sent[j]==','))
            {
                words[m][q]='\0';
                m++;
                q=0;
                continue;
            }
            words[m][q++]=sent[j];
        }
        if(isalpha(sent[j-1]))
        {
            printf("yes\n");
            words[m][q]='\0';
            m++;
        }
        qsort(words,m,sizeof(words[0]),cmp);
        printf("case #%d:\n",i);
        for(int x=0;x<m-1;x++)
        if(strcmp(words[x],words[x+1])!=0)
        printf("%s ",words[x]);
        printf("%s\n",words[m-1]);
    }
}
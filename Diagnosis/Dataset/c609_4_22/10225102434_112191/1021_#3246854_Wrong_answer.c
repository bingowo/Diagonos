#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char*a;
    char*c;
}STR;
void Turn(char*p,char s[27])
{
    int i,j;
      for(j = 0;j<strlen(p);j++)
    {
       for(i = 0;i<26;i++)
        {
            if(p[j]==s[i]||p[j]==s[i]+'a'-'A')p[j] = i+'0';
        }
    }
    return;
}
int cmp(const void*a,const void*b)
{
    STR* p1 = (STR*)a;
    STR*p2 = (STR*)b;
   return strcmp(p1->c,p2->c);
}
int main()
{
    char s[27];
    int i , j;
    while(scanf("%s",s)!=EOF)
    {
        STR *b= (STR*)malloc(sizeof(STR)*102);
        for(i = 0;getchar()!='\n'||i ==0;i++)
        {
            b[i].a = (char*)malloc(sizeof(char)*22);
            b[i].c = (char*)malloc(sizeof(char)*22);
             scanf("%s",b[i].a);
             strcpy(b[i].c,b[i].a);
        }
       for(j = 0;j<i;j++)Turn(b[j].c,s);

        qsort(b,i,sizeof(b[0]),cmp);

        for(j = 0;j<i;j++)
            printf("%s ",b[j].a);
        printf("%c",'\n');
        for(j = 0;j<i;j++)

        {
            free(b[j].a);
            free(b[j].c);
        }
        free(b);
    }
    return 0;
}

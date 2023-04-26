#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char com[100];
void findcore(char* s, char* core);
int compar(const void* p1, const void* p2);
void myPrint(char *x,int len,int l,int r)       //len：本次输出的长度，l：本次输出从第l个元素开始，r：本次输出到第r-1个元素终止
{
    if(l==r)
        return;
    for(;l!=r;l++)
    {
        com[len]=x[l];
        com[len+1]=0;
        puts(com);
        myPrint(x,len+1,l+1,r);
    }
}
int main()
{
    int T, i;
    char s[17], core[17];
    scanf("%d", &T);
    for (i = 0;i < T;i++)
    {
        scanf("%s", s);
        memset(core, 0, sizeof(core));
        findcore(s, core);
        qsort(core, strlen(core), sizeof(char), compar);
        printf("case #%d:\n", i);
        myPrint(core,0,0,strlen(core));
    }

    return 0;
}
void findcore(char* s, char* core)
{
    int i, j;j = 0;
    for (i = 0;i < strlen(s);i++)
    {
        if (strchr(core, s[i]) == NULL)
        {
            core[j++] = s[i];
        }
    }
}
int compar(const void* p1, const void* p2)
{
    char *a = (char*)p1,  *b = (char*)p2;
    if (strcmp(a,b)<0)
        return -1;
    else
        return 1;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char com[100];
void findcore(char* s, char* core);
int compar(const void* p1, const void* p2);
void myPrint(char *x,int pos,int l,int r)           //作用：修改com第pos位的值，并输出com数组
{
    if(l==r)
        return;
    for(;l!=r;l++)
    {
        com[pos]=x[l];
        com[pos+1]=0;
        puts(com);
        myPrint(x,pos+1,l+1,r);
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

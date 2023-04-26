#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//char res[100000][17];
char** res;
int x;
void findcore(char* s, char* core);
int compar(const void* p1, const void* p2);
int compar1(const void* p1, const void* p2);
void findres(char* a,int len);
int main()
{
    int T, i,j;
    char s[17], core[17];
    scanf("%d", &T);
    res = (char**)malloc(10000 * sizeof(char*));
    for (i = 0;i < 10000;i++)
        res[i] = (char*)malloc(17*sizeof(char));
    for (i = 0;i < T;i++)
    {
        x = 0;
        scanf("%s", s);
        memset(core, 0, sizeof(core));
        findcore(s, core);
        qsort(core, strlen(core), sizeof(char), compar);
        printf("case #%d:\n", i);
        findres(core,strlen(core));
        qsort(res, x, sizeof(char*), compar1);

        puts(res[0]);
        for (j = 1;j< x;j++)
        {
            if(strcmp(res[j],res[j-1])!=0)
                puts(res[j]);
        }

    }

    for (i = 0;i < 10000;i++)
        free(res[i]);
    free(res);
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
    char a = *(char*)p1,  b = *(char*)p2;
    if (a<b)
        return -1;
    else
        return 1;
}
int compar1(const void* p1, const void* p2)
{
    char* a = *(char**)p1, * b = *(char**)p2;
    if (strcmp(a, b) < 0)
        return -1;
    else
        return 1;
}
void findres(char* a,int len)
{
    int i, j;
    char c,temp[17];
    strcpy(temp, a);
    j = 0;
    if (len == 0)
        return;
    for (i = 0;i < strlen(a);i++)
    {
        if (a[i] != '0')
            res[x][j++] = a[i];
    }
    res[x][j] = 0;
    x++;
    for (i = 0;i < strlen(a);i++)
    {
        if (temp[i] == '0')
            continue;
        c = temp[i];
        temp[i] = '0';
        findres(temp,len-1);
        temp[i] = c;
    }
}

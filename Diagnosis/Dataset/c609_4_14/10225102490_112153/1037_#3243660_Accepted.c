#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int begin;
    int end;
} String;

int cmp(String *a, String *b)
{
    int x = a->end - a->begin;
    int y = b->end - b->begin;
    if (x != y) return y-x;
    else return a->begin - b->begin;
}

int main()
{
    String *a = (String*)malloc(sizeof(String) * 1000001);
    char *t = (char*)malloc(sizeof(char) * 1000001);
    scanf("%s",t);
    //printf("%s\n",t);
    a[0].begin = 0; a[0].end = strlen(t)-1;
    int hash[128] = {0};
    int i = 0,j = 0;
    int right = 0, left = 0;
    while (right < strlen(t))
    {
        if (hash[t[right]] > 0)
        {
            i++;
            hash[t[left]] = 0;
            left++;
        }
        else
        {
            hash[t[right]] = 1;
            right++;
            a[i].begin = left;
            a[i].end = right;
        }
    }
    //printf("1\n");
    /*for (int k = 0; k < i; k++)
    {
        printf("%d %d\n",a[k].begin,a[k].end);
    }*/
    qsort(a,i,sizeof(String),cmp);
    for (int k = a[0].begin; k < a[0].end; k++)
    {
        printf("%c",t[k]);
    }
}

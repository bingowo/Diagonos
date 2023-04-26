#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct String
{
    int order;
    int length;
    char c[1000000];
} str;
int cmp(const void* x,const void* y)
{
    str* a=(str*)x;
    str* b=(str*)y;
    if(a->length!=b->length) return b->length-a->length;
    else return a->order-b->order;
}
int main()
{
    char s[1000001];
    scanf("%s",s);
    int len=strlen(s);
    str* m;
    m=(str*)malloc(sizeof(struct String)*500001);
    int j=0,i=0;
    for(int k=0; k<500001; k++) m[k].length=1;
    while(s[i]!='\0')
    {
        if(s[i]==s[i+1]) i++;
        else
        {
            m[j].order=j;
            while(s[i]!=s[i+1])
            {
                m[j].length+=1;
                if(m[j].length==2)
                {
                    strcpy(m[j].c,s[i]);
                    strcpy(m[j].c,s[i+1]);
                }
                else strcpy(m[j].c,s[i+1]);
                i++;
                if(s[i]==s[i+1])
                {
                    j++;
                    break;
                }
            }
        }
    }
        qsort(m,j,sizeof(struct String),cmp);
        printf("%s",m[0].c);
        free(m);
        return 0;
    }

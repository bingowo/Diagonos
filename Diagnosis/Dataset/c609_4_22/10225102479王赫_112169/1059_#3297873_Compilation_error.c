#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int len_integer;
    char integer[101];
    char decimal[101];
} num_positive;
typedef struct
{
    int len_integer;
    char integer[101];
    char decimal[101];
} num_passive;
int cmp_postive(const void* _a,const void* _b)
{
    num_positive *a=(num_positive*)_a;
    num_positive *b=(num_positive*)_b;
    if(a->len_integer!=b->len_integer) return a->len_integer-b->len_integer;
    else
    {
        int i=0;
        for(i=0; i<strlen(a->decimal)&&i<strlen(b->decimal); i++)
        {
            if(atoi(a->decimal[i])!=atoi(b->decimal[i])) return atoi(a->decimal[i])-atoi(b->decimal[i]);
        }
        if(i==strlen(a->decimal)-1||i==strlen(b->decimal)-1)
        {
            if(i=strlen(a->decimal)-1) return -1;
            else return 1;
        }
    }

}
int cmp_passive(const void* _a,const void* _b)
{
    num_passive *a=(num_passive*)_a;
    num_passive *b=(num_passive*)_b;
    if(a->len_integer!=b->len_integer) return b->len_integer-a->len_integer;
    else
    {
        for(int i=0; i<strlen(a->decimal)&&i<strlen(b->decimal); i++)
        {
            if(atoi(a->decimal[i])!=atoi(b->decimal[i])) return atoi(b->decimal[i])-atoi(a->decimal[i]);
        }
        if(i==strlen(a->decimal)-1||i==strlen(b->decimal)-1)
        {
            if(i=strlen(a->decimal)-1) return 1;
            else return -1;
        }
    }

}
int main()
{
    int n;
    scanf("%d",&n);
    struct num_positive m[n]= {0,{0},{0}};
    struct num_passive p[n]={0,{0},{0}};
    int len_po=0,len_pa=0;
    for(int i=0; i<n; i++)
    {
        char s[101];
        scanf("%s",s);
        int j=1,k=0;
        if(s[0]='-')
        {
            while(s[j]!='.')
            {
                m.integer[k++]=s[j];
                j++;
            }
            m.len_integer=k;
            j--;
            k=0;
            while(s[j]!='\0')
            {
                m.decimal[k++]=s[j];
                j++;
            }
            len_po=k;
        }
        else
        {
            j=0;
            while(s[j]!='.')
            {
                p.integer[k++]=s[j];
                j++;
            }
            p.len_integer=k;
            j--;
            k=0;
            while(s[j]!='\0')
            {
                p.decimal[k++]=s[j];
                j++;
            }
            len_pa=k;
        }
    }
    qsort(m,len_po,sizeof(p[0]),cmp_positive);
    qsort(m,len_pa,sizeof(m[0]),cmp_passive);
    for(int i=0;i<len_pa;i++)
    {
        printf("%c",p[i]);
        printf("\n");
    }
    for(int i=0;i<len_po;i++)
    {
        printf("%c",m[i]);
        printf("\n");
    }
    return 0;
}


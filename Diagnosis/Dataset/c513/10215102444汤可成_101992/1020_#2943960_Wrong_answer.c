#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file
{
    long long time;
    int size;
    char s[100];
    char ret[17];
}file;

int cmp_n(const void*pa, const void*pb)
{
    file* a = (file*)pa;
    file* b = (file*)pb;
    return strcmp(a->s, b->s);
}

int cmp_s(const void*pa, const void*pb)
{
    file* a = (file*)pa;
    file* b = (file*)pb;
    if(a->size < b->size) return -1;
    else if(a->size > b->size) return 1;
    else
    {
        return strcmp(a->s, b->s);
    }
}

int cmp_t(const void*pa, const void*pb)
{
    file* a = (file*)pa;
    file* b = (file*)pb;
    if(a->time < b->time) return -1;
    else if(a->time > b->time) return 1;
    else
    {
        return strcmp(a->s, b->s);
    }
}

int main()
{
    int n = 0;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0) break;
        else
        {
            file* f = (file*)malloc(sizeof(file)*n);
            int i = 0;
            for(i =0; i<n; i++)
            {
                int j = 0;
                long long num = 0;
                scanf("%s", f[i].ret);
                f[i].ret[10] = ' ';
                scanf("%s", &(f[i].ret[11]));
                for(j = 0; j<16; j++)
                {
                    if(j == 4 || j == 7 || j == 10 || j == 13)
                    {
                        continue;
                    }
                    else
                    {
                        num = num*10 + f[i].ret[j] - '0';
                    }
                }
                f[i].time = num;
                scanf("%d", &f[i].size);
                scanf("%s", f[i].s);
            }
            char ss[15] = {0};
            scanf("%s", ss);
            ss[4] = ' ';
            scanf("%s", &(ss[5]));
            if(strcmp(ss,"LIST /NAME") == 0) qsort(f,n,sizeof(f[0]),cmp_n);
            else if(strcmp(ss,"LIST /SIZE") == 0) qsort(f,n,sizeof(f[0]),cmp_s);
            else if(strcmp(ss,"LIST /TIME") == 0) qsort(f,n,sizeof(f[0]),cmp_t);
            for(i = 0; i<n; i++)
            {
                printf("%s", f[i].ret);
                printf("%16d ", f[i].size);
                printf("%s\n", f[i].s);
            }
            free(f);
        }
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <alg.h>

struct mail//直接开100000的char数组太大了，用指针
{
    char *name;
    char *realm;
};
//
int qcmp(const void * q1, const void *q2)
{
    struct mail * p1 = (struct mail *) q1;
    struct mail * p2 = (struct mail *) q2;
    int judge = strcmp(p1->realm,p2->realm);
    if(judge == 0)
    {
        return strcmp(p2->name,p1->name);
    }
    return judge;
}

char all[10000000] = {0};

int main() {
    int total;
    scanf("%d",&total);

    getchar();
    struct mail cap[total];
    struct mail * M = cap;
    int len = 0;

    for(int i = 0; i < total; i++)
    {
        M[i].name = all + len;
        char c = getchar();
        while(c != EOF && c != '\n')
        {
            if(c == '@')
            {
                all[len++] = '\0';
                M[i].realm = (all + len);
                c = getchar();
                continue;
            }
            all[len++] = c;
            c = getchar();
        }
        all[len++] = '\0';
    }

    qsort(M,total,sizeof(struct mail),qcmp);

    for (int i = 0; i < total; ++i) {
        printf("%s@%s\n",M[i].name,M[i].realm);
    }
    return 0;
}

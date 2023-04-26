#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int num;
    int a[100];
}node;

int cmp(const void *a,const void *b)
{
    node *pa = (node*)a;
    node *pb = (node*)b;
    int len = pa->num > pb->num ? pb->num : pa->num;
    for(int i = 0;i < len;i++)
    {
        if(pa->a[i] != pb->a[i])
            return pb->a[i] - pa->a[i];
    }
    return pb->num - pa->num;
}

int main()
{
    int n;scanf("%d",&n);
    while(n--)
    {
        int len;scanf("%d",&len);
        node *ch = (node*)malloc(len*sizeof*ch);
        for(int i = 0;i < len;i++)
        {
            int cnt = 0;
            int res;
            while(1)
            {
                scanf("%d",&res);
                if(res == -1)
                    break;
                ch[i].a[cnt++] = res;
            }
            ch[i].num = cnt;
        }
        qsort(ch,len,sizeof(ch[0]),cmp);
        for(int i = 0;i < len;i++)
        {
            for(int j = 0;j < ch[i].num;j++)
            {
                printf("%d%c",ch[i].a[j],j == ch[i].num-1 ? '\n' : ' ');
            }
        }
        free(ch);
    }

    return 0;
}
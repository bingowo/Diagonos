#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T,j;
    scanf("%d",&T);
    for(j = 0;j <T;j++)
    {
        int N,i;
        scanf("%d",&N);
        typedef struct {
        int val;
        int y;
        int d;
        char m[7];
        } RECORD;
        RECORD a[10001];
        int month2idx(char* m)
        {
            static char* month[] ={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

            for (int i=0;; i++)
              if (!strcmp(m,month[i])) return i;
        }
        for (i=0;i<N;i++)
        {
          scanf("%d.%s %d", &a[i].d, &a[i].m, &a[i].y);
          a[i].val = a[i].y*1000 + month2idx(a[i].m)*20 + a[i].d;
        }
        int cmp(const void* a,const void* b)
        {
            return ((RECORD*)a)->val - ((RECORD*)b)->val;
        }
        qsort(a, N, sizeof(RECORD), cmp);
        printf("case #%d:\n",j);
        for (i=0;i<N;i++)
            printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y);
    }
    return 0;


}

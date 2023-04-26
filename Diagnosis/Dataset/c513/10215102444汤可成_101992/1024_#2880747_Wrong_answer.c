#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    unsigned char* pa = (unsigned char*)a;
    unsigned char* pb = (unsigned char*)b;
    if((*(pa+11)+ *(pa+12)) > (*(pb+11) + *(pb+12))) return -1;
    else if((*(pa+11)+*(pa+12)) < (*(pb+11) + *(pb+12))) return 1;
    else
    {
        int i = 0;
        while(1)
        {
            if(*(pa+i) < *(pb+i)) return -1;
            else if(*(pa+i) > *(pb+i)) return 1;
            else i++;
        }
    }
}

int main()
{
    int T = 0;
    scanf("%d",&T);

    int i = 0;
    for (i = 0; i < T; i++)
    {

        int M = 0;
        int N = 0;
        int G = 0;
        scanf("%d %d %d", &N, &M, &G);

        unsigned char stu[500][13] = {0};
        int sco[10] = {0};

        int j = 0;
        for(j = 0; j<M; j++)
        {
            scanf("%d", &sco[j]);
        }

        int num =0;
        for(j = 0; j<N; j++)
        {
            scanf("%s", &stu[j][0]);
            int n = 0;
            scanf("%d",&n);
            int p = 0;
            for(p = 0; p<n; p++)
            {
                int q = 0;
                scanf("%d", &q);
                if(stu[j][11] + sco[q-1]<127)stu[j][11] +=  sco[q-1];
                else stu[j][12] += sco[q-1];
            }
            if ((stu[j][11]+ stu[j][12] ) >= G)

            {
                num++;
            }
        }
        qsort(stu, N, sizeof(stu[0]), cmp);
        printf("case #%d:\n", i);
        printf("%d\n", num);
        for(j = 0; j<num; j++)
        {
            int p = 0;
            for(p = 0; p<11; p++)
            {
                printf("%c",stu[j][p]);
            }
            printf(" %d\n", (stu[j][11]+stu[j][12]));
        }

    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T; scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int num[100] = {}; int p = 0;
        int mod[100] = {}; int q = 0;
        int bucket[1001] = {};
        int pos1,pos2;
        int n,m; scanf("%d %d",&n,&m);
        printf("case #%d:\n",i);
        while (1)
        {
            num[p++] = n/m;
            n %= m;
            if (n==0)
            {
                printf("0.");
                for (int j=1;j<p;j++) printf("%d",num[j]);
                printf("\n");
                break;
            }
            mod[q++] = n;
            if (bucket[n]==0) bucket[n]++;
            else
            {
                pos2 = --q;
                while (mod[--q]!=n) ;
                pos1 = q+1;
                printf("0.");
                for (int j=1;j<p;j++) printf("%d",num[j]);
                printf("\n%d-%d\n",pos1,pos2);
                break;
            }
            n *= 10;
        }
    }
    system("pause");
    return 0;
}
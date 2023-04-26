#include <stdio.h>
#include <stdlib.h>

struct onenum {
    long long val;
    int onum;
};
int cmp(const void *a,const void *b)
{
    struct onenum *a1=(struct onenum*)a,*b1=(struct onenum*)b;
    if(a1->onum != b1->onum)
        return b1->onum-a1->onum;
    else
        if(a1->val>b1->val)
            return 1;
    return -1;
}
int main() {
    struct onenum NUM[10000];
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        long long a[10000];
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            NUM[i].val = a[i];
        }
        for (int i = 0; i < n; i++) {
            NUM[i].onum = 0;
            long long m = 1;
            int x=64;
            while (x > 0) {
                if (a[i] & m)
                    NUM[i].onum++;
                m = m << 1;
                x--;
            }
        }
        qsort(NUM,n,sizeof (NUM[0]),cmp);
        printf("case #%d:\n",t);
        for(int i=0;i<n;i++)
        {
            printf("%lld%c",NUM[i].val,i==n-1?'\n':' ');
        }
    }
    return 0;
}

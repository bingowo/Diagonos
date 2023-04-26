#include <stdio.h>
#include <string.h>

typedef struct {int cnt; int pos[334];} Bigint;

void bigdiv(Bigint* n)
{
    int carry = 0;
    if (n->pos[n->cnt-1]<2) {n->cnt--; carry = 1;}
    for (int i=n->cnt-1;i>=0;i--)
    {
        int t = 10*carry+n->pos[i];
        n->pos[i] = t/2;
        carry = t%2;
    }
}

void bigmul(Bigint* n,int d)
{
    int carry = d;
    for (int i=0;i<n->cnt;i++)
    {
        int t = carry+n->pos[i]*2;
        n->pos[i] = t%10;
        carry = t/10;
    }
    if (carry>0) n->pos[n->cnt++] = carry;
}

int main()
{
    int T; scanf("%d",&T);
    for (int t=0;t<T;t++)
    {
        char num[102] = {}; scanf("%s",num);
        printf("case #%d:\n",t);
        if (strcmp(num,"0")==0) {printf("0\n"); continue;}
        Bigint n;
        n.cnt = strlen(num);
        for (int i=0;i<n.cnt;i++) n.pos[i] = num[n.cnt-i-1]-'0';
        int arr[334], cnt = 0;
        while (n.cnt>0)
        {
            arr[cnt++] = n.pos[0]%2;;
            bigdiv(&n);
        }
        for (int i=0;i<cnt;i++) bigmul(&n,arr[i]);
        for (int i=n.cnt-1;i>=0;i--) printf("%d",n.pos[i]);
        printf("\n");
    }
    return 0;
}
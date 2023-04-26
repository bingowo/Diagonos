#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int cnt,v[70];
}BIGINT;

BIGINT B[50];
int cmp(const void *a,const void *b)
{
    BIGINT *a1=(BIGINT*)a,*b1=(BIGINT*)b;
    if(a1->cnt == b1->cnt)
    {
        for(int i=(a1->cnt)-1;i>=0;i--)
        {
            if(a1->v[i] != b1->v[i])
                return a1->v[i]-b1->v[i];
        }
    }
    return a1->cnt-b1->cnt;
}

BIGINT sub(BIGINT S,BIGINT T)
{
    BIGINT R={0,{0}};
    int temp;
    for(int i=0;i<T.cnt;i++)
    {
        temp=S.v[i]-T.v[i];
        R.v[i]=temp;
        if(temp<0)
        {
            R.v[i]+=10;
            S.v[i+1]-=1;
            int j=i+1;
            while(S.v[j]<0 && j<S.cnt)
            {
                S.v[j]+=10;
                j++;
                S.v[j]-=1;
            }
        }
    }
    for(int i=T.cnt;i<S.cnt;i++)
    {
        R.v[i]=S.v[i];
    }
    return R;
}

int main()
{
    int n;
    scanf("%d",&n);
    char s[50][70];
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
        B[i].cnt= strlen(s[i]);
        for(int j=0,k=B[i].cnt-1;j<B[i].cnt;j++,k--)
        {
            B[i].v[j]=s[i][k]-'0';
        }
    }
    qsort(B,n,sizeof (B[0]),cmp);
    BIGINT R={0,{0}};
    R=sub(B[n-1],B[0]);
    for(int i=R.cnt-1;i>=0;i--)
    {
        printf("%d",R.v[i]);
    }
    printf("\n");
}
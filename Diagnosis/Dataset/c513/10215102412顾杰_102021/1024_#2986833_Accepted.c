#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef struct{int cnt,v[334];}BIGINT;
BIGINT int2BIG(int x)
{
    BIGINT R={0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    }
    while(x>0);
    return R;
}
BIGINT ADD(BIGINT S,BIGINT T)
{
    BIGINT R={0};
    int i,carry=0;
    for(i=0;i<S.cnt&&i<T.cnt;i++)
    {
        int temp=(S.v[i]+T.v[i]+carry);
        R.v[i]=temp%10;
        carry=temp/10;
    }
    while(i<S.cnt)
    {
        int temp=S.v[i]+carry;
        R.v[i++]=temp%10;
        carry=temp/10;
    }
    while(i<T.cnt)
    {
        int temp=T.v[i]+carry;
        R.v[i++]=temp%10;
        carry=temp/10;
    }
    if(carry)
    {
        R.v[i++]=carry%10;
    }
    R.cnt=i;
    return R;
}
void DIV2(BIGINT *n)
{
    int carry=0,i;
    if(n->v[n->cnt-1]<2){n->cnt--;carry=1;}
    for(i=n->cnt-1;i>=0;i--)
    {
        int t=10*carry+n->v[i];
        n->v[i]=t/2;
        carry=t%2;
    }
}
long long N2T(long long a)
{
    return a<9?a:N2T(a/10)*9+a%10;
}
typedef struct {char id[12];int mark;}STUDENT;
int cmp(const void*a,const void*b)
{
    STUDENT sa=*(STUDENT*)a,sb=*(STUDENT*)b;
    if(sa.mark==sb.mark)return strcmp(sa.id,sb.id);
    else return sb.mark-sa.mark;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int n0,m,g,tab[11],sn=0;
        STUDENT stu[500];
        scanf("%d%d%d",&n0,&m,&g);
        for(int j=0;j<m;j++)scanf("%d",&tab[j]);
        for(int j=0;j<n0;j++)
        {
            int num,mar=0,t;
            scanf("%s%d",stu[j].id,&num);
            for(int k=0;k<num;k++){scanf("%d",&t);mar+=tab[t-1];}
            stu[j].mark=mar;
            if(mar>=g)sn++;
        }
        qsort(stu,n0,sizeof(stu[0]),cmp);
        printf("case #%d:\n%d\n",i,sn);
        for(int j=0;j<sn;j++)printf("%s %d\n",stu[j].id,stu[j].mark);
    }
}

#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int r,h;
    long long int S,SS;
}column;

int cmp1(const void*a,const void*b)
{
    column c = *(column*)a;
    column d = *(column*)b;
    if(c.S<d.S)return 1;
    else return -1;
}


int cmp2(const void*a,const void*b)
{
    column c = *(column*)a;
    column d = *(column*)b;
    if(c.SS<d.SS)return 1;
    else return -1;
}

int main()
{
    int n,m,i,j;
    long long int SSS;
    column *s,*ss;
    scanf("%d%d",&n,&m);
    s = (column *)malloc(n*sizeof(column));
    ss = (column *)malloc((n-1)*sizeof(column));
    for(i = 0; i < n; i++)scanf("%d%d",&s[i].r,&s[i].h);
    for(i = 0; i < n; i++)
        {
            s[i].S = 2 * s[i].r * s[i].h;
            s[i].SS = s[i].S + s[i].r * s[i].r;
        }
    qsort(s,n,sizeof(s[0]),cmp2);//先按底面面积和侧面面积和的大小从大到小排序；
    for(i = 1; i < n; i++)ss[i-1] = s[i];//用ss将剩下的n-1个储存；
    qsort(ss,n-1,sizeof(ss[0]),cmp1);//再按侧面面积从大到小排一遍；
    SSS = s[0].SS;
    for(j = 0; j < m-1; j++)//选取ss的前m-1个加起来；
        SSS = SSS + ss[j].S;
    printf("%lld\n",SSS);
    return 0;

}
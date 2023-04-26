#include<stdio.h>
#include<stdlib.h>
typedef struct{int r,h;long long int S;}column;

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
    if(c.r<d.r)return 1;
    else return -1;
}


int main()
{
    int n,m,i,j;
    long long int SS;
    column *s,*t;
    scanf("%d%d",&n,&m);
    s = (column *)malloc(n*sizeof(column));
    t = (column *)malloc(m*sizeof(column));
    for(i = 0; i < n; i++)scanf("%d%d",&s[i].r,&s[i].h);
    for(i = 0; i < n; i++)
        s[i].S = 2 * s[i].r * s[i].h;
    qsort(s,n,sizeof(s[0]),cmp1);//先按表面积从大到小排一遍；
    for(j = 0; j < m; j++)
        t[j] = s[j];
    qsort(t,m,sizeof(t[0]),cmp2);//再把这几个表面积大的按半径大小降序排一遍；
    SS = t[0].r * t[0].r;
    for(j = 0; j < m; j++)
        SS = SS + t[j].S;
    printf("%lld",SS);
    return 0;

}

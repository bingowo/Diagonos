#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    long long int r,h;
    long long int S,SS;
}column;

int cmp1(const void*a,const void*b)
{
    column c = *(column*)a;
    column d = *(column*)b;
    if(c.S<d.S)return 1;
    else return -1;
}//按侧面积降序排

int cmp2(const void*a,const void*b)
{
    column c = *(column*)a;
    column d = *(column*)b;
    if(c.r<d.r)return 1;
    else return -1;
}//按半径大小降序排


int main()
{
    long long int n,m,i,j,SSS;
    column *s,*t;
    scanf("%lld%lld",&n,&m);
    s = (column *)malloc(n*sizeof(column));
    t = (column *)malloc(m*sizeof(column));
    for(i = 0; i < n; i++)scanf("%lld%lld",&s[i].r,&s[i].h);
    for(i = 0; i < n; i++)
        {
            s[i].S = 2 * s[i].r * s[i].h;
            s[i].SS = s[i].S + s[i].r * s[i].r;
        }
    qsort(s,n,sizeof(s[0]),cmp1);//先按侧面面积的大小从大到小排序；
    SSS = 0;
    for(i = 0; i < m; i++){SSS = SSS + s[i].S;t[i] = s[i];}
    qsort(t,m,sizeof(t[0]),cmp2);//再按半径大小降序排列；
    SSS = SSS + t[0].r * t[0].r;//加上半径最大的圆的面积；
    printf("%lld\n",SSS);
    return 0;
}

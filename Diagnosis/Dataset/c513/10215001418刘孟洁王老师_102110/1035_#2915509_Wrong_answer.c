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

int cmp3(const void*a,const void*b)
{
    column c = *(column*)a;
    column d = *(column*)b;
    if(c.SS<d.SS)return 1;
    else return -1;
}//底面面积和侧面面积和的大小从大到小排序

int main()
{
    long long int n,m,i,j,SSS;
    column *s,*ss,*t;
    scanf("%lld%lld",&n,&m);
    s = (column *)malloc(n*sizeof(column));
    t = (column *)malloc(m*sizeof(column));
    ss = (column *)malloc((n-1)*sizeof(column));
    for(i = 0; i < n; i++)scanf("%lld%lld",&s[i].r,&s[i].h);
    for(i = 0; i < n; i++)
        {
            s[i].S = 2 * s[i].r * s[i].h;
            s[i].SS = s[i].S + s[i].r * s[i].r;
        }
    qsort(s,n,sizeof(s[0]),cmp3);//先按底面面积和侧面面积和的大小从大到小排序；
    t[0] = s[0];
    for(i = 1; i < n; i++)ss[i-1] = s[i];//用ss将剩下的n-1个储存；
    qsort(ss,n-1,sizeof(ss[0]),cmp1);//再按侧面面积从大到小排一遍；
    for(j = 1; j < m; j++)t[j] = ss[j-1];
    for(j = 0; j < m-1; j++)SSS = SSS + ss[j].S;//算第二个到m个这些的侧面积和；
    qsort(t,m,sizeof(t[0]),cmp2);//再按半径大小降序排列；
    SSS = t[0].SS;//记录第一个圆柱体的侧面积加底面积；
    for(j = 1; j < m; j++)
         SSS = SSS + t[0].SS;
    printf("%lld\n",SSS);
    return 0;

}

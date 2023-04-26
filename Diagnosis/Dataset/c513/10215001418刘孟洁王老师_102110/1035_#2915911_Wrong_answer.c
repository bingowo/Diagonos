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
    column *s,*ss;
    scanf("%lld%lld",&n,&m);
    s = (column *)malloc(n*sizeof(column));
    ss = (column *)malloc((n-1)*sizeof(column));
    for(i = 0; i < n; i++)scanf("%lld%lld",&s[i].r,&s[i].h);
    for(i = 0; i < n; i++)
        {
            s[i].S = 2 * s[i].r * s[i].h;
            s[i].SS = s[i].r * s[i].r;
        }
    qsort(s,n,sizeof(s[0]),cmp2);//先按半径的大小从大到小排序；
    for(i = 1; i < n; i++)ss[i-1] = s[i];//用ss将剩下的n-1个储存；
    qsort(ss,n-1,sizeof(ss[0]),cmp1);//再按侧面面积从大到小排一遍；
    SSS = s[0].S;
    for(j = 0; j < m-1; j++)SSS = SSS + ss[j].S;//算第二个到m个这些的侧面积和；
    SSS = SSS + s[0].SS;//加上最大的底面积；
    printf("%lld\n",SSS);
    return 0;

}

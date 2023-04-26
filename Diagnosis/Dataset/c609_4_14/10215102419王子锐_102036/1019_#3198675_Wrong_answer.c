#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct data
{
    int dig;
    int val;
};
int getDig (int val)
{
    val = abs(val);
    int ans = 0;
    while (val)
    {
        ans ++;
        val /= 10;
    }
    return ans;
}
int cmp(const void *a,const void *b){
    struct data d1,d2;
    d1=*((struct data *)a);
    d2=*((struct data *)b);
    if (d1.dig != d2.dig)
        return d1.dig > d2.dig;
    return d1.val < d2.val;
}

int main()
{
    int n=0;
    struct data p[1000000];
    while(scanf("%d",&p[n++].val)!=EOF)
    {
        p[n].dig = getDig(p[n].val);
    }
    qsort(p,n+1,sizeof(p[0]),cmp);
    for(int i=0; i<n; i++)
    printf("%d%c",p[i].val,(i==n?'\n':' '));
    return 0;
    
}
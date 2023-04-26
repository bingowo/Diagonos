#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct val{int num;int dig;}s[1000000];

int getdig(int num;)
{
    int num;
    num=abs(num);
    int ans=0;
    while(num!=0)
    {
        num/=10;
        ans++;
    }
    return ans;
}

int cmp(const void *a,const void *b)
{
    if((val *)a.dig==(val*)b.dig)return (val *)a.num>(val*)b.num;
    else return (val*)a.dig>(val*)b.dig;
}

int main()
{
    int i=0;
    while(scanf("%d",&s[i].num)!=EOF)
    {
        s[i].dig=getdig(s[i].num);
        i++;
    }
    int j=i--;
    qsort(s,j,sizeof(s[0]),cmp);
    for(i=0;i<=j;i++)printf("%d ",s[i].num);
    return 0;
}

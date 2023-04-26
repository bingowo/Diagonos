#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Num
{
    int val;//数值
    int dig;//位数
}num;
num a[1000000];

int getdig(int n)
{
    n=abs(n);
    int ans=0;
    while(n)
    {
        ans++;
        n/=10;
    }
    return ans;
}

int cmp(const void *a,const void *b)
{
	num c=*(num*)a;
	num d=*(num*)b;
	if(c.dig!=d.dig)
        return d.dig-c.dig;
    else return c.val-d.val;
}

int main()
{
	int n=0;
	while(1)
    {
        scanf("%d",&a[n].val);
        a[n].dig=getdig(a[n].val);
        n++;
        if(getchar()=='\n') break;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i=0;i<n-1;i++)
        printf("%d ",a[i].val);
    printf("%d\n",a[n-1].val);
    return 0;
}
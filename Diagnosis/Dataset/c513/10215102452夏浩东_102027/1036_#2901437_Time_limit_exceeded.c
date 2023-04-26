#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct pos{
    long long int x;
    long long int y;
};
int cmp(const void *a,const void *b)
{
     struct pos*A=(struct pos*)a;
     struct pos*B=(struct pos*)b;
     long long int num1=(llabs)(A->x)+(llabs)(A->y);
     long long int num2=(llabs)(B->x)+(llabs)(B->y);
     if(num1<num2) return 1;
     else if(num2<num1) return -1;
     else 
     {
         if(A->x > B->x) return 1;
         else if(A->x < B->x) return -1;
         else
         {
            if(A->y > B->y) return 1;
            else return -1;
         }
     }
}
long long int num=0;
long long int step(long long int d1,long long int d2)
{
	long long int num=0;
	long long int d3=0;
	if(d1%2 == d2%2) return -1;
    while((d1+d2)!=1)
    {
    	if(d1%2==0)
    	{
    		d3=d1;
    		d1=d2;
    		d2=d3;
		}
    	if(((d1-1)/2)%2 != (d2/2)%2 )
		{
			d1=(d1-1)/2;
			d2=d2/2;
		}
		else
		{
			d1=(d1+1)/2;
			d2=d2/2;
		}
		num++;
	}
    return num+1;	
}

int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    struct pos *L=(struct pos*)malloc(cnt*sizeof(struct pos));
    for(int i=0;i<cnt;i++) scanf("%lld %lld",&L[i].x,&L[i].y);
    qsort(L,cnt,sizeof(L[0]),cmp);
    long long int dit =(llabs)(L[0].x-L[1].x)+(llabs)(L[0].y-L[1].y);
    printf("%lld\n",dit);
    long long int res=0;
    for(int i=0;i<cnt-1;i++)
    {
        long long int d1=llabs(L[i].x-L[i+1].x);
        long long int d2=llabs(L[i].y-L[i+1].y);
        long long int re=step(d1,d2);
        if(re!=-1) res+=re;
        else break;
    }
    printf("%lld",res);
    free(L);
    return 0;
}
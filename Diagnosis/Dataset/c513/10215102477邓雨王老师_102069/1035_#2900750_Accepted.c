#include<stdio.h>
typedef struct{
	long long r;
	long long h;
}yuan;
int cmp1(const void*a,const void*b){
	yuan x,y;
	x=*(yuan*)a;
	y=*(yuan*)b;
	if(x.r*x.h>y.r*y.h) return -1;
	else if(x.r*x.h==y.r*y.h){
		if(x.r>=y.r) return -1;
		else return 1;
	}
	else return 1;
}
int main(){
	long long sum=0;
	int number,choice;
	scanf("%d %d",&number,&choice);
	yuan a[number];
	int i;
	for(i=0;i<number;i++){
		scanf("%lld %lld",&a[i].r,&a[i].h);
	}
	qsort(a,number,sizeof(yuan),cmp1);
	long long maxn=-1;
	for(i=0;i<number;i++)
    {
        long long ans=a[i].r*a[i].h*2+a[i].r*a[i].r;
        int count1=1;
        int j;
        for(j=0;j<number&&count1<choice;j++)
        {
            if(i==j||a[i].r<a[j].r)    continue;
            ans+=a[j].r*a[j].h*2;
            count1++;
        }
        maxn=(maxn>ans)?maxn:ans;
    }
    printf("%lld",maxn);
    return 0;
	
}
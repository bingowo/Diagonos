#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct dot{
	long long int x,y;
	unsigned long long int d;
};
int cmp(const void*a,const void *b){
	struct dot p1,p2;
	p1=*(struct dot*)a;p2=*(struct dot*)b;
	if(p1.d!=p2.d)return p1.d>p2.d?-1:1;
	else {
		if(p1.x!=p2.x)return p1.x>p2.x?1:-1;
		else return p1.y>p2.y?1:-1;
	}
}
int main(int argc, char *argv[]) {
	long long int n,count,i,j,k;
	unsigned long long int r,rx,ry;
	struct dot num[105];
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		scanf("%lld%lld",&num[i].x,&num[i].y);
        num[i].d=llabs(num[i].x)+llabs(num[i].y);
	}  //记录坐标和距离
	qsort(num,n,sizeof(num[0]),cmp);  //从大到小排序 
	rx=llabs(num[0].x-num[1].x);
	ry=llabs(num[0].y-num[1].y);
    count=0;
    if(rx+ry==0 && rx>0)printf("18446744073709551616\n");
    else printf("%llu\n",rx+ry);  //输出曼哈顿距离
	for(i=0;i<n-1;i++){ 
	    //从第一个点出发
		rx=llabs(num[i].x-num[i+1].x);ry=llabs(num[i].y-num[i+1].y);
	    r=rx+ry;
	    if(r==0)continue;
	    else if(r%2==0)break;  //不能到达 
		else {
			k=0;
			while(pow(2,k)-1<r || pow(2,k-1)-1>=r){
				k++;
			}
			count+=k;
		}
	}
	printf("%lld",count);
	return 0;
}
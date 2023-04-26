#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void* a,const void* b){
	long long int *p1,*p2;
	p1=*(long long int (*)[2])a;p2=*(long long int (*)[2])b;
	if(*(p1+1)!=*(p2+1)) return *(p1+1)>*(p2+1)?-1:1;
	else return *p1>*p2?1:-1;  //顺序排列 
}
int main(int argc, char *argv[]) {
	long long int t,i,j,k,n; 
	long long int number[10000][2];
	scanf("%lld",&t);
	for(i=0;i<t;i++){
		for(j=0;j<10000;j++)for(k=0;k<2;k++)number[j][k]=0; //初始化为0 
		scanf("%lld",&n);  //数字的个数 
		for(j=0;j<n;j++){
			scanf("%lld",&number[j][0]);
			for(k=0;k<64;k++){
				if(number[j][0]&(1LL<<k))number[j][1]++;//记录1出现的次数 
			}
		}
		qsort(number,j,sizeof(number[0]),cmp);
		printf("case #%d:\n",i);
		for(k=0;k<j;k++)printf("%d ",number[k][0]);
		printf("\n");
	} 
	return 0;
}
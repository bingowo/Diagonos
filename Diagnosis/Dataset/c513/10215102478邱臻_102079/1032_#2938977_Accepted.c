#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void*a,const void*b){
	long long int *p1,*p2;
	p1=*(long long int(*)[51])a;p2=*(long long int(*)[51])b;
	while(*p1 && *p2){
		if(*p1!=*p2){
			return *p1>*p2?-1:1;  //按降序排列 
		}
		else {
			p1++;p2++;
		}
	}
}

int main() {
	long long int n,t,m,q,x,i,j,k,z;
	long long int number[1001][51];
	scanf("%lld",&t);
	for(i=0;i<t;i++){
		scanf("%lld",&n);
		for(j=0;j<1001;j++){
			for(k=0;k<51;k++)number[j][k]=-1;
		}  //初始化数组 
		for(j=0;j<n;j++){  //每一行的输入 
		    for(k=0;;k++){
		    	scanf("%lld",&x);
		    	if(x!=-1)number[j][k]=x;
		    	else break;
			}
		}
		qsort(number,n,sizeof(number[0]),cmp);
		for(z=0;z<n;z++){
			q=0;
			while(number[z][q]!=-1){
				printf("%d ",number[z][q++]);
			}
			printf("\n");
		}
	}
	return 0;
}
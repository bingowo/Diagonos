#include<stdio.h>
#include<string.h>

int trans(int *res,int x){
	
	int i=0;
	while(x){
		res[i]=x%2;
		x=x/2;
		i++;
	}
	return i;	
}
int main(){
	int T,cnt;
	scanf("%d",&T);
	cnt=0;
	int x;
	while(T){
		int tran[100];
		scanf("%d",&x);
		int num=trans(tran,x);
		int res=1;
		int max=1;
		for (int i=0;i<num-1;i++){
			if(tran[i]!=tran[i+1]){
				res++;
			}
			else{
				res=1;
			}
			if(res>max){
				max=res;
			}
		}
		T-=1;
		printf("case #%d:\n%d\n",cnt,max);
		cnt+=1;	
	}
	return 0;
} 
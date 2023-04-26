#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

typedef struct{
	char ch[123456];
	int sum[123456];
}A;

int cmp(const void *a,const void *b){
	int A=*(int *)a;
	int B=*(int *)b;
	if(A>B)
	return 1;
	else
	return -1;
}

int main(){
	int T;
	scanf("%d",&T);
	A aa[T];
	for(int i=0;i<T;i++){
		char in[123456];
		scanf("%s",&in);
		int len=strlen(in);
		int k=0;
		for(int j=0;j<len;j++){
			int temp=1;
			while(in[j]==in[j+1]){
				j++;
				temp++;
			}
			aa[i].ch[k]=in[j];
			aa[i].sum[k]=temp;
			k++;
		}
		if(i>0){
			if(strcmp(aa[i].ch,aa[i-1].ch)!=0){
				printf("-1");
				exit(1);
			}
		}
			
	}
	int out=0;
	int l=strlen(aa[0].ch);
	for(int j=0;j<l;j++){
		int mid=0;
		int t[T];
	for(int i=0;i<T;i++)
		t[i]=aa[i].sum[j];
	qsort(t,T,sizeof(t[0]),cmp);
		if((T%2)==0)
		mid=(t[T/2-1]+t[T/2])/2;
		else
		mid=t[(T+1)/2-1];
	for(int i=0;i<T;i++){
		int te=t[i]-mid;
		if(te>=0)
		out+=te;
		else
		out-=te;
	}
	}
	printf("%d",out);
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b){
	return *((int*)a) - *((int*)b);
}
int main(){
	char a; int b[101];
	int i=0;
	scanf("%c",&a);
	while(scanf("%d",&b[i])!=EOF) i++;
	qsort(b,i,sizeof(b[0]),cmp); int c=i;
	if(a=='A'){
		for(i=0;i<c-1;i++){
			printf("%d ",b[i]);
			while(b[i]==b[i+1]) i++;	
		}
		if(i==c-1) printf("%d",b[i]);
	}
	else{
		for(i=c-1;i>0;i--){
			printf("%d ",b[i]);
			while(b[i]==b[i-1]) i--;
		}
		if(i==0) printf("%d",b[i]);
	}
	return 0;
} 
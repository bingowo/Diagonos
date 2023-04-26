#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	char flag;
	int A[110];
int cmp(const void*a,const void*b){
	int*a1=(int*)a,*b1=(int*)b;
	if(flag=='A') return *a1-*b1;
	else return *b1-*a1;
	
}
int main(int argc, char *argv[]) {
    int i=0,j,n;
    scanf("%c",&flag);
    while(scanf("%d",&n)!=EOF){
	A[i++]=n;
}
  qsort(A,i,sizeof(int),cmp);
  int temp=-1;
  for(j=0;j<i;j++){
  	if(A[j]!=temp){
  		printf("%d",A[j]);
  		if(j!=i-1) printf(" ");
  		temp=A[j];
	  }
	  
  }
	
	return 0;
}
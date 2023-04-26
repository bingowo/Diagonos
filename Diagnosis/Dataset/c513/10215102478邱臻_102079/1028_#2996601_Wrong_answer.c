#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp1(const void*a,const void*b){
	int *p1,*p2;
	p1=(int*)a;p2=(int*)b;
	return *p1>*p2?1:-1; 
}
int cmp2(const void*a,const void*b){
	int *p1,*p2;
	p1=(int*)a;p2=(int*)b;
	return *p1>*p2?-1:1; 
}
int main() {
	int number[105]={};
	int i=0,x,n=0;
	char c;
	scanf("%c",&c);
	while(scanf("%d",&number[i++])!=EOF){
		n++;
	}  //记录数字
	if(c=='A')qsort(number,n,sizeof(number[0]),cmp1);//升序 
	else qsort(number,n,sizeof(number[0]),cmp2); //降序 
	for(i=0;i<n;i++){
		if(number[i]==number[i+1]);
		else printf("%d",number[i]);
	}
	return 0;
}
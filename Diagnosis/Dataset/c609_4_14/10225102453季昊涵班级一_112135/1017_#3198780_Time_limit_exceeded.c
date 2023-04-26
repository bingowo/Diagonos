#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
	int A= *(int *)a;
	int B= *(int *)b;
	if(A>B)
	return 1;
	else
	return -1;
}

int main(){
	int a[100];
	int i=0;
	char s;
	scanf("%c",s);
	while((scanf("%d",&a[i]))!=EOF)
	i++;
	qsort(a,i,sizeof(a[0]),cmp);
	for(int j=0;j<i;j++){
		if(a[j]==a[j+1])
		continue;
		printf("%d ",a[j]);
	}
	return 0; 
} 
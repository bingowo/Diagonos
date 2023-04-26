#include<stdio.h>
#define MAX 50
int main(){
	char fence[MAX];
	int i=0,num=1,maxn=1;
	fgets(fence,MAX,stdin); 
	while(fence[i]!=EOF){
		if(fence[i]!=fence[i+1]) num++;
		else if(num>=maxn){
			maxn=num; num=1;
		}
		else num=1;
		i++;
	}
	printf("%d",maxn);
	return 0;
}
//1041
#include <stdio.h>
int main(){
	char ch;
	char n[51];
	int l=0;
	int cnt=0,max=0;
	while((ch=getchar())!='\n'){
		n[l]=ch;
		if(n[l]!=n[l-1]){
			cnt++;
			if(max<=cnt){
				max=cnt;
			}
		}
		else{
			if(max<=cnt){
				max=cnt;
			}
			cnt=0;
		}		
		l++;
	}
	printf("%d",max+1);
}
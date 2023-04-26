#include<stdio.h>
#include<string.h>
int main(){
	char a[50005];
	scanf("%s",a);
	int f=0,ma=0,cnt=0;
	for(int i=0;i<strlen(a);i++){
		if(a[i]>'0' && a[i]<='9') f=1;
		if(a[i]>'9'){
			if(ma<cnt) ma=cnt;
			cnt=0;
			f=0;
		}
		if(f==1) cnt++;		
	}
	if(ma<cnt) ma=cnt;
	printf("%d",ma);
}
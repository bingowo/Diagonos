#include <stdio.h>

char tochar(int x){
	if (x>=10) return 'A'+(x-10);
	else{
		char s='0'+x;
		return s;
	}
}

int main(){
	int N,R;
	scanf("%d%d",&N,&R);
	char a[20];
	for (int i=0;i<20;i++) a[i]='0';
	int k=19;
	if(N==0){
		k--;
	}
	while (N){
		if(N%R<0) {
			a[k]=tochar(N%R-R);
			N=N/R+1;
		}
		else{
			a[k]=tochar(N%R);
			N/=R;
		}
		k--;
	}
	k++;
	for (;k<20;k++) printf("%c",a[k]);
	return 0;
}
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
	char a[20]={0};
	int k=19;
	while (N){
		int x=N/R,y=N%R;
		if(y>=0) {
			a[k]=tochar(y);
			k--;
			N=x;
		}
		else{
			a[k]=tochar(y-R);
			N=x+1;
			k--;
		}
	}
	k++;
	for (;k<20;k++) printf("%c",a[k]);
	return 0;
}
#include <stdio.h>

int main(){
	char a[501];
	int digit=0,b[6000];
	b[0]=0,b[1]=0,b[2]=0,b[3]=1;
	scanf("%s",a);
	while(a[digit]!='\0') digit++;
	for(int j=0;j<digit/3;j++){
		int c[10],k=9;
		int number=(a[j*3]-'0')*100+(a[1+j*3]-'0')*10+(a[2+j*3]-'0');
		for (int q=0;q<10;q++) c[q]=0;
		while(number){
			c[k]=number%2;
			number/=2;
			k--;
		}
		for (int q=0;q<10;q++){
			b[14+10*j+q]=c[q];
		}
		b[14+10*j+10]=10;
	}
	int mod=digit%3;
	if(mod!=0){
		if (mod==1){
			int f=14+10*(digit/3)+3;
			b[f+1]=10;
			int s=a[digit-1]-'0';
			for (int y=0;y<4;y++){
				b[f]=s%2;
				s/=2;
				f--;
			}
		}
		else if(mod==2){
			int f=14+10*(digit/3)+6;
			b[f+1]=10;
			int s=10*(a[digit-2]-'0')+(a[digit-1]-'0');
			for (int y=0;y<7;y++){
				b[f]=s%2;
				s/=2;
				f--;
			}
		}
	}
	int g=13;
	while(digit){
		b[g]=digit%2;
		digit/=2;
		g--;
	}
	for(g;g>3;g--) b[g]=0;
	int x=0;
	while(b[x]<2){
		printf("%d",b[x]);
		x++;
	}
	return 0;
}
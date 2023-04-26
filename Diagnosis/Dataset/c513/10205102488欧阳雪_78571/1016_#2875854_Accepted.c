#include<stdio.h>
int main()
{
	char a[]="0123456789ABCDEFGHIJKLMN";
	int b[50]={0};
	int N,R,j=0;
	scanf("%d%d",&N,&R);
	if(!N){
		printf("0");
		return 0;
	}
	while(N){
		int temp=N%R;
		N/=R;
		if(temp<0){
			temp-=R;
			N++;
		}
		b[j]=temp;
		j++;
	}
	j--;
	while(j>=0){
		if(b[j]<10){
			printf("%d",b[j]);
		}
		else{
			printf("%c",a[b[j]]);
		}
		j--; 
	}
	return 0;
}
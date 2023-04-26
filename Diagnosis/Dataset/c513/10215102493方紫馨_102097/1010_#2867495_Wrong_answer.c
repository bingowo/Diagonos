#include<stdio.h>
void binary(int n,int r){
	unsigned int b;
	for(int i=r;i>0;i--){
		b=n<<(32-i)>>31;
		printf("%d",-b);
	}
}
int main()
{
	int num[50],c,i=0;
	while((c=getchar())!=EOF){
		num[i]=c-'0';
		i++;
	}
	printf("0001");
	binary(i,10);
	int n;
	for(int j=0;(j+3)<i;j=j+3){
		n=100*num[j]+10*num[j+1]+num[j+2];
		binary(n,10);
	}
	if(i%3==1){
		
		binary(num[i-1],4);
	}
	else if(i%3==2){
		n=num[i-2]*10+num[i-1];
		binary(n,7);
	}else{
		n=100*num[i-3]+10*num[i-2]+num[i-1];
		binary(n,10);
	}
	return 0;
}
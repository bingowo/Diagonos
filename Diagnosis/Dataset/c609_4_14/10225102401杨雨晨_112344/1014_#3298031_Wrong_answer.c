#include <stdio.h>
#include <math.h>
/*int * trans(int x,int y)
{
	if (x/3){
		trans(x/3);num[i]=x%3;i++;
		if (i)
	}
	else num[i]=x;
	return num;
}*/

int Caculate(int x){
	return x%3==2?x/3+1:x/3;
	}

int main(){
	int a,b,i,j;
	int m;
	double p;
	int num[32];
	scanf("%d %d",&a,&b);//输入两个数，整数 用空格分开
	m=a%b;
	p=log(b)/log(3);
	if (m==0){a=a/b;b=1;}
	for (i=0;Caculate(a);i++){
		num[i]=a%3;
		a=Caculate(a);
	}
	num[i]=a;
	if(p<i+1){
	for (j=i;j>=0;j--)
	{if (j==0&&num[j]==0){break;}
	printf("%d",num[j]);
	if (j==p&&m!=0)printf("%c",'.');}}
	else {printf("%c%c",'0','.');
	for (j=0;j<p-i-1;j++){printf("%c",'0');}
	for (j=i;j>=0;j--){printf("%d",num[i]);	}}
	
	return 0;

}
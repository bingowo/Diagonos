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
int Caculate1(int x){
	int m;
	x%3==2?m=x%3+1:m=x%3;
	return m;
}
int Caculate2(int x){
	int m;
	x%3==2?m=x/3+1:m=x/3;
	return m;
	}

int main(){
	int a,b,i,j;
	double p;
	int num[32];
	p=log(b)/log(3);
	scanf("%d %d",&a,&b);//输入两个数，整数 用空格分开
	for (i=0;Caculate2(a);i++){
		num[i]=Caculate1(a);
		a=Caculate2(a);
	}
	num[i]=a;
	for (j=i;j>=0;j--)
	{printf("%d",num[j]);
	if (i-j==2&&a%b!=0)printf("%c",'.');}
	return 0;

}
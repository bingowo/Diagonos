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
	double p;
	int num[32];
if (a%b==0){a=a/b;}
	p=log(b)/log(3);
	scanf("%d %d",&a,&b);//输入两个数，整数 用空格分开
	for (i=0;Caculate(a);i++){
		num[i]=a%3;
		a=Caculate(a);
	}
	num[i]=a;
	
	for (j=i;j>=0;j--)
	{printf("%d",num[j]);
	if (i-j==3&&a%b!=0)printf("%c",'.');}
	return 0;

}
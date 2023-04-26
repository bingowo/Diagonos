#include <stdio.h>
void trans(int x)
{	
	if (x/3){
		trans(x/3);printf("%d",x%3);
	}
	printf("%d",x);
}
int main(){
	int a,b;
	int m,n;
	scanf("%d %d",&a,&b);//输入两个数，整数 用空格分开
	m=a/b;n=a%b;
	trans(m);
	printf("%c",'.');
	trans(n);
	return 0;

}
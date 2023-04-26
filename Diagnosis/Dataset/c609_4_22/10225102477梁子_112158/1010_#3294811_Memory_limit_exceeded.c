#include<stdio.h>
#include<string.h>
void trans(int n,int R)
{
	char t[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int d=n%R;
	int c=n/R;
	if(n){
		c++;
		d=d-R;}
	trans(c,R);
	printf("%c",t[d]);
}
int main()
{
	int n,R;
	scanf("%d",&n);
	scanf("%d",&R);
	if(n==0)printf("0");
	else trans(n,R);
	return 0;
}
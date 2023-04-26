#include<stdio.h>
#include<math.h>
#include<string.h>
int y=0;
void f(int x,int z)
{
	if(x) {y++;f(x/2,z);}
	else return;
	while(y<z){printf("0");y++;}
	printf("%d",x%2);
}
int main()
{
	int n,b,z;
	char a[500];
	scanf("%s",a);
	printf("0001");
	f(strlen(a),10);y=0;
	n=(strlen(a)+2)/3;
	for(int i=0;i<n;i++)
	{
		if((a[i*3+1]!='\0')&&(a[i*3+2]!='\0')) {b=(a[i*3]-48)*100+(a[i*3+1]-48)*10+(a[i*3+2]-48);z=10;}
		if(a[i*3+1]!='\0'){b=(a[i*3]-48)*10+(a[i*3+1]-48);z=7;}
		else {b=a[i*3]-48;z=4;}
		if(b!=0){f(b,z);y=0;}
		else{printf("0000000000");}
	}
	
	return 0;
	
	
 } 
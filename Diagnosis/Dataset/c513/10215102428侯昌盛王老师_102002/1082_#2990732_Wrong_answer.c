#include <stdio.h>
#include <string.h>
void input(int *a)
{
	char r[501];
	scanf("%s",r);
	int i,len=strlen(r);
	for(i=0;r[i]!='.'&&i<len;i++);
 
	//printf("h\n");
	int j,n;
	for(j=500,n=i-1;n>=0;j--,n--) a[j]=r[n]-'0';
	for(j=501,n=i+1;n<len;j++,n++) a[j]=r[n]-'0';
}
void add(int *a,int*b,int n)
{
	int i;
	for(i=1000;i>500+n;i--)
	{
		a[i]+=b[i];
		a[i-1]+=a[i]/10;
		a[i]%=10;
	}
	if(a[i+1]>5) a[i]++;
	for(i=500+n;i>=0;i--) 
	{
		a[i]+=b[i];
		a[i-1]+=a[i]/10;
		a[i]%=10;
	}
}
void output(int *a,int n)
{
	int i;
	for(i=0;a[i]==0;i++);
	if(i==501) printf("0");
	int k;
	for(k=i;k<=500;k++) printf("%d",a[k]);
	printf(".");
	for(k;k<=500+n;k++) printf("%d",a[k]);
	printf("\n");
}
int main()
{
	int a[1002]={0},b[1002]={0},n;
	//printf("h\n");
	input(a);input(b);
	//printf("%d\n",a[2]);
	//printf("h");
	scanf("%d",&n);
	add(a,b,n);
	output(a,n);
	return 0;
}
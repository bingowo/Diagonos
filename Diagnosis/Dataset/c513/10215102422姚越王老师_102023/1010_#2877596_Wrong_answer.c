#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void change_dec_into_bin(const void* a,int dec,int length)
{
	int* ax=(int*)a;
	int i=length;
	while(i--)
	{
		ax[i]=dec%2;
		dec/=2;
	}
	for(int i=0;i<length;i++)printf("%d",ax[i]);
}
int main()
{
	char s[510];
	scanf("%s",s);
	int length=strlen(s),i;
	printf("0001");
	int b[10];change_dec_into_bin(b,length,10);
	for(i=0;s[i];)
	{
		char sx[4];
		sx[0]=s[i++];
		sx[1]=s[i++];
		sx[2]=s[i++];
		sx[3]=0;
		int n=atoi(sx);
		int a[10];
		change_dec_into_bin(a,n,10);
		if(i+3>strlen(s))break;
	}
	if(i+1==strlen(s))
	{
		char sx[2];
		sx[0]=s[i];
		sx[1]=0;
		int n=atoi(sx);
		int a[4];
		change_dec_into_bin(a,n,4);
	}
	else if(i+2==strlen(s))
	{
		char sx[2];
		sx[0]=s[i];
		sx[1]=0;
		int n=atoi(sx);
		int a[4];
		change_dec_into_bin(a,n,7);
	}
	return 0;
}
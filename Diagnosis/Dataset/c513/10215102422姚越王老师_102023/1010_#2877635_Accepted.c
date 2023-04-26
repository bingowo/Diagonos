#include<stdlib.h>
void dec2bin(const void* a,int dec,int length)
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
	int length=strlen(s);
	printf("0001");
	int a[10];
	dec2bin(a,length,10);
	if(length%3==0)
	{
		for(int i=0;i<length;i+=3)
		{
			char sx[4];sx[0]=s[i];sx[1]=s[i+1];sx[2]=s[i+2];sx[3]=0;
			int n=atoi(sx);
			int b[10];
			dec2bin(b,n,10);
		}
	}
	else if(length%3==1)
	{
		int i;
		for(i=0;i<length-1;i+=3)
		{
			char sx[4];sx[0]=s[i];sx[1]=s[i+1];sx[2]=s[i+2];sx[3]=0;
			int n=atoi(sx);
			int b[10];
			dec2bin(b,n,10);
		}
		char sx[2];sx[0]=s[i];sx[1]=0;
		int n=atoi(sx);
		int b[4];
		dec2bin(b,n,4);
	}
	else
	{
		int i;
		for(i=0;i<length-2;i+=3)
		{
			char sx[4];sx[0]=s[i];sx[1]=s[i+1];sx[2]=s[i+2];sx[3]=0;
			int n=atoi(sx);
			int b[10];
			dec2bin(b,n,10);
		}
		char sx[3];sx[0]=s[i];sx[1]=s[i+1];sx[2]=0;
		int n=atoi(sx);
		int b[7];
		dec2bin(b,n,7);
	}
	return 0;
}
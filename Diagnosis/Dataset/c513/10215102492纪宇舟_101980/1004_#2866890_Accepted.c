#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char a[100];
	int cnt1=sizeof(int);int cnt2=sizeof(double);
	while(scanf("%s",a)!=EOF)
	{
		char *p;p=strchr(a,'.');
		if(p)
		{
			double x=atof(a);
			unsigned char* ans=(unsigned char*)&x;
			for(int i=1;i<=cnt2;i++)
			printf("%02x ",*ans++);
		}
		else
		{
			int y=atoi(a);
			unsigned char* ans=(unsigned char*)&y;
			for(int i=1;i<=cnt1;i++)
			printf("%02x ",*ans++);
		}
		printf("\n");
	}
	return 0;
}
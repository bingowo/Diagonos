#include<stdio.h>
#include<stdlib.h>
int define_is_int(const char* s)
{
	int flag=1;
	while(*s++)
	{
		if(*s=='.')return 0;
	}
	return flag;
}
void int_print(const void* a)
{
	int* ax=(int*)a;
	int t;
	for(int i=0;i<8;i++,ax+=4)
	{
		t=*(ax+3)+*(ax+2)*2+*(ax+1)*4+*ax*8;
		if(i%2==0)printf("%x",t);
		else printf("%x ",t);
	}
	printf("\n");
}
void double_print(const void* a)
{
	int* ax=(int*)a;
	int t;
	for(int i=0;i<16;i++,ax+=4)
	{
		t=*(ax+3)+*(ax+2)*2+*(ax+1)*4+*ax*8;
		if(i%2==0)printf("%x",t);
		else printf("%x ",t);
	}
	printf("\n");
}
int main()
{
	char s[1005];
	while((scanf("%s",s))==1)
	{
		char *p=s;
		if(define_is_int(p)==1)
		{
			int ans=atoi(s),p=1,a[32];
			for(int i=0;i<32;i++,p<<=1)
			{
				if(i<=7)
				{
					if(ans&p)a[7-i]=1;
					else a[7-i]=0;
				}
				else if(i<=15)
				{
					if(ans&p)a[23-i]=1;
					else a[23-i]=0;
				}
				else if(i<=23)
				{
					if(ans&p)a[39-i]=1;
					else a[39-i]=0;
				}
				else
				{
					if(ans&p)a[55-i]=1;
					else a[55-i]=0;
				}
			}
			int_print(a);
		}
		else
		{
			int a[64];
			long long ans=(long long)atof(s);
			long long p=1;
			for(int i=0;i<64;i++,p<<=1)
			{
				if(i<=7)
				{
					if(ans&p)a[7-i]=1;
					else a[7-i]=0;
				}
				else if(i<=15)
				{
					if(ans&p)a[23-i]=1;
					else a[23-i]=0;
				}
				else if(i<=23)
				{
					if(ans&p)a[39-i]=1;
					else a[39-i]=0;
				}
				else if(i<=31)
				{
					if(ans&p)a[55-i]=1;
					else a[55-i]=0;
				}
				else if(i<=39)
				{
					if(ans&p)a[71-i]=1;
					else a[71-i]=0;
				}
				else if(i<=47)
				{
					if(ans&p)a[87-i]=1;
					else a[87-i]=0;
				}
				else if(i<=55)
				{
					if(ans&p)a[103-i]=1;
					else a[103-i]=0;
				}
				else
				{
					if(ans&p)a[119-i]=1;
					else a[119-i]=0;
				}
				double_print(a);
			}
		}
	}
	return 0;
}
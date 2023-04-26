#include<stdio.h>
int add(char a[])
{
	if(a[63]=='0')  a[63]='1';
	else
	{
		a[63]='0';
		int i;
		for(i=63;i>=0;i--)
		{
			if(a[i-1]=='0')    
			{
				a[i-1]='1';
				break;
			}
			else
			{
				a[i-1]='0';
			}
		}
/*		while(a[i-1]!='0')  
		{
			a[i]='0';
			a[i-1]='0';
			i--;
		}
		a[i-1]='1';
*/
	}
	int c=0,j;
	for(j=0;j<64;j++)
		if(a[j]=='1')  c++;
	return c;
}

typedef struct mem
{
	long long data;
	int num;
}mem;

int cmp(const void* a,const void*b)
{
	struct mem d1,d2; //结构体排序必须先转换类型 
    d1=*(( struct mem *) a );
    d2=*(( struct mem *) b );
  	if(d1.num==d2.num)
  		return d1.data-d2.data;
	else
		return d2.num-d1.num;
}

int count(long long n)
{
	int len=1,count=0,i;
	long long x=n;
	if(x>=0)
	{
		while(x/2!=0)
		{
			x/=2;
			len++;
		}
		for(i=0;i<len;i++)
		{
			if(n%2==1)	count++;
			n/=2;
		}
	}
	else  //负数是先取反再加一 
	{
		x=0-x;
		n=0-n;
		char a[64];  //如：1234 a[0]是1 
		while(x/2!=0)
		{
			x/=2;
			len++;
		}
		for(i=63;i>63-len;i--)
		{
			if(n%2==0)  a[i]='1';
			else  a[i]='0';
			n/=2;
		}
		for(i=0;i<64-len;i++)
			a[i]='1';
		count=add(a);
	}
	return count;
}

int main()
{
	int t;
	scanf("%d",&t);
	int i,j;
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		struct mem m[10000];
		for(j=0;j<n;j++)
		{
			scanf("%lld",&m[j].data);
			m[j].num=count(m[j].data);
		}	
		qsort(m,n,sizeof(m[0]),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<n;j++)
			printf("%lld ",m[j].data);
		printf("\n");
	}
} 

#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	int i=0;
	for(i;i<T;i++)
	{
		int N;
		scanf("%d",&N);
		long s[N];
		int j=0; 
		for(j;j<N;j++)
		{
			scanf("%ld",&s[j]);
		}
		int x=0;
		for(x;x<N-1;x++)
		{
			int y=x+1;
			for(y;y<N;y++)
			{
				unsigned int a,b;
				int r=0,t=0;
				if(s[x]<0)
				{
					a=-s[x]-1;
					int m=0;
					for(m;m<64;m++)
					{
						if(a%2==1)
						{
							r++;
						}
						a=a/2;
						if(a==0) break;
					}
					r=64-r;
				}
				else
				{
					a=s[x];
					int m=0;
					for(m;m<64;m++)
					{
						if(a%2==1)
						{
							r++;
						}
						a=a/2;
						if(a==0) break;
					}
				}
				if(s[y]<0)
				{
					b=-s[y]-1;
					int n=0;
					for(n;n<64;n++)
					{
						if(b%2==1)
						{
							t++;
						}
						b=b/2;
						if(b==0) break;
					}
					t=64-t;
				}
				else
				{
					b=s[y];
					int n=0;
					for(n;n<64;n++)
					{
						if(b%2==1)
						{
							t++;
						}
						b=b/2;
						if(b==0) break;
					}
				}
				
				if(r<t)
				{
					long  w=s[x];
					s[x]=s[y];
					s[y]=w;
				}
				else if(r==t&&s[x]>s[y])
				{
					long  p=s[x];	
					s[x]=s[y];
					s[y]=p;
				}
			}
		}
		printf("case #%d:\n",i);
		int q=0;
		for(q;q<N-1;q++)
		{
			printf("%ld ",s[q]);
		}
		printf("%ld\n",s[N-1]);
	}
	return 0;
} 
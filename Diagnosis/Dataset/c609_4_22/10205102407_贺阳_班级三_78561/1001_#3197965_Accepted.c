#include<stdio.h> 
int main()
{
	int T;
	scanf("%d",&T);
	int i=0;
	for(i;i<T;i++)
	{
		int N,R;
		scanf("%d %d",&N,&R);
		if(R==10)
		{
			printf("%d\n",N);
		}
		else if(R<10)
		{
			if(N<0)
			{
				N=-N;
				int a[100];
				int x=N,b=0;
				while(1)
				
				{
					int y=x%R;
					a[b]=y;
					b++;
					x=x/R;
					if(x==0) break;
				}
				int s=b-1;
				printf("-");
				for(s;s>=0;s--)
				{
					if(s!=0) printf("%d",a[s]);
					else printf("%d\n",a[s]);
				}
			}
			else
			{
				int a[100];
				int x=N,b=0;
				while(1)
				{
					int y=x%R;
					a[b]=y;
					b++;
					x=x/R;
					if(x==0) break;
				}
				int s=b-1;
				for(s;s>=0;s--)
				{
					if(s!=0) printf("%d",a[s]);
					else printf("%d\n",a[s]);
				}
			}
		}
		else
		{
			if(N<0)
			{
				N=-N;
				char a[100];
				int x=N,b=0;
				while(1)
				{
					int y=x%R;
					if(y<10) a[b]=y+48;
					else a[b]=y+55;
					b++;
					x=x/R;
					if(x==0) break;
				}
				int s=b-1;
				printf("-");
				for(s;s>=0;s--)
				{
					if(s!=0) printf("%c",a[s]);
					else printf("%c\n",a[s]);
				}
			}
			else
			{
				char a[100];
				int x=N,b=0;
				while(1)
				{
					int y=x%R;
					if(y<10) a[b]=y+48;
					else a[b]=y+55;
					b++;
					x=x/R;
					if(x==0) break;
				}
				int s=b-1;
				for(s;s>=0;s--)
				{
					if(s!=0) printf("%c",a[s]);
					else printf("%c\n",a[s]);
				}
			}
		}
	}
	return 0;
}
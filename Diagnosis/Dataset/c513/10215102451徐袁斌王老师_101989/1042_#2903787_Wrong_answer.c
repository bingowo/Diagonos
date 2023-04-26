#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct stu
	{
		char a;
		int b;
	};
int cmp(const void *a,const void *b)
{
	struct stu* A=(struct stu*)a;
	struct stu* B=(struct stu*)b;
	if(A->a!=B->a)
	{
		if((A->a)-(B->a)>0){return 1;}
		else return -1;
	} 
	else
	{
		if((B->b)-(A->b)>0) return 1;
		else return -1;
	}
}
int main()
{
	int t,j=0,n=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		char a[16];
		struct stu b[16];
		struct stu *p=b;
		for(int u=0;u<16;u++)
		{
			b[u].a=123;
			b[u].b=0;
			a[u]='\0';
		}
		scanf("%s",a);
		while(a[n]!='\0')
		{
			n++;
		}
		for(j=0;j<n;j++)
		{
			if(a[j]<=90) 
			{
				b[j].a=a[j]+32;
				b[j].b=1;
			}
			else
			{
				b[j].a=a[j];
				b[j].b=0;
			}
		}
		qsort(p,n,sizeof(struct stu),cmp);
		for(int k=0;k<j+1;k++)
		{
			for(int g=k+1;g<j+1;g++)
			{
				if(b[k].a==b[g].a&&b[k].b==b[g].b)
				{
					for(int temp=g;temp<j+1;temp++)
					{
						b[temp].a=b[temp+1].a;
						b[temp].b=b[temp+1].b;
					}
					j--;g--;
				}
			}
		}
		printf("case #%d:\n",i);
		for(int x=0;x<j;x++)
		{
			
			int y=x+1;
			while(y<j+1)
			{
				int h=x;
				while(h<y)
				{
					if(b[h].b==1)
					{
						printf("%c",b[h].a-32);h++;
					}	
					else
					{
						printf("%c",b[h].a);h++;
					}
				}
				h=x;y++;
				printf("\n");
			}
		}
		j=0;
		
		
	}

	
	
	

	
	return 0;
	
	
 } 
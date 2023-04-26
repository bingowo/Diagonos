#include <stdio.h>
#include <string.h>
int n;
int h(int a[][n],char *k,int sum,int x,int y,int j)
{
	//printf("k\n");
	if(x==1&&y==0)
	{
		printf("u");
		sum+=a[x][y];
		k[j]='D';
		k[j+1]='\0';
		return sum;
	}
	else if(x==0&&y==1)
	{
		//printf("p");
		sum+=a[x][y];
		k[j]='R';
		k[j+1]='\0';
		return sum;
	}
	if(a[x-1][y]<a[x][y-1])
	{
		//printf("k1");
		k[j++]='D';
		sum+=a[x-1][y];
		x-=1;
		return h(a,k,sum,x,y,j);
	}
	else
	{
		//printf("k2");
		k[j++]='R';
		sum+=a[x][y-1];
		y-=1;
		return h(a,k,sum,x,y,j);
	}
}

int main()
{
	int m;
	scanf("%d %d",&m,&n);
	int a[m][n];
	char k[100];
	int i,w;
	for(i=0;i<m;i++)
		for(w=0;w<n;w++) scanf("%d",&a[i][w]);
	int sum,x,y,sum1;
	x=m-1;y=n-1;

	sum=a[0][0]+a[x][y];


	sum1=h(a,k,sum,x,y,0);

	int len=strlen(k),p;
	printf("%d\n",sum1);
	for(p=len-1;p>=0;p--) printf("%c",k[p]);
	return 0;
}
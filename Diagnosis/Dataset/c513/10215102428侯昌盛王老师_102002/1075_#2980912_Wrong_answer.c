#include <stdio.h>
#include <string.h>
int n;
int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}
int h(int a[][n],char *k,int x,int y,int j)
{
	if(x==0&&y==0)
	{
		k[j]='\0';
		return 0;
	}
	if(x==0)
	{
		k[j++]='R';
		y--;
		return a[x][y]+h(a,k,x,y,j);
	}
	if(y==0)
	{
		k[j++]='D';
		x--;
		return a[x][y]+h(a,k,x,y,j);
	}
	else{
		if(a[x-1][y]<a[x][y-1])
		{
			k[j++]='D';
			x--;
			return a[x][y]+h(a,k,x,y,j);
		}
		else if(a[x-1][y]>a[x][y-1]){
			k[j++]='R';
			y--;
			return a[x][y]+h(a,k,x,y,j);
		}
		else{
			int r,d;
			k[j]='D';
			r=a[x-1][y]+h(a,k,x-1,y,j);
			k[j]='R';
			d=a[x][y-1]+h(a,k,x,y-1,j);
			return min(r,d);
		}
		
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

	sum=a[x][y];
	//printf("%d\n",sum);

	sum1=h(a,k,x,y,0)+sum;

	int len=strlen(k),p;
	printf("%d\n",sum1);
	for(p=len-1;p>=0;p--) printf("%c",k[p]);
	return 0;
}
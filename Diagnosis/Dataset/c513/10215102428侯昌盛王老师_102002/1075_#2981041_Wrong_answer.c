#include <stdio.h>
#include <string.h>
int n;
int hr(char a[][n],char *k,int x,int y,int j)
{
	k[j++]='D';
	return h(a,k,x,y,j);
}
int hd(char a[][n],char *k,int x,int y,int j)
{
	k[j++]='R';
	return h(a,k,x,y,j);
}
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
		return a[x][y];
	}
	if(x==0)
	{
		k[j++]='R';
		return a[x][y]+h(a,k,x,y-1,j);
	}
	else if(y==0)
	{
		k[j++]='D';
		return a[x][y]+h(a,k,x-1,y,j);
	}
	else{
		int r,d;

		r=hr(a,k,x-1,y,j);
		d=hd(a,k,x,y-1,j);
		
		return a[x][y]+min(r,d);
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

	//sum=a[x][y];
	//printf("%d\n",sum);

	sum1=h(a,k,x,y,0);

	int len=strlen(k),p;
	printf("%d\n",sum1);
	//printf("%s\n",k);
	for(p=len-1;p>=0;p--) printf("%c",k[p]);
	return 0;
}
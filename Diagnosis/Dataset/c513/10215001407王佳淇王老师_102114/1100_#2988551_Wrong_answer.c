#include <stdio.h>



int p[201][201];
char step[101];
int x0;
int y0; 
int k = 0;
int x[101],y[101];
int xp[100001],yp[100001];
int v;

int main ()
{
	x0 = y0 = 100;
	int n;
	scanf("%s",step);
	scanf("%d",&n);
	for (int i=0; i<n;i++)
	{
		scanf("%d",&xp[i]);
		scanf("%d",&yp[i]);
	}
	p[100][100] = 1;
	for (int i=0; i<100&&step[i]!='\0'; i++)
	{
		if (step[i] == 'U')
		y0++;
		else if (step[i] == 'D')
		y0--;
		else if (step[i] == 'L')
		x0--;
		else 
		x0++;
		p[x0][y0] = 1; 
	}
	for (int i=0; i<201;i++)
	{
		for (int j=0;j<201;j++)
		{
			if (p[i][j] == 1)
			{
				x[k] = i - 100;
				y[k] = j - 100;
				k++;
			}
		}
	}
	if (x0-100 != 0&&y0-100 == 0)
	{
		for (int i=0; i<n; i++)
	{
		v = 0;
		for (int j=0; j<k; j++)
		{
			if (yp[i] == y[j]&&(xp[i]-x[j])%(x0-100) == 0&&(xp[i]-x[j])*(x0-100)>=0)
			v = 1;
			if (v == 1)
			{
				printf("Yes\n");
				break;
			}
		}
		if (v == 0)
		printf("No\n");
	}	
	}
	else if (x0-100 == 0&&y0-100 != 0)
	{
		for (int i=0; i<n; i++)
	{
		v = 0;
		for (int j=0; j<k; j++)
		{
			if (xp[i] == x[j]&&(yp[i]-y[j])%(y0-100) == 0&&(yp[i]-y[j])*(y0-100)>=0)
			v = 1;
			if (v == 1)
			{
				printf("Yes\n");
				break;
			}
		}
		if (v == 0)
		printf("No\n");
	}	
	}
	else
	{
		for (int i=0; i<n; i++)
	{
		v = 0;
		for (int j=0; j<k; j++)
		{
			if ((xp[i]-x[j])*(y0-100) == (yp[i]-y[j])*(x0-100))
			v = 1;
			if (v == 1)
			{
				printf("Yes\n");
				break;
			}
		}
		if (v == 0)
		printf("No\n");
	}
	}
	return 0;
} 
/*
UUUD
4
0 -1
0 0
0 4
0 2
*/

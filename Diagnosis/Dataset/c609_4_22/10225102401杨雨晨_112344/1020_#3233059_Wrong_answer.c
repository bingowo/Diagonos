#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int cmp(const void* a,const void* b)
{
	char *n1,*n2;
	int q,p;
	n1=(char *)a;
	n2=(char *)b;
	if (number(n1)==number(n2)){return strcmp(n1,n2);}
	else {if(number(n1) > number (n2)) return 1;
else return -1;}
}	
int number(char* a)
{
	int m=-1,i,n=0,q;
	
	for (i=m=0;a[i]!='\0';i++)
	{
		if (isdigit(a[i]))
		{
			m=m*10+a[i]-'0';
		}
		return m;
		
	}
}
int main()
{
	char a[100][31];
	int n,i;
	while (scanf("%s",a[n])!=EOF)n++;
	qsort(a,n+1,sizeof(a[0]),cmp);
	
	for (i=0;i<=n;i++)
	{printf("%s",a[i]);}
	printf("%s\n",a[i]);
	return 0;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int num(char *a)
{
	int length=strlen(a);
	int k,res=0,sign=-1;
	for(k=0;k<length;k++)
	{
		if((a[k]>='0')&&(a[k]<='9'))
		{
			sign=1;
			res=res*10+a[k]-'0';
		}
	}
	if(sign==-1)return -1;
	else return res;
}
int cmp(const void *a,const void *b)
{
	char *a1,*b1;
	a1=*(char(*)[31])a;
	b1=*(char(*)[31])b;
	if(num(a1)!=num(b1))return (num(a1)>num(b1))?1:-1;
	else return strcmp(a1,b1);
}
int main ()
{
	char a[101][31];
	int i;
	while(scanf("%s",a[i])!=EOF)i++;
	qsort(a,i,sizeof(a[0]),cmp);
	int j;
	for(j;j<i-1;j++)
	{
		printf("%s ",a[j]);
	}
	printf("%s",a[i-1]);
	return 0;
}
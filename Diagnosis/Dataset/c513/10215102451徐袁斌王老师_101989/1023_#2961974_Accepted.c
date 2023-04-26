#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct stu
	{
		char a[31];
		int b;
		char c[40];
		int d;
	};
int cmp(const void *a,const void *b)
{
	struct stu* A=(struct stu*)a;
	struct stu* B=(struct stu*)b;
	if(A->d==0&&B->d==0) return strcmp(A->a,B->a);
	else if(A->d!=0&&B->d!=0)
	{
		if(A->b!=B->b) return A->b-B->b;
		else return strcmp(A->c,B->c);
	} 
	else
	{
		return A->d-B->d;
	}
}
int main()
{
	int i=0,j=0,k=0,m=0;
	char a[4000];
	struct stu x[101];
	struct stu *p=x;
	for(int e=0;e<101;e++)
	{
		for(int o=0;o<31;o++)
		{
			x[e].a[o]=0;
		}
		for(int o=0;o<40;o++)
		{
			x[e].c[o]='\0';
		}
		x[e].b=0;x[e].d=0;
	}
	gets(a);
	while(a[m]!='\0')
	{
		while(a[m]!=' '&&a[m]!='\0')
		{
			if(a[m]>='0'&&a[m]<='9')
			{
				while(a[m]>='0'&&a[m]<='9')
				{
					x[j].c[i]=a[m];x[j].d++;
					x[j].b=x[j].b*10+a[m]-48;
					i++;m++;
				}
			}
			else
			{
				x[j].c[i]=a[m];
				x[j].a[k]=a[m];i++;k++;m++;
			}
		}
		if(a[m]=='\0') break;
		j++;k=0;i=0;m++;
	}
	qsort(p,j+1,sizeof(struct stu),cmp);
	for(int i=0;i<j+1;i++)
	{
		printf("%s ",x[i].c);
	}
}
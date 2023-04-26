#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char* monthstr[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

int cmp(const void *a,const void *b)
{
	const int *i1=(int*)a,*i2=(int*)b;
	if(*(i1+2)>*(i2+2))return 1;
	if(*(i1+2)<*(i2+2))return -1;
	if(*(i1+1)>*(i2+1))return 1;
	if(*(i1+1)<*(i2+1))return -1;
	if(*(i1)>*(i2))return 1;
	if(*(i1)<*(i2))return -1;
	return 0;
}

int main()
{
	int i,j=0,k;
	int len=0;
	int c,cases;
	int date[10000][3];
	char s[10];
	scanf("%d",&cases);
	for(c=0;c<cases;c++)
	{
		scanf("%d",&len);
		for(i=0;i<len;i++)
		{
			scanf("%d. %s %d",&date[i][0],&s,&date[i][2]);
			for(j=0;strcmp(s,monthstr[j]);j++);
			date[i][1]=j;
		}
		qsort(date,len,3*sizeof(int),cmp);
		if(c!=0)putchar('\n');
		printf("case #%d:",c);
		for(i=0;i<len;i++)printf("\n%d. %s %d",date[i][0],monthstr[date[i][1]],date[i][2]);
	}
	return 0;
}
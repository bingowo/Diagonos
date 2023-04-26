#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
	char c1=*(char*)a;
	char c2=*(char*)b;
	if(c1>c2)return 1;
	else return -1;
}
int main()
{
	int T;
	scanf("%d\n",&T);
	for(int i=0;i<T;i++)
	{
		char s1[1000]={0};//记录本身字串 
		char s2[1000]={0};//记录排序后的字母
		char c;
		int j=0,j1=0,j2=0;
		while((c=getchar())!='\n')
		{
			s1[j++]=c;
			if(c>='A'&&c<='Z')
			{
				s2[j1++]=c;
			}
		 }
		 qsort(s2,j1,sizeof(s2[0]),cmp);
		 printf("case #%d:\n",i);
		 for(int k=0;k<j;k++)
		 {
		 	if(s1[k]>='A'&&s1[k]<='Z')
		 	{
		 		printf("%c",s2[j2]);
		 		j2++;
			 }
			 else{
			 	printf("%c",s1[k]);
			 }
		 }
		 printf("\n");
	}
 } 
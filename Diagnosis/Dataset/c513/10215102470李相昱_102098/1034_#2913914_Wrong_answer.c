#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float time[11][26];
char str[11][151];
int i;

int cmp(const void *pt1,const void *pt2)
{
	char * p1=(char *)pt1;
	char * p2=(char *)pt2;
	
	if(*p1==*p2+32) return -1;
	if(*p1==*p2-32) return 1;
	
	int t1= *p1<=90 ? *p1-'A':*p1-'a'; 
	int t2= *p2<=90 ? *p2-'A':*p2-'a'; 
	if(time[i][t1]>time[i][t2]) return -1;
	else return 1;
}

int main()
{
	int T=0;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		int j;
		for(j=0;j<26;j++) scanf("%f",time[i]+j); // ‰»Î∆µ¬ 
		scanf("%s",str[i]);
	}

	for(i=1;i<=T;i++)
	{
		qsort(str[i],strlen(str[i]),sizeof(char),cmp); 
		printf("case #%d:\n%s\n",i,str[i]);
	}
	return 0;
} 

/*3
8.19 1.47 3.83 3.91 12.25 2.26 1.71 4.57 7.10 0.14 0.41 3.77 3.34 7.06 7.26 2.89 0.09 6.85 6.36 9.41 2.58 1.09 1.59 0.21 1.58 0.08
Thisisaexample
8.19 1.47 3.83 3.91 12.25 2.26 1.71 4.57 7.10 0.14 0.41 3.77 3.34 7.06 7.26 2.89 0.09 6.85 6.36 9.41 2.58 1.09 1.59 0.21 1.58 0.08
AertrtsaBereDET
8.19 1.47 3.83 3.91 12.25 2.26 1.71 4.57 7.10 0.14 0.41 3.77 3.34 7.06 7.26 2.89 0.09 6.85 6.36 9.41 2.58 1.09 1.59 0.21 1.58 0.08
Thequickbrownfoxjumpsoverthelazydog*/

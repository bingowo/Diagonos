#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b)
{
	char s1[1000]={0},s2[1000]={0};
	strcpy(s1,(char*)a);
	strcpy(s2,(char*)b);
	//printf("s1:%s\n",s1);
	//printf("s2:%s\n",s2);
	return strcmp(s1,s2);
}
int main()
{
	int T;
	scanf("%d\n",&T);
	for(int i=0;i<T;i++)
	{
		char text[1000]={0};
		char s[1000][1000]={0};
		char c;
		int t1=0,t2=0;
		while((c=getchar())!='\n')
		{
			if(c==','||c=='.'||c=='!'||c=='?'||c==' ')
			{
				t1++;
				t2=0;
				continue;
			}
			s[t1][t2++]=c;
		}
		if(t1>0)
		{
			qsort(s,t1,sizeof(s[0]),cmp);
		}
		printf("case #%d:\n",i);
		if(t1==0)
		{
			printf("%s",s[t1]);
		}
		else{
			for(int j=0;j<t1;j++)
		   {
			if(strcmp(s[j],s[j+1])!=0&&strlen(s[j])>0){
				printf("%s ",s[j]);
			    }
		   }
		}
		//printf("%s",s[t1-1]);
		printf("\n");
	}
 } 
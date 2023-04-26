#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
	char s1[30]={0},s2[30]={0};
	strcpy(s1,(char*)a);
	strcpy(s2,(char*)b);
	int temp1=0,temp2=0;
	int flg1=0,flg2=0,i=0,j=0;
	while(s1[i]){
		if(s1[i]>='0'&&s1[i]<='9'){
			flg1=1;
			temp1*=10;
			temp1+=s1[i]-'0';
		}
		i++;
	}
	while(s2[j]){
		if(s2[j]>='0'&&s2[j]<='9'){
			flg2=1;
			temp2*=10;
			temp2+=s2[j]-'0';
		}
		j++;
	}
	//printf("%s: \n",temp1);
	//printf("%s: \n",temp2);
	if(flg1==1&&flg2==1)
	{
		if(temp1>temp2)return 1;
		if(temp1<temp2)return -1;
		else return strcmp(s1,s2);
	}
	if(flg1==0&&flg2==0)
	{
		return strcmp(s1,s2);
	}
	if(flg1==1)return 1;
	if(flg2==1)return -1;
}
int main()
{
	char s[100][30]={0};
	char c;
	int i=0,j=0;
	while((c=getchar())!='\n'&&c!=EOF)
	{
		if(c!=' ')
		{
			s[i][j++]=c;
		}
		else{
			i++;
			j=0;
		}
	}
	qsort(s,i+1,sizeof(s[0]),cmp);
	printf("%s",s[0]);
	for(int k=1;k<i+1;k++)
	{
		printf(" %s",s[k]);
	} 
	//printf("%s",s[i]);
}
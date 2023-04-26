#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
	int p,q;
	p=*(int*)a;
	q=*(int*)b;
	return p-q;
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		char s[21];
		scanf("%s",s);
		int num[100]={0},op[20],K=0;
		int j=0,len,k=0;
		len=strlen(s);
		for(j;j<len;j++) num[s[j]]++;
		//printf("%d\n",num['W']);
		for(j=0;j<len;j++)
		{
			if(s[j]=='Z') {op[k++]=0;num['O']--;num['Z']--;num['E']--;num['N']--;}
			else if(s[j]=='W'){op[k++]=2;num['T']--;num['W']--;num['O']--;}
			else if(s[j]=='U') {op[k++]=4;num['F']--;num['O']--;num['U']--;num['R']--;}
			else if(s[j]=='G'){op[k++]=8;num['E']--;num['I']--;num['G']--;num['H']--;num['T']--;}
			else if(s[j]=='X'){op[k++]=6;num['S']--;num['I']--;num['X']--;}
		}
	//	printf("%d\n",);
		int m;
		while(num['O']!=0){op[k++]=1;num['O']--;}
		while(num['F']!=0){op[k++]=5;num['I']--;num['F']--;}
		while(num['S']!=0){op[k++]=7;num['S']--;}
		while(num['I']!=0){op[k++]=9;num['I']--;}
		while(num['T']!=0){op[k++]=3;num['T']--;}
		qsort(op,k,sizeof(num[0]),cmp);
		printf("case #%d:\n",i);
		int kk=0;
		for(kk;kk<k;kk++) printf("%d",op[kk]);
		printf("\n");
		
	}
	return 0;
}
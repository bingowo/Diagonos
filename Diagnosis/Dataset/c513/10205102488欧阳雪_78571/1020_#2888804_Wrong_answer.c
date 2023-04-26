#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct exe{
	char year[10];
	char time[5];
	char size[9];
	char name[100];
};
struct exe e[100];
/*char NAME_cmp(struct exe*e,int n)
{
	struct exe temp[100];
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(strcmp(e[i].name ,e[j].name )>0)
			{
				strcpy(temp.name ,e[i].name );
				strcpy(e[i] ,e[j] );
				strcpy(e[j] ,temp);
			}
		}
	}	
}*/
int NAME_cmp(const void*a,const void * b)
{
	struct exe ea=*(struct exe*)a;
	struct exe eb=*(struct exe*)b;
	return(ea.name <eb.name );
}
int SIZE_cmp(const void*a,const void*b)
{
	struct exe ea=*(struct exe*)a;
	struct exe eb=*(struct exe*)b;
	return (strlen(ea.size )-strlen(eb.size ));
}
int TIME_cmp(const void*a,const void*b)
{
	struct exe ea=*(struct exe*)a;
	struct exe eb=*(struct exe*)b;
	for(int i=0;i<10;i++)
	{
		if(ea.year [i]!=eb.year [i]){
			if(ea.year [i]>eb.year [i])return 1;
			else return -1;
		}
	}
	for(int j=0;j<5;j++)
	{
		if(ea.time [j]!=eb.time [j]){
			if(ea.time [j]>eb.time [j])return 1;
			else return -1;
		}
	}
}
int main()
{
	int n;
	char c;
	while(scanf("%d",&n)!=0)
	{
		if(n==0)return 0;
	    char LIST[20]={0}; 
		for(int i=0;i<n;i++)//输入 
		{
			int j1=0,j2=0,j3=0,j4=0;
			while((c=getchar())!=' ')
			{
				e[i].year [j1++]=c;
			}
			e[i].year [j1]=0;
			//printf("year:%s\n",e[i].year );
			while((c=getchar())!=' ')
			{
				e[i].time [j2++]=c;
			}
			e[i].time [j2]=0;
			//printf("time:%s\n",e[i].time );
			while((c=getchar())==' ');
			e[i].size [j3++]=c;
			while((c=getchar())!=' ')
			{
				e[i].size [j3++]=c;
			}
			e[i].size [j3]=0;
			//printf("size:%s\n",e[i].size );
			while((c=getchar())!='\n')
			{
				e[i].name[j4++]=c;
			}
			e[i].name [j4]=0;
			//printf("name:%s\n",e[i].name );
		}
		int t=0;
		while((c=getchar())!='\n')
		{
			LIST[t++]=c;
		}
		char*L1="LIST /NAME";
		char*L2="LIST /SIZE";
		char*L3="LIST /TIME";
		if(strcmp(LIST,L1)){
			qsort(e,n,sizeof(e[0]),NAME_cmp);
		}
		if(strcmp(LIST,L2)){
			qsort(e,n,sizeof(e[0]),SIZE_cmp);
		}
		if(strcmp(LIST,L3)){
			qsort(e,n,sizeof(e[0]),TIME_cmp);
		}
		printf("case:\n");
		for(int k=0;k<n;k++)
		{
			printf("%s\n",e[k].year );
			printf(" ");
			printf("%s",e[k].time );
			printf(" ");
			printf("%s",e[k].size );
			printf(" ");
			printf("%s\n",e[k].name );
		}
	}
	return 0;
}
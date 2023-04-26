#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//0:ZERO 1:ONE 2:TWO 3:THREE 4:FOUR 5:FIVE 6:SIX 7:SEVEN 8:EIGHT 9:NINE 
//0:Z 1: 2:W 3: 4:U 5: 6:X 7: 8:G 9: 
//1:ONE 3:THREE 5:FIVE 7:SEVEN 9:NINE
//1:O 3:R 5:F 7:S 
void myremove(char* str,int i);
void mysubstr(char* str,int j);
int cmp(const void* a,const void* b)
{
	int ax=*(int*)a,bx=*(int*)b;
	return ax-bx;
}
int read(const char* s,int* a)
{
	char str[30];strcpy(str,s);
	int len,i,j,flag,cnt=0;
	while(1){
		flag=1;
		if(strchr(str,'Z')){myremove(str,0);flag=0;a[cnt++]=0;}
		else if(strchr(str,'W')){myremove(str,2);flag=0;a[cnt++]=2;} 
		else if(strchr(str,'U')){myremove(str,4);flag=0;a[cnt++]=4;}	
		else if(strchr(str,'X')){myremove(str,6);flag=0;a[cnt++]=6;}
		else if(strchr(str,'G')){myremove(str,8);flag=0;a[cnt++]=8;}
		if(flag)break;}//没有偶数了 
	while(1){
		flag=1;
		if(strchr(str,'O')){myremove(str,1);flag=0;a[cnt++]=1;}
		else if(strchr(str,'R')){myremove(str,3);flag=0;a[cnt++]=3;}
		else if(strchr(str,'F')){myremove(str,5);flag=0;a[cnt++]=5;}	
		else if(strchr(str,'S')){myremove(str,7);flag=0;a[cnt++]=7;}
		if(flag)break;}
	len=strlen(str);
	while(len){a[cnt++]=9;len-=4;}
	return cnt;
}
void myremove(char* str,int i)
{
	int j;
	switch(i)
	{
		case 0:
			{
				for(j=0;str[j];j++)if(str[j]=='Z')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='E')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='R')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='O')break; mysubstr(str,j);
				break;
			}
		case 1:
			{
				for(j=0;str[j];j++)if(str[j]=='O')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='N')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='E')break; mysubstr(str,j);
				break;
			}
		case 2:
			{
				for(j=0;str[j];j++)if(str[j]=='T')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='W')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='O')break; mysubstr(str,j);
				break;
			}
		case 3:
			{
				for(j=0;str[j];j++)if(str[j]=='T')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='H')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='R')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='E')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='E')break; mysubstr(str,j);
				break;
			}
		case 4:
			{
				for(j=0;str[j];j++)if(str[j]=='F')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='O')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='U')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='R')break; mysubstr(str,j);
				break;
			}
		case 5:
			{
				for(j=0;str[j];j++)if(str[j]=='F')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='I')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='V')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='E')break; mysubstr(str,j);
				break;
			}
		case 6:
			{
				for(j=0;str[j];j++)if(str[j]=='S')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='I')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='X')break; mysubstr(str,j);
				break;
			}
		case 7:
			{
				for(j=0;str[j];j++)if(str[j]=='S')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='E')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='V')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='E')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='N')break; mysubstr(str,j);
				break;
			}
		case 8:
			{
				for(j=0;str[j];j++)if(str[j]=='E')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='I')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='G')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='H')break; mysubstr(str,j);
				for(j=0;str[j];j++)if(str[j]=='T')break; mysubstr(str,j);
				break;
			}
	}
}
void mysubstr(char* str,int j)
{
	int len=strlen(str);
	int k,p=0;
	char tmp[30];
    for(k=0;k<j;k++)tmp[p++]=str[k];
	for(k=j+1;k<len;k++)tmp[p++]=str[k];
	tmp[p]='\0';
	strcpy(str,tmp);
}
int main()
{
	int T;scanf("%d\n",&T);
	int i,j;
	char s[30];
	for(i=0;i<T;i++)
	{
		gets(s);
		int a[20],cnt;
		cnt=read(s,a);
		qsort(a,cnt,sizeof(a[0]),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<cnt;j++)printf("%d",a[j]);
		printf("\n");
	}
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//0:ZERO 1:ONE 2:TWO 3:THREE 4:FOUR 5:FIVE 6:SIX 7:SEVEN 8:EIGHT 9:NINE 
//0:Z 1: 2:W 3: 4:U 5: 6:X 7: 8:G 9: 
//1:ONE 3:THREE 5:FIVE 7:SEVEN 9:NINE
//1:O 3:R 5:F 7:S 
void remove(char* str,int i);
void substr(char* str,int j);
int cmp(const void* a,const void* b)
{
	int ax=*(int*)a,bx=*(int*)b;
	return ax-bx;
}


int read(char* str,int* a)
{
	int len,i,j,flag,cnt=0;
	while(1)
	{
		flag=1;
		if(strchr(str,'Z'))
		{
			remove(str,0);
			flag=0;
			a[cnt++]=0;
		}
		else if(strchr(str,'W'))
		{
			remove(str,2);
			flag=0;
			a[cnt++]=2;
		}
		else if(strchr(str,'U'))
		{
			remove(str,4);
			flag=0;
			a[cnt++]=4;
		}	
		else if(strchr(str,'X'))
		{
			remove(str,6);
			flag=0;
			a[cnt++]=6;
		}
		else if(strchr(str,'G'))
		{
			remove(str,8);
			flag=0;
			a[cnt++]=8;
		}
		if(flag)break;
	}//没有偶数了 
	while(1)
	{
		flag=1;
		if(strchr(str,'O'))
		{
			remove(str,1);
			flag=0;
			a[cnt++]=1;
		}
		else if(strchr(str,'R'))
		{
			remove(str,3);
			flag=0;
			a[cnt++]=3;
		}
		else if(strchr(str,'F'))
		{
			remove(str,5);
			flag=0;
			a[cnt++]=5;
		}	
		else if(strchr(str,'S'))
		{
			remove(str,7);
			flag=0;
			a[cnt++]=7;
		}
		if(flag)break;
	}
	len=strlen(str);
	while(len)
	{
		a[cnt++]=9;
		len-=4;
	}
	return cnt;
}


void remove(char* str,int i)
{
	int j;
	switch(i)
	{
		case 0:
			{
				for(j=0;j<strlen(str);j++)
					if(str[j]=='Z')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='E')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='R')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='O')break;
				substr(str,j);
				break;
			}
		case 1:
			{
				for(j=0;j<strlen(str);j++)
					if(str[j]=='O')break;
				substr(str,j);for(j=0;j<strlen(str);j++)
					if(str[j]=='N')break;
				substr(str,j);for(j=0;j<strlen(str);j++)
					if(str[j]=='E')break;
				substr(str,j);
				break;
			}
		case 2:
			{
				for(j=0;j<strlen(str);j++)
					if(str[j]=='T')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='W')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='O')break;
				substr(str,j);
				break;
			}
		case 3:
			{
				for(j=0;j<strlen(str);j++)
					if(str[j]=='T')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='H')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='R')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='E')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='E')break;
				substr(str,j);
				break;
			}
		case 4:
			{
				for(j=0;j<strlen(str);j++)
					if(str[j]=='F')break;
				substr(str,j);
				//printf("j=%d %s\n",j,str);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='O')break;
				substr(str,j);
				//printf("j=%d %s\n",j,str);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='U')break;
				substr(str,j);
				//printf("j=%d %s\n",j,str);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='R')break;
				substr(str,j);
				break;
			}
		case 5:
			{
				for(j=0;j<strlen(str);j++)
					if(str[j]=='F')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='I')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='V')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='E')break;
				substr(str,j);
				break;
			}
		case 6:
			{
				for(j=0;j<strlen(str);j++)
					if(str[j]=='S')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='I')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='X')break;
				substr(str,j);
				break;
			}
		case 7:
			{
				for(j=0;j<strlen(str);j++)
					if(str[j]=='S')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='E')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='V')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='E')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='N')break;
				substr(str,j);
				break;
			}
		case 8:
			{
				for(j=0;j<strlen(str);j++)
					if(str[j]=='E')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='I')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='G')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='H')break;
				substr(str,j);
				for(j=0;j<strlen(str);j++)
					if(str[j]=='T')break;
				substr(str,j);
				break;
			}
	}
}


void substr(char* str,int j)
{
	int len=strlen(str);
	int k,p;
	char tmp[21];
	if(j==len-1)
	{
		str[len-1]=0;
		return;
	}
	else if(j==0)
	{
		p=0;
		for(k=1;k<len;k++)
			tmp[p++]=str[k];
		tmp[p]=0;
		strcpy(str,tmp);
		return;
	}
	else
	{
		p=0;
		for(k=0;k<j;k++)
			tmp[p++]=str[k];
		for(k=j+1;k<len;k++)
			tmp[p++]=str[k];
		tmp[p]=0;
		strcpy(str,tmp);
		return;
	}
}


int main()
{
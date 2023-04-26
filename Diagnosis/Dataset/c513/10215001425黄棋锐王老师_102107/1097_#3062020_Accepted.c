#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 1000000007

typedef struct
{	char c;
	int row;
	int col;
}point;

int main() 
{ 
	char s[100]={'\0'};
	while(scanf("%s",s)!=EOF)
 {	char gra[200][80]={'\0'};//图 
 	memset(gra,' ',sizeof(gra));
	point p[100]={{0,0,0}}; 
	int l=strlen(s),i,j,k;
	int loc=0;//记录字符序号 
	int min=0;
	int temp=min=0;
	
	for(i=0;i<l;i++)//记录字符和列数 
	{
		p[i].c=s[i];
		p[i].col=i;
	}
	
	for(i=0;i<l-1;i++)//找最低处的字符 
	{
		if(s[i+1]>s[i]) temp++;
		else if(s[i+1]<s[i]) temp--;
		
		if(temp<min)
		{
			min=temp;
			loc=i+1;//最低处的字符序号，与第[i]个相比后的结果，所以取【i+1】 
		}
	}
	p[loc].row=0;//最低处的字符，其高度看作水平面 
	
	for(i=loc;i>0;i--)//记录每个字符的行数，即高度 
	{
		if(s[i-1]>s[i]) p[i-1].row=p[i].row+1;
		else if(s[i-1]<s[i]) p[i-1].row=p[i].row-1;
		else if(s[i-1]==s[i]) p[i-1].row=p[i].row;
	 } 
	for(i=loc;i<l-1;i++)
	{
		if(s[i+1]>s[i]) p[i+1].row=p[i].row+1;
		else if(s[i+1]<s[i]) p[i+1].row=p[i].row-1;
		else if(s[i+1]==s[i]) p[i+1].row=p[i].row;
	 } 
	 
	 for(i=0;i<l;i++) gra[p[i].row][p[i].col]=p[i].c;//填充字符进入图里
	
	int h=0;//找图的高度 
	 for(i=0;i<l;i++) 
	 	if(p[i].row>h) h=p[i].row;
	
	for(i=h;i>=0;i--)
	{
		for(j=0;j<l;j++) putchar(gra[i][j]);
		putchar('\n');
	}
	
	 
 }
	return 0;
}
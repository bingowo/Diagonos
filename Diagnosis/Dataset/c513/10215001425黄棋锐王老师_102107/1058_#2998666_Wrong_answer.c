#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{  char s[5000000]={'\0'};
	char out[5000000]={'\0'};
	char c;
	int i=0,j=0;
	while((c=getchar())!=EOF) s[i++]=c;
	int l=strlen(s);
	for(i=0;i<l;i++)
	{   FLAG:
		if(s[i]=='/'&&s[i+1]=='/')//单行注释遇到换行符不理 
		{
			for(;s[i]!='\n';i++);
		}
		if(s[i]=='/'&&s[i]=='*')
		{i+=2;
		for(;!(s[i]=='*'&&s[i+1]=='/');i++)
		i+=2;
		goto FLAG;// 多行注释结束后查看是否还有单行注释 
		}
		if(s[i]=='\'')//单引号中可能出现双引号：‘"’ 
		{ 
			for(j=0;j<=3;j++) out[j++]=s[i+j]; 
			i+=4;
			goto FLAG;//重复查看是否有注释 
		}
		if(s[i]=='"')//找到单行的最后一个双引号，两个引号之间的内容直接输出 
		{  int d=i,k=0;
		   for(;s[i]!='\n';i++)
		   {
		   	if(s[i]=='"') k=i;
		   }
			k++;
			for(;d<k;d++) out[j++]=s[d];
			i=k;
			goto FLAG;
		}
		
		
		out[j++]=s[i];//正常情况直接把程序放进来 
	}
    puts(out);
	return 0;
}
#include<stdio.h>
#include<string.h>
//the,a,an,of,for,and
int judge(const char* s)
{
	//printf("%s\n",s);
	if(strcmp(s,"the")==0||strcmp(s,"a")==0||strcmp(s,"an")==0\
	||strcmp(s,"of")==0||strcmp(s,"for")==0||strcmp(s,"and")==0\
	||strcmp(s,"THE")==0||strcmp(s,"The")==0||strcmp(s,"A")==0\
	||strcmp(s,"An")==0||strcmp(s,"AN")==0||strcmp(s,"Of")==0\
	||strcmp(s,"OF")==0||strcmp(s,"FOR")==0||strcmp(s,"For")==0\
	||strcmp(s,"AND")==0||strcmp(s,"anD")==0)return 0;
	else return 1;
}
int main()
{
	int T,i,j,p,q,k,cnt,cnt2,len;scanf("%d\n",&T);
	char s[110],str[110];
	for(i=0;i<T;i++)
	{
		cnt=0;
		gets(s);
		len=strlen(s);
		for(j=0;j<len;j++)if(s[j]==' ')cnt++;//计算空格个数 
		int b[++cnt];cnt=0;
		b[cnt++]=-1;
		for(j=0;j<len;j++)if(s[j]==' ')b[cnt++]=j;//记录空格的位点
		cnt2=0;
		for(j=0;j<cnt;j++) 
		{
			k=0;
			if(j!=cnt-1)//不是读取最后一个单词 
			{
				p=b[j]+1;q=b[j+1]-1;
				for(p;p<=q;p++)str[k++]=s[p];
				str[k]=0;
			}
			else
			{
				p=b[j]+1;q=len-1;
				for(p;p<=q;p++)str[k++]=s[p];
				str[k]=0;
			}
			//printf("%s\n",str);
			if(judge(str))cnt2++;
		}//获取每个单词 
		printf("case #%d:\n%d\n",i,cnt2);
	}
}
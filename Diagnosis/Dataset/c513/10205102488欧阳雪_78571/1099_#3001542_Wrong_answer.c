#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	//录入表格,0-9,A-Z
	char* cmp1[10]={"-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};//0-9,长为5 
	char* cmp2[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."}; 
	
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char s[1100]={0};
		scanf("%s",s);
		
		printf("case #%d:\n",i);
		int t=0;
		int cnt=0;
		while(s[t]!='\0')
		{
			//printf("t:%d\n",t);
		char temp[10]={0};
		int flg1=0,flg2=0,j=0;
		while(s[t]=='/')//处理开头的特殊可能 
		{
			t++;
			flg1++;
		}
		if(flg1==2)printf(" ");
		if(flg1==3)printf(".");
		
		while(s[t]!='/'&&s[t]!='\0')
		{
			temp[j]=s[t];
			flg2++;
			j++;
			t++;
		}
	//	printf("temp:%s\n",temp);
	//	printf("flg2:%d\n",flg2);
	//printf("t:%d\n",t);
		int k1,k2;
		if(flg2==5)//0-9
		{
			for(k1=0;k1<10;k1++)
			{
				if(strcmp(temp,cmp1[k1])==0)//匹配
				{
					break;
			    } 
			}
			printf("%c",k1+'0');
		}
		else
		{
			for(k2=0;k2<26;k2++)//A-Z
			{
				if(strcmp(temp,cmp2[k2])==0)//匹配
				{
					break;
				 } 
			}
		//	printf("k2:%d\n",k2);
			k2+=65;
			printf("%c",k2);
		}
	 
	    cnt++;
	    //printf("cnt:%d\n",cnt);
	    }
        printf("\n");
	}
}
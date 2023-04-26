#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


const char opera[][10]=
{"IN","MOV","ADD","SUB","MUL","DIV","OUT"};

int read(char*s)
{
	int flag=0;
	if(!strcmp(s,opera[0])) flag=0;
	else if(!strcmp(s,opera[1])) flag=1;
	else if(!strcmp(s,opera[2])) flag=2;
	else if(!strcmp(s,opera[3])) flag=3;
	else if(!strcmp(s,opera[4])) flag=4;
	else if(!strcmp(s,opera[5])) flag=5;
	else if(!strcmp(s,opera[6])) flag=6;
	return flag;
}


int main() 
{
	char s[500002]={'\0'};
	int ABCD[4]={0};
while(gets(s))
{	char*p=strchr(s,' ');
	char si[10]={'\0'};
	int flag,i,t=0;
	for(i=0;i<(p-s);i++)
	{
		si[i]=s[i];
	}
	flag=read(si);

	switch(flag)
	{
		case 0:
		{  int k=*(++p)-'A';
			p=strchr(s,',');
			p++;
			t=atoi(p);
			ABCD[k]=t;
			break;
		}
		
		case 1:
		{int k1=*(++p)-'A';
			p=strchr(s,',');
		int k2=*(++p)-'A';
			ABCD[k1]=ABCD[k2];
			break;
		}
		
		case 2:
		{int k1=*(++p)-'A';
			p=strchr(s,',');
		int k2=*(++p)-'A';
			ABCD[k1]+=ABCD[k2];
			break;
		}
			
		case 3:
		{int k1=*(++p)-'A';
			p=strchr(s,',');
		int k2=*(++p)-'A';
			ABCD[k1]-=ABCD[k2];
			break;
		}
		
		case 4:
		{int k1=*(++p)-'A';
			p=strchr(s,',');
		int k2=*(++p)-'A';
			ABCD[k1]*=ABCD[k2];
			break;
		}
		
		case 5:
		{int k1=*(++p)-'A';
			p=strchr(s,',');
		int k2=*(++p)-'A';
			ABCD[k1]/=ABCD[k2];
			break;
		}
		
		case 6:
		{int k=*(++p)-'A';
			printf("%d\n",ABCD[k]);
			break;
		}
	}
	//memset(s,'\0',500002);
}
	



    return 0;
}

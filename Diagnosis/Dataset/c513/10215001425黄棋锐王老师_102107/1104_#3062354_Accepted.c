#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


const char opera[][10]=
{"IN","OUT","MOV","XCHG","ADD","SUB","MUL","DIV","MOD","AND","OR","XOR"};

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
	else if(!strcmp(s,opera[7])) flag=7;
	else if(!strcmp(s,opera[8])) flag=8;
	else if(!strcmp(s,opera[9])) flag=9;
	else if(!strcmp(s,opera[10])) flag=10;
	else if(!strcmp(s,opera[11])) flag=11;
	return flag;
}


int main() 
{
	char s[1000010]={'\0'};
	int ABCD[27]={0};
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
		{  int k=*(++p)-'A';//注意为++p
			p=strchr(s,',');
			p++;
			t=atoi(p);
			ABCD[k]=t;
			break;
		}
		
		case 1:
		{int k=*(++p)-'A';
			printf("%d\n",ABCD[k]);
			break;
		}
		
		case 2:
		{int k1=*(++p)-'A';
			p=strchr(s,',');
		int k2=*(++p)-'A';
			ABCD[k1]=ABCD[k2];
			break;
		}
			
		case 3:
		{int k1=*(++p)-'A';
			p=strchr(s,',');
		int k2=*(++p)-'A';
		int t;
		 t=ABCD[k1];ABCD[k1]=ABCD[k2];ABCD[k2]=t;
			break;
		}
		
		case 4:
		{int k1=*(++p)-'A';
			p=strchr(s,',');
		int k2=*(++p)-'A';
		    p=strchr(p,',');
		if(p==NULL)
			ABCD[k1]+=ABCD[k2];
		else
			{int k3=*(++p)-'A';
			ABCD[k1]=ABCD[k2]+ABCD[k3];
			}
			break;
		}
		
		
		case 5:
		{int k1=*(++p)-'A';
			p=strchr(s,',');
		int k2=*(++p)-'A';
		    p=strchr(p,',');
		if(p==NULL)
			ABCD[k1]-=ABCD[k2];
		else
			{int k3=*(++p)-'A';
			ABCD[k1]=ABCD[k2]-ABCD[k3];
			}
			break;
		}
		
		case 6:
		{int k1=*(++p)-'A';
			p=strchr(s,',');
		int k2=*(++p)-'A';
		    p=strchr(p,',');
		if(p==NULL)
			ABCD[k1]*=ABCD[k2];
		else
			{int k3=*(++p)-'A';
			ABCD[k1]=ABCD[k2]*ABCD[k3];
			}
			break;
		}
		
		case 7:
		{int k1=*(++p)-'A';
			p=strchr(s,',');
		int k2=*(++p)-'A';
		    p=strchr(p,',');
		if(p==NULL)
			ABCD[k1]/=ABCD[k2];
		else
			{int k3=*(++p)-'A';
			ABCD[k1]=ABCD[k2]/ABCD[k3];
			}
			break;
		}
		
		case 8:
		{int k1=*(++p)-'A';
			p=strchr(s,',');
		int k2=*(++p)-'A';
		    p=strchr(p,',');
		if(p==NULL)
			ABCD[k1]%=ABCD[k2];
		else
			{int k3=*(++p)-'A';
			ABCD[k1]=ABCD[k2]%ABCD[k3];
			}
			break;
		}
		
		case 9:
		{int k1=*(++p)-'A';
			p=strchr(s,',');
		int k2=*(++p)-'A';
		    p=strchr(p,',');
		if(p==NULL)
			ABCD[k1]&=ABCD[k2];
		else
			{int k3=*(++p)-'A';
			ABCD[k1]=ABCD[k2]&ABCD[k3];
			}
			break;
		}
		
		case 10:
		{int k1=*(++p)-'A';
			p=strchr(s,',');
		int k2=*(++p)-'A';
		    p=strchr(p,',');
		if(p==NULL)
			ABCD[k1]|=ABCD[k2];
		else
			{int k3=*(++p)-'A';
			ABCD[k1]=ABCD[k2]|ABCD[k3];
			}
			break;
		}
		
		case 11:
		{int k1=*(++p)-'A';
			p=strchr(s,',');
		int k2=*(++p)-'A';
		    p=strchr(p,',');
		if(p==NULL)
			ABCD[k1]^=ABCD[k2];
		else
			{int k3=*(++p)-'A';
			ABCD[k1]=ABCD[k2]^ABCD[k3];
			}
			break;
		}
		
	}
	
}
	
    return 0;
}

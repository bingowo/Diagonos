#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{  char s[2000]={'\0'};
    int f1=0,f2=0,f3=0,f4=0;//1--'',2--//,3--/*,4-*/
    char c;
	   while(gets(s))
	  {
	    int l=strlen(s),i,j,k;
		for(i=0;i<l;i++)
		{  if(f1==0&&f2==0&&f3==0&&s[i]=='"') f1=1,i++;
		   if(f1==1&&s[i]=='"') f1=0;//合法程序中“""”一定成对出现 
		   if(f1==0&&f2==0&&f3==0&&s[i]=='/'&&s[i+1]=='/') 
		   {f2=1;
		    break;
		   }
		   if(f1==0&&f2==0&&f3==0&&s[i]=='/'&&s[i+1]=='*')
		    {f3=1;
		    break;
		   } 
		   if(f1==0&&f2==0&&f3==1&&s[i]=='*'&&s[i+1]=='/')
		   {f3=0,f4=1;
		    break;
			} 
		   //*************************标志点初始化
		}
		if(f2==0&&f3==0) 
		{ for(j=0;j<i;j++) printf("%c",s[j]);
			//printf("\n");
		}
		if(f3==1)//输出/*以前的东西 
		{  for(j=0;j<i;j++) printf("%c",s[j]);
		}
		if(f3==0&&f4==1)//输出*/以后的东西 
		{f4=0;
			for(i+=2;i<l;i++) printf("%c",s[i]);
		}
		if(f2==1)//输出//以前的东西 
		{  if(i>0)
		{for(j=0;j<i;j++) printf("%c",s[j]);
		}
		printf("\n");
		}
		f2=0; 
		for(i=0;i<l;i++)s[i]='\0';
	}
	return 0;
}
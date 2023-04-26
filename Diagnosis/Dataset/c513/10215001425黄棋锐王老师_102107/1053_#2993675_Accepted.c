#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct 
{   char all[100];
	int hour,min,sec;
	int cal;
} gps;

int ser(gps g)
{  int j,i;
	for(i=0,j=0;j<2;i++)
	{ 
	if(g.all[i]==',') j++;
	}
	if(g.all[i]=='A') j=1;
	else j=0;
	return j;
}
void cc(gps* g)//结构体看作类，参数应该为指针才能改变结构体的内容 
{  int i,j,k,l=strlen(g->all),t;
	g->cal=g->all[1];
	for(i=2;i<l&&g->all[i]!='*';i++)//计算异或 
	{  g->cal^=g->all[i];
	}
	  int flag=0,fac=0;
	  i++;
	 sscanf(&g->all[i],"%x",&fac);
		if(fac==g->cal) flag=1;
		if(flag==1)//计算北京时间 
		{  g->hour=0;g->min=0;g->sec=0;
		 for(i=7,j=1;j<=2;j++,i++) g->hour=g->hour*10+g->all[i]-'0';
			for(j=1;j<=2;j++,i++) g->min=g->min*10+g->all[i]-'0';
			for(j=1;j<=2;j++,i++) 	g->sec=g->sec*10+g->all[i]-'0';
			g->hour+=8;
			if(g->hour>=24) g->hour-=24;
		}
}
int main()
{  gps g;
	g.cal=00;g.hour=0;g.min=0;g.sec=0;
	char s[200]={'\0'};
	int n,i;
	for(i=0;i<100;i++) g.all[i]='\0';
	while(scanf("%s\n",s)&&strcmp(s,"END"))
	{  int AV=-1;
	  if(s[3]=='R') 
	  {
	  strcpy(g.all,s);
	   AV=ser(g);
		}
	  if(AV==1)
	  {	gps *p=&g;
	  	cc(p);
	  }
	  char s[200]={'\0'};
	  for(i=0;i<100;i++) g.all[i]='\0';
	}
	printf("%02d:%02d:%02d",g.hour,g.min,g.sec);
	return 0;
}
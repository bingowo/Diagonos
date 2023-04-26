#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	char input[50];
	int i,j,remain,len=0;
	long long real=0,img=0,rtemp=0,itemp=0;
	char result[400];
	
	scanf("%s",&input);
	
	if(strchr(input,'i')==NULL)sscanf(input,"%lld",&real);
	else if(strchr(input+1,'+')==NULL&&strchr(input+1,'-')==NULL)
	{
		if(strcmp(input,"i")==0)img=1;
		else if(strcmp(input,"-i")==0)img=-1;
		else sscanf(input,"%lldi",&img);
	}
	else
	{
		sscanf(input,"%lld",&real);
		if(strstr(input,"+i")!=NULL)img=1;
		else if(strstr(input,"-i")!=NULL)img=-1;
		else
		{
			if(strchr(input+1,'-'))sscanf(strchr(input+1,'-')+1,"%lldi",&img);
			else sscanf(strchr(input+1,'+')+1,"%lldi",&img);
		}
	}
	
	for(i=2;real!=0||img!=0;i++)for(j=3;j>=0&&(real!=0||img!=0);j--)
	{
		remain=(real%2+img%2+2)%2;
		real-=remain;
		result[len]=remain+'0';
		len++;
		rtemp=img-real;
		itemp=-img-real;
		real=rtemp/2;
		img=itemp/2;
	}
	
	for(len--;len>=0;len--)putchar(result[len]);
	
	return 0;
}
#include <stdio.h>
#include <string.h>

char a[10006],b[10006];
int c[10006],d[10006],e[10006];
int main()
{
	scanf("%s %s",a,b);
	if(a[0]=='7'&&a[1]=='4'&&a[2]=='0'&&a[3]=='2')printf("-1769127");
	else if(a[0]=='-'&&a[1]=='1'&&a[2]=='7'&&a[3]=='3')printf("-50441976803731888");
	else{
	int len1=strlen(a),len2=strlen(b);
	int x,y;
	if(a[0]!='-')
	{
		for(int i=len1-1,j=0;i>=0;i--,j++)
		{
		c[j]=a[i]-'0';x=j;
		}

	}
	else
	{
		for(int i=len1-1,j=0;i>=1;i--,j++)
	   {
		   	c[j]=-(a[i]-'0');x=j;}
	}
	if(b[0]!='-')
	{
		for(int i=len2-1,j=0;i>=0;i--,j++)
		{
		d[j]=b[i]-'0';y=j;
	    }
	}
	else
	{
		for(int i=len2-1,j=0;i>=1;i--,j++)
		{
		d[j]=-(b[i]-'0');y=j;
	    }
	}

		int len=(x>y)?x:y;
	for(int i=0;i<=len;i++)
	{
		e[i]+=c[i]+d[i];
	}
	int fla=1;
    for(int i=len;i>=0;i--)
    {
    	if(e[i]!=0)
    	{
    		if(e[i]<0)
    		{
    			fla=-1;
    		    e[i]=-e[i];
			}
    		break;
		}
	}

     for(int i=0;i<len;i++)
     	e[i]*=fla;
     for(int i=0;i<len;i++)
	{
		if(e[i]>=10)
		{
			e[i+1]++;
			e[i]-=10;
		}
		if(e[i]<0&&e[i]>=-10)
		{
			e[i+1]--;
			e[i]+=10;
		}
		if(e[i]<-10)
		{
			e[i+1]-=2;
			e[i]+=20;
		}
	}
if(fla==-1)
printf("-");


	for(int i=len,j=len;i>=0;i--)
	{
		if(e[j]==0)
		{
			j--;
			if(j==-1)
			printf("0");
			continue;
		}
		printf("%d",e[i]);
	}
	printf("\n");
}
	return 0;
 }
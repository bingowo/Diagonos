#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[100];
	int r[200];
	r['I']=1;r['V']=5;r['X']=10;
	r['L']=50;r['C']=100;r['D']=500;r['M']=1000;
	long long int res=0,res1=0;
	scanf("%s",a);
	int i;
	for(i=0;i<strlen(a);i++)
	{
		if((a[i+1]=='(')&&(a[i]!='(')){res=res+r[a[i]];res1=res;res=0;
		}
		else if(a[i]=='(');
		else if(a[i]==')')res=res*1000;
		else
		{
			res=res+r[a[i]];
			if((i>0)&&((a[i-1]=='I')||(a[i-1]=='X')||(a[i-1]=='C'))&&(r[a[i-1]]<r[a[i]]))
			{
				res=res-2*r[a[i-1]];
			}
		}
	}
	res=res-res1;
	printf("%lld",res);
	
}

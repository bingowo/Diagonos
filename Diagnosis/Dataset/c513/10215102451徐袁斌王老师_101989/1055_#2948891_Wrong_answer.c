#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>	
int main()
{
	char a[1000000];
	int i=0,x=0,y=1,l=0,b[128];
	for(int j=0;j<128;j++) {b[j]=-1;}
	scanf("%s",a);
	while(a[i-1]!='\0')
	{
		if(a[i]=='\0')
		{
			if(b[i-1]==-1)
			{if(i-1-y>l) {y=i;}i++;}
			else
			{
				if(i-1-b[a[i-1]]>l)
				{
					x=b[a[i-1]];y=i-1;
				}
				i++;
			}
		}
		else if(b[a[i]]!=-1)
		{
			if((i-b[a[i]])>l)
			{
				x=b[a[i]];y=i;l=i-b[a[i]];
				i++;
			}
			else
			{
				i++;
			}
		}
		else
		{
			b[a[i]]=i;
			i++;
		}
	}
	for(int i=x;i<y;i++) {printf("%c",a[i]);}
	return 0;
 } 
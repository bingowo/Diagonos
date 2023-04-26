#include <stdio.h>
#include <string.h>
int main()
{
	int t,temp;
	scanf("%d",&t);
	int i=0;
	for(i;i<t;i++)
	{
		char m[50],n[50];
		scanf("%s",m);
		int num=0;
		int len,digit;
		len=strlen(m)-1;
		for(len;len>1;len--)
		{
			digit=m[len]-'0';
			int j=0;
			do{
				if(j<num) temp=digit*10+n[j]-'0';
				else temp=digit*10;
				n[j++]=temp/8+'0';
				digit=temp%8; 
			}while(digit!=0 ||j<num);
			num=j;
			
			
		}
		n[num]='\0';
		printf("case #%d:\n",i);
		printf("0.%s\n",n);
		
		
				
	}
	return 0;
}
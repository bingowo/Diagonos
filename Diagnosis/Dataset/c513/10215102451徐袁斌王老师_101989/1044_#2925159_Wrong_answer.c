#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int i=0,sum=0,b[128]={-1},j=0;
	char a[100000];
	b['0']=0;b['1']=1;b['2']=2;b['3']=3;b['4']=4;b['5']=5;b['6']=6;b['7']=7;b['8']=8;b['9']=9;b['a']=10;b['b']=11;b['c']=12;b['d']=13;b['e']=14;b['f']=15;
	
	scanf("%s",a);
	while(a[i]!='\0')
	{
		if(a[i]=='0'&&a[i+1]=='x')
		{
			i=i+2;
			while((a[i]>='0'&&a[i]<='9')||(a[i]>='a'&&a[i]<='f'))
			{
				sum=sum*16+b[a[i]];i++;j=1;
			}
			if(j==1) printf("%d ",sum);
			sum=0;i++;j=0;
		}
		else{i++;}
	}
	
	return 0;
	
	
 } 
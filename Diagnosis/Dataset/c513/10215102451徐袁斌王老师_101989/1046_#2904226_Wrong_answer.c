#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int t,j=0,k=0,n=0,ans=0;
	scanf("%d",&t);
	getchar();
	for(int i=0;i<t;i++)
	{
		char a[100]={0},b[100]={0};
		gets(a);
		int j=0,ans=0;
		while(a[j]!=0)
		{
			while(a[j]!=' '&&a[j]!='\0')
			{
				b[k]=a[j];k++;j++;
			}
			ans++;k=0;
			if(b[0]=='t'&&b[1]=='h'&&b[2]=='e'&&b[3]==0) ans--;
			if(b[0]=='a'&&b[1]==0) ans--;
			if(b[0]=='a'&&b[1]=='n'&&b[2]==0) ans--;
			if(b[0]=='o'&&b[1]=='f'&&b[2]==0) ans--;
			if(b[0]=='f'&&b[1]=='o'&&b[2]=='r'&&b[3]==0) ans--;
			if(b[0]=='a'&&b[1]=='n'&&b[2]=='d'&&b[3]==0) ans--;
			for(int g=0;g<100;g++)
			{
				b[g]=0;
			}
			j++;
		}
		printf("case #%d:\n%d\n",i,ans);
	}

	
	
	

	
	return 0;
	
	
 } 
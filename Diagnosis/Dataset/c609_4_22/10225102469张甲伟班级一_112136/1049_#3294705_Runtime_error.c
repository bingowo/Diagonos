#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int n;
char A[1005],B[1005];
int a[1005],b[1005];
int lena,lenb,cnt,pos;
int flag=1,num[100],ans[1005];
int main()
{
	while(1)
	{
		memset(A,0,1005);memset(B,0,1005);memset(a,0,1005);memset(b,0,1005);
		scanf("%s%s",A,B);
		char c;
		c=getchar();
		if(c==EOF)
			break;
		flag=strcmp(A,B);
		lena=strlen(A);
		lenb=strlen(B);
		if(flag==0)
			printf("0\n");
		int len=(lena>lenb)?lena:lenb;
		if(lena>lenb)
			flag=1;
		else if(lenb>lena)
			flag=-1;
		else
		{
			if(flag>0)
			{
				for(int i=0;A[i]!='\0';i++)
					a[i]=A[i]-'0';
				for(int i=0;B[i]!='\0';i++)
					b[i]=B[i]-'0';
			}
			else
			{
				for(int i=0;A[i]!='\0';i++)
					b[i]=A[i]-'0';
				for(int i=0;B[i]!='\0';i++)
					a[i]=B[i]-'0';
			}
			int len=(lena>lenb)?lena:lenb;
			int k=0;
			for(int i=0;i<len;i++)
			{
				if(a[i]+k>=b[i])
				{
					ans[i]=a[i]+k-b[i];
					k=0;
				}
				else
				{
					ans[i]=a[i]+10+k-b[i];
					k=-1;
				}
			}
			if(flag<0)
				printf("-");
			int tap=0;
			while(ans[tap]==0)
				tap++;
			for(int i=tap;i<len;i++)
				printf("%d",ans[i]);
			printf("\n");
			}	
	}
	return 0;
 } 
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
		else
		{
			int len=(lena>lenb)?lena:lenb;
			if(lena!=lenb)
				flag=(lena>lenb)?1:-1;
			if(flag>0)
			{
				for(int i=0,j=lena-1;j>=0;j--,i++)
					a[j]=A[i]-'0';
				for(int i=0,j=lenb-1;j>=0;j--,i++)
					b[j]=B[i]-'0';
			}
			else
			{
				for(int i=0,j=lena-1;j>=0;j--,i++)
					b[j]=A[i]-'0';
				for(int i=0,j=lenb-1;j>=0;j--,i++)
					a[j]=B[i]-'0';
			}
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
			int tap=len;
			while(ans[tap]==0)
				tap--;
			for(int i=tap;i>=0;i--)
				printf("%d",ans[i]);
			printf("\n");
			}	
	}
	return 0;
 } 

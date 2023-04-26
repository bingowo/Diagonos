#include <stdio.h>
#include <string.h>
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		char str[501];
		scanf("%s",str);
		int num[501];
		char word[501];
		int n=0,len,j,w=0,k=0;
		len=strlen(str);
		for(j=0;j<len;j++)
		{
			if(j==0){
				word[w++]=str[j];
				k++;
				if(j==len-1) num[n++]=k;
			}
			
			else if(str[j]!=str[j-1]||k==255)
			{
				num[n++]=k;
				k=0;
				word[w++]=str[j];k++;
				if(j==len-1) num[n++]=k;
			}
			else if(j==len-1) num[n++]=k+1; 
			else k++;
		}
		//printf("%d\n",num[n-1]);
		int w2,n2=0;
		printf("case #%d:\n",i);
		for(w2=0;w2<w;w2++)
		{
			printf("%d",num[n2++]);
			printf("%c",word[w2]);
		}
		printf("\n");
		
	}
}
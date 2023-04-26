#include <stdio.h>
#include <string.h>
int main()
{
	int e=0;
	while(e<100)
	{
		char s[100];
		char a[202][100];
		scanf("%s",s);
		int i,len,k=100,count=1,min=100,max=100;
		len=strlen(s);
		a[100][0]=s[0];
	
		for(i=1;i<len;i++)
		{
			if(s[i]>s[i-1]) {
				a[k-1][count++]=s[i];
				k--;
				if(k<min) min=k;
		//	printf("%d\n",min);
			}
			else if(s[i]<s[i-1]) {
				a[k+1][count++]=s[i];
				k++;
				if(k>max) max=k;
			}
			else a[k][count++]=s[i];
		}
	//printf("%c\n",a[98][2]);
		int m=min;
	
		for(m;m<=max;m++)
		{
			int j=0;
			for(j;j<100;j++)
			{
				if(a[m][j]!=' ') printf("%c",a[m][j]);
				else printf("");
			}
			printf("\n");
		}
	}
	return 0;
}
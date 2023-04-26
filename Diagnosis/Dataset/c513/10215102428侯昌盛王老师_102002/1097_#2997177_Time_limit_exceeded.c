#include <stdio.h>
#include <string.h>

int main()
{
	int e=0;
	while(e<100)
	{
		char s[100];
		char a[202][100];
		memset(a,'\t',sizeof(a));
		int c[202]={0};
		scanf("%s",s);
		int i,len,k=100,count=1,min=100,max=100;
		len=strlen(s);
		a[100][0]=s[0];
		c[100]=1;
		for(i=1;i<len;i++)
		{
			if(s[i]>s[i-1]) {
				a[k-1][count++]=s[i];
				k--;
				c[k]++;
				if(k<min) min=k;
		//	printf("%d\n",min);
			}
			else if(s[i]<s[i-1]) {
				a[k+1][count++]=s[i];
				k++;
				c[k]++; 
				if(k>max) max=k;
			}
			else {
				a[k][count++]=s[i];
				c[k]++;
			}
		}
	//printf("%c\n",a[98][2]);
		int m=min;
		//printf("%c\n",a[100][0]);
		for(m;m<=max;m++)
		{
			int j=0,r=0;
			while(r<c[m])
			{
				if(a[m][j]!='\t') {
					printf("%c",a[m][j]);
					r++;
				}
				else printf(" ");
				j++;
			}
			
			printf("\n");
			
		}
	}
	return 0;
}
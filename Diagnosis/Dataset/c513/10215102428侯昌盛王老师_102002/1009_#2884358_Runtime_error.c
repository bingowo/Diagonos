#include <stdio.h>
#include <string.h>
int main()
{
	int n,i=0;
	scanf("%d",&n);
	for(i;i<n;i++)
	{
		char s[121];
		gets(s);
		int len,k,j=0,num=0;
		len=strlen(s);
		printf("%d\n",len);
		k=len*8;
		for(j;j<len;j++)
		{
			int d=1,w=0;
			for(w;w<8;w++)
			{
				if(s[j]&d) num++;
				d=d<<1;
			}
		
		}
		//printf("%d\n",num);
		int e;
		if(!(k%num)){
			e=k/num;
			printf("1/%d\n",e);
		}
		else printf("%d/%d\n",num,k);
		
		
	}
	return 0;
}
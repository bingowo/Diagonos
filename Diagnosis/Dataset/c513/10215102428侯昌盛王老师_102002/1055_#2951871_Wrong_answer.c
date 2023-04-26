#include <stdio.h>
#include <string.h>

int main()
{
	char s[100];
	scanf("%s",s);
	char sel[100][100];
	int len,i,h1=0,h2=1;
	len=strlen(s);
	sel[0][0]=s[0];
	for(i=1;i<len;i++)
	{
		int k=0,rr=0;
		while(k<i&&s[i]!=s[k]){
			rr++;
			k++;
		}
		if(rr==i) sel[h1][h2++]=s[i];
		else{
			h1++;
			h2=0;
			sel[h1][h2++]=s[i];
		}
	}
	//printf("%s\n",sel[1]);
	int max=0,n,j,op;
	for(j=0;j<h1;j++)
	{
		n=strlen(sel[j]);
		if(n>max){
			max=n;
			op=j;
		}
	}
	printf("%s\n",sel[op]);
	return 0;
}
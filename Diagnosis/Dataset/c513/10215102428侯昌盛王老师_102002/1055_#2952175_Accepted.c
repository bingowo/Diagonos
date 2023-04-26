#include <stdio.h>
#include <string.h>

int main()
{
	char s[1000000];
	scanf("%s",s);
	int n[128],j=0;
	for(j;j<128;j++) n[j]=-1;
	int len1=0,len,t=0,i,max=0,start=0;
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		char c=s[i];
		if(n[c]>=t){
			t=n[c]+1;
			n[c]=i;
		}
		else{
			n[c]=i;
			if(len1<i-t+1)
			{
				start=t;
				len1=i-t+1;
			}
			
		}
	}
	int k=0;
	for(k;k<len1;k++) printf("%c",s[start+k]);
	printf("\n");
	return 0;
}
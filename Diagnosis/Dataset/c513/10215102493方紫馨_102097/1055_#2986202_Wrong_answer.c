#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000001];
	int t[128] = {0};
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++){
		if(t[s[i]]==0)
			printf("%c",s[i]);
		t[s[i]]=1;
	}
	
	return 0;
}
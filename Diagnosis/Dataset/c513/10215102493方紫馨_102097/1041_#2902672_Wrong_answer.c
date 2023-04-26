#include<stdio.h>
#include<string.h>
int main()
{
	char s[51];
	scanf("%s",s);
	int cnt=0,max=0;
	for(int i=1;i<strlen(s);i++){		
		if(s[i-1]==s[i]){
			if(max<cnt)
				max=cnt;
			cnt=-1;
		}
		cnt++;
	}
	printf("%d",max+1);
	return 0;
}

#include<stdio.h>
#include<string.h>
int main()
{
	char s[51];
	scanf("%s",s);
	int cnt=1,max=0;
	for(int i=1;i<strlen(s);i++){		
		if(s[i-1]==s[i]){
			if(max<cnt)
				max=cnt;
			cnt=0;
		}
		cnt++;
	}
	if(max<cnt)
		max=cnt;
	printf("%d",max);
	return 0;
}

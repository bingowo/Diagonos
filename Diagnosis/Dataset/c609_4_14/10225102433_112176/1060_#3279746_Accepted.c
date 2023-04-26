#include <stdio.h>
#include <string.h>

char s[110];

int main()
{
	scanf("%s",s);
	unsigned len = strlen(s);
	for(int i = 0;i < len-1;i++)
	{
		if(s[i] < s[i+1]){
			printf("%c%c",s[i],s[i]);
		}
		else if(s[i] > s[i+1]){
			printf("%c",s[i]);
		}
		else{
			int flag = 0;
			int sig = 0;
			for(int j = i;j < len;j++){
				if(s[j] != s[i]){
					flag = 1;
					if(s[j] > s[i]) sig = 1;
					break;
				}
			}
			if(flag && sig) printf("%c%c",s[i],s[i]);
			else printf("%c",s[i]);
		}
	}
	printf("%c",s[len-1]);
	return 0;
}
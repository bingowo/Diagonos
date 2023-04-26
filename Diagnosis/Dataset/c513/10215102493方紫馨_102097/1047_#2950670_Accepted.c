#include<stdio.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		char s[510];
		scanf("%s",s);
		int cnt=1;
		printf("case #%d:\n",i);
		if(strlen(s)==1)
			printf("%d%c",cnt,s[0]);
		for(int j=1;j<strlen(s);j++){
			if(s[j]==s[j-1]&&cnt<255){
					cnt++;
			}else{
				printf("%d%c",cnt,s[j-1]);
				cnt=1;
			}
			if(j==strlen(s)-1)
				printf("%d%c",cnt,s[j]);
		}
		printf("\n");
	}
	return 0;
 } 
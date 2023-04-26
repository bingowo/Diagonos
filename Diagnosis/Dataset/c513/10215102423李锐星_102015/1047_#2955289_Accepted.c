#include <stdio.h>
#include <string.h>

int main()
{
	int T;
	scanf("%d",&T);
	char s[501];
	int i;
	for (i=0;i<T;i++){
		printf("case #%d:\n",i);
		scanf("%s",s);
		int j;
		int cnt=1;
		char a=s[0];
		for (j=1;j<strlen(s);j++){
			if(a==s[j]){
				if(cnt<255){
					cnt++;
				}
				else if(cnt==255){
					printf("%d%c",cnt,a);
					cnt=1;
					
				}
			}
			else{
				printf("%d%c",cnt,a);
				cnt=1;
				a=s[j];
			}
		}
		printf("%d%c\n",cnt,a); 
	}
	return 0;
}
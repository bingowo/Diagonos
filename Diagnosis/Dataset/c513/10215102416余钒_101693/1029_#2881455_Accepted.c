#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int T,cnt[30];
char s[10005];

int main() {
	scanf("%d\n",&T);
	for(int c=0;c<T;c++){
		gets(s);
		for(int i=0;i<30;i++) cnt[i]=0;
		for(int i=0;s[i];i++)
			if(s[i]>='A'&&s[i]<='Z')
				cnt[s[i]-'A']++;
		printf("case #%d:\n",c);
		int pos=0;
		for(int i=0;s[i];i++){
			if(s[i]>='A'&&s[i]<='Z'){
				while(cnt[pos]<=0) pos++;
				printf("%c",pos+'A');
				cnt[pos]--;
			}
			else printf("%c",s[i]);
		}
		puts("");
	}
	return 0;
}
#include <stdio.h>
#include <string.h>
int T;
int main(void)
{
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++){
		char s[111] = {0};
		scanf("%s",s);
		int len = strlen(s);
		int cnt[4] = {0}, tot[4] = {0}, ans[4] = {0};
		for(int i=0;i<len;i++){
			tot[i%4]++;
			if(s[i]=='R'){
				cnt[0]++;
				ans[0] = i%4;
			}
			if(s[i]=='B'){
				cnt[1]++;
				ans[1] = i%4;
			}
			if(s[i]=='Y'){
				cnt[2]++;
				ans[2] = i%4;
			}
			if(s[i]=='G'){
				cnt[3]++;
				ans[3] = i%4;
			}
		}
		printf("case #%d:\n",kase);
		for(int i=0;i<4;i++) printf("%d ",tot[ans[i]]-cnt[i]);
		putchar('\n'); 
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,k;
	char s[101];
	scanf("%d",&n);
	for(k=0;k<n;k++){
		scanf("%s",s);
		printf("case #%d:\n",k);
		int len=strlen(s),i;
		int tot[4]={0},ans[4]={0},cnt[4]={0};
		for(i=0;i<len;i++){
			tot[i%4]++;
			switch(s[i]){
				case 'R':cnt[0]++;ans[0]=i%4;break;
				case 'B':cnt[1]++;ans[1]=i%4;break;
				case 'Y':cnt[2]++;ans[2]=i%4;break;
				case 'G':cnt[3]++;ans[3]=i%4;break;
			    case '!':break;
			}
		}
		printf("%d %d %d %d\n",tot[ans[0]]-cnt[0],tot[ans[1]]-cnt[1],tot[ans[2]]-cnt[2],tot[ans[3]]-cnt[3]);
	}
	return 0;
}
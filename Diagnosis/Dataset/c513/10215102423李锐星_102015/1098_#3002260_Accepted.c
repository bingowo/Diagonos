#include <stdio.h>
#include <string.h>

void solve()
{
	char s[101];
	scanf("%s",s);
	int len=strlen(s);
	int cnt[4],tot[4],ans[4];
	int i;
	for (i=0;i<4;i++){
		cnt[i]=0;
		tot[i]=0;
		ans[i]=0;
	}
	for (i=0;i<len;i++){
		tot[i%4]++;
		switch(s[i]){
			case 'R':{
				cnt[0]++;
				ans[0]=i%4;
				break;
			}
			case 'B':{
				cnt[1]++;
				ans[1]=i%4;
				break;
			}
			case 'Y':{
				cnt[2]++;
				ans[2]=i%4;
				break;
			}
			case 'G':{
				cnt[3]++;
				ans[3]=i%4;
				break;
			}
		}
	}
	printf("%d %d %d %d\n",tot[ans[0]]-cnt[0],tot[ans[1]]-cnt[1],tot[ans[2]]-cnt[2],tot[ans[3]]-cnt[3]);
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		printf("case #%d:\n",i);
		solve();
	}
	return 0;
}
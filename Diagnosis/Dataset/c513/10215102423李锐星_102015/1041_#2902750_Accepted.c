#include <stdio.h>
#include <string.h>

int main()
{
	char s[51];
	scanf("%s",s);
	int cnt1=1,cnt2=1;
	int i;
	for (i=1;i<strlen(s);i++){
		if (s[i]!=s[i-1]){
			cnt1++;
		}
		else{
			if(cnt2<cnt1){
				cnt2=cnt1;
			}
			cnt1=1;
		}
	}
	if (cnt2<cnt1){
		cnt2=cnt1;
	}
	printf("%d\n",cnt2);
	return 0;
}
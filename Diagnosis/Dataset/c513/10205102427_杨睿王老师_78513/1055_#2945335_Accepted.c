#include <stdio.h>
#include <string.h>
char s[10000000],t[10000000];
int main(){
	scanf("%s",s);
	int len=strlen(s);
	int i=0,j=1,p,q,w=0,cnt=0,cmp=0;
	if(len<2){
		printf("%c\n",s[0]);
		return 0;
	}
	else 
		while(j<len){
			//printf("test-j:%d\n",j);
			for(p=i;p<j;p++)
				if(s[p]==s[j]){
					i = p + 1;
					break;
				}
			//printf("test-i:%d\n",i);
			++j;
			cnt = j - i;
			//printf("test-cnt:%d\n",cnt);a			
			if(cnt>cmp){
				cmp=cnt;
				for(q=i;q<j;q++)
					t[q-i]=s[q];
			}
		}
	for(int r=0;r<cmp;r++)
		printf("%c",t[r]);
	return 0;
}

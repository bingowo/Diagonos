#include <stdio.h>
int main(){
	int T,i;
	scanf("%d",&T);
	getchar();
	for(i=0;i<T;i++){
		printf("case #%d:\n",i);
		char ch;
		char s[600];
		memset(s,'\0',600);
		int l=0;
		int cnt=1;
		while((ch=getchar())!='\n'){
			s[l]=ch;
			//printf("%c",s[l]);
			l++;
		}
		for(int y=0;y<l;y++){
			if(s[y]==s[y+1]) cnt++;
			else{
				if(cnt>255){
					printf("255%c%d%c",s[y],cnt-255,s[y]);
				}
				else{
					printf("%d%c",cnt,s[y]);
				}
				cnt=1;
			}
		}
		printf("\n");
	}
}

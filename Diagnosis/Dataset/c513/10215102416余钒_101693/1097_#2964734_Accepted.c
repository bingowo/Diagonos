#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int l,pos[10005],cnt[10005];
char s[10005];
int main() {
	while(~scanf("%s",s+1)){
		int min=1,max=1;
		for(int i=1;i<=100;i++) cnt[i]=0;
		for(int i=1;s[i];i++){
			if(i==1) pos[i]=1;
			else{
				if(s[i]>s[i-1]) pos[i]=pos[i-1]-1;
				else if(s[i]==s[i-1]) pos[i]=pos[i-1];
				else pos[i]=pos[i-1]+1;
				if(pos[i]<min) min=pos[i];
				if(pos[i]>max) max=pos[i];
			}
		}max+=-min+1;
		for(int i=1;s[i];i++) pos[i]+=-min+1,cnt[pos[i]]++;
		for(int i=1;i<=max;i++){
			int hav=0;
			for(int j=1;s[j];j++){
				if(pos[j]!=i) putchar(' ');
				else putchar(s[j]),hav++;
				if(hav==cnt[i]) break;
			}
			puts("");
		}
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
struct data{
	int begin,end,d;
}x[100000];
int main()
{
	char s[1000001];
	int t[128] = {0};
	scanf("%s",s);
	int idx=0;
	for(int i=0;i<strlen(s);i++){
		if(t[s[i]]==0){
			t[s[i]]=1;
			if(i-1<x[idx-1].begin||t[s[i-1]]!=1)
				x[idx].begin = i;
		}else{
			x[idx].end = i;
			x[idx].d = x[idx].end - x[idx].begin;
			t[s[i]] = 1;
			i = x[idx].begin ;
			idx++;
			x[idx].begin = i + 1;
			memset(t,0,128*4);
			
		}
	}
	x[idx].end = strlen(s);
	x[idx].d = x[idx].end - x[idx].begin;
	int max = 0;
	for(int i=idx;i>=1;i--){
		if(x[max].d<x[i].d)
			max = i;
	}
	for(int i=x[max].begin;i<x[max].end;i++){
		printf("%c",s[i]);
	}
	
	return 0;
}
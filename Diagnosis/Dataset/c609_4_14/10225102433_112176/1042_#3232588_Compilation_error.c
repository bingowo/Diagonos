#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1010

typedef struct{
	char *s;
	int L;
}node;

int LEN;
int ans;
char s[3000];

int main()
{
	int n;scanf("%d",&n);
	for(int i = 0;i < n;i++){
		int M;scanf("%d",&M);
		printf("case #%d:\n",i);
		node *ch = (node*)malloc(N*sizeof*ch);
		char c;
		int sig = 1;
		while(sig)
		{
			scanf("%s%c",s+LEN,&c);
			unsigned len = strlen(s+LEN);
			if(c == '\n') sig = 0;
			ch[ans].s = s+LEN;
			ch[ans++].L = len;
			LEN += len+1;
		}
		int cnt = 0;
		for(int j = 0;j < ans-1;j++){
			int ak = j+1;
			int res = ch[j].L;
			while((res+ch[ak.L]+1) <= M){
				res += ch[ak++].L+1;
			}
			int Num = (ak-j-1)+M-res;       //空格个数
			int num = (ak-1-j);
			if(Num%num != 0)
			{
				int p1 = Num/num;
				int p2 = Num%num;
				printf("%s",ch[j].s);
				for(int k = 1;k <= num-p2;k++){
					for(int u = 0;u < p1;u++) printf(" ");
					printf("%s",ch[j+k]);
				}
				for(int k = 1;k <= p2;k++){
					for(int u = 0;u < p1+1;u++) printf(" ");
					printf("%s",ch[j+num-p2+k].s);
				}
			}
			j = ak-1;
		} 
		free(ch);
		ans = 0;
		memset(s,'\0',sizeof(s));
		LEN = 0;
	}
}
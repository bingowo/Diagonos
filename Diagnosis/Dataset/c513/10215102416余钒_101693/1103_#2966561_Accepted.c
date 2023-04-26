#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define M 1000000007 
long long num[10];
char oper[100005],s[100005];
int main() {
	num[0]=num[1]=num[2]=num[3]=0;
	while(~scanf("%s",s)){
		int p1,p2;
		long long res,flg;
		if(s[0]=='I'){
			scanf("%s",oper);
			p1=oper[0]-'A',res=0,flg=1;
			if(oper[3]=='-') flg=-1;
			for(int j=oper[3]=='-'?4:3;oper[j];j++) res=res*10+oper[j]-'0';
			res*=flg;
			//printf("??? %d\n",res);
			num[p1]=res;
		}else if(s[0]=='O'){
			scanf("%s",oper);
			printf("%lld\n",num[oper[0]-'A']);
		}else{
			scanf("%s",oper);
			p1=oper[0]-'A',p2=oper[3]-'A';
			//printf("!! %d %d\n",p1,p2);
			if(s[1]=='O') num[p1]=num[p2];
			else if(s[0]=='A') num[p1]+=num[p2];
			else if(s[0]=='S') num[p1]-=num[p2];
			else if(s[0]=='M') num[p1]*=num[p2];
			else num[p1]/=num[p2];
		}
	}
	return 0;
}

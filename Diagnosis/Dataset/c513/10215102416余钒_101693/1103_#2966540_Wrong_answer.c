#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define M 1000000007 
int num[10];
char oper[105],s[105];
int main() {
	num[0]=num[1]=num[2]=num[3]=0;
	while(~scanf("%s",s)){
		int p1,p2,res;
		if(s[0]=='I'){
			scanf("%s",oper);
			p1=oper[0]-'A',res=0;
			for(int j=3;oper[j];j++) res=res*10+oper[j]-'0';
			//printf("??? %d\n",res);
			num[p1]=res;
		}else if(s[0]=='O'){
			scanf("%s",oper);
			printf("%d\n",num[oper[0]-'A']);
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

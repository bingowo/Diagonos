#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define M 1000000007
long long num[40];
char oper[100005],s[100005];
int main() {
	for(int i=0; i<30; i++) num[i]=0;
	while(~scanf("%s",s)) {
		int p1,p2,p3;
		long long res,flg;
		scanf("%s",oper);
		if(s[0]=='I') {
			p1=oper[0]-'A',res=0,flg=1;
			if(oper[3]=='-') flg=-1;
			for(int j=oper[3]=='-'?4:3; oper[j]; j++) res=res*10+oper[j]-'0';
			res*=flg;
			//printf("??? %d\n",res);
			num[p1]=res;
		} else if(s[2]=='T') {
			printf("%lld\n",num[oper[0]-'A']);
		} else if(s[0]=='M'&&s[2]=='V') {
			p1=oper[0]-'A',p2=oper[3]-'A';
			num[p1]=num[p2];
		} else if(s[0]=='X'&&s[1]=='G') {
			p1=oper[0]-'A',p2=oper[3]-'A';
			res=num[p1],num[p1]=num[p2],num[p2]=res;
		} else {
			flg=0;
			p1=oper[0]-'A',p2=oper[3]-'A';
			if(oper[5]==',') flg=1,p3=oper[6]-'A';
			//printf("!! %d %d %d\n",p1,p2,p3);
			if(s[0]=='A'&&s[1]=='D') {
				if(flg) num[p1]=num[p2]+num[p3];
				else num[p1]+=num[p2];
			} else if(s[0]=='S') {
				if(flg) num[p1]=num[p2]-num[p3];
				else num[p1]-=num[p2];
			} else if(s[0]=='M' && s[1]=='U') {
				if(flg) num[p1]=num[p2]*num[p3];
				else num[p1]*=num[p2];
			} else if(s[0]=='D') {
				if(flg) num[p1]=num[p2]/num[p3];
				else num[p1]/=num[p2];
			} else if(s[0]=='M'&&s[1]=='O') {
				if(flg) num[p1]=num[p2]%num[p3];
				else num[p1]%=num[p2];
			} else if(s[0]=='A'&&s[1]=='N') {
				unsigned int tmp1=(int)num[p1],tmp2=(int)num[p2],tmp3=(int)num[3];
				if(flg) num[p1]=((int)tmp2&tmp3)*1ll;
				else num[p1]=((int)tmp1&tmp2)*1ll;
			} else if(s[0]=='O'&&s[1]=='R') {
				unsigned int tmp1=(int)num[p1],tmp2=(int)num[p2],tmp3=(int)num[3];
				if(flg) num[p1]=((int)tmp2|tmp3)*1ll;
				else num[p1]=((int)tmp1|tmp2)*1ll;
			} else {
				unsigned int tmp1=(int)num[p1],tmp2=(int)num[p2],tmp3=(int)num[3];
				if(flg) num[p1]=((int)tmp2^tmp3)*1ll;
				else num[p1]=((int)tmp1^tmp2)*1ll;
			}
		}
		//for(int i=0;i<4;i++) printf("%d ",num[i]);
		//puts(" ");
	}
	return 0;
}

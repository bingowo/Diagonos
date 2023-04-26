#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char s[1005];
int p[10];
int cal(int x) {
	return x*x*x*p[3]+x*x*p[2]+x*p[1]+p[0];
}
int main() {
	scanf("%s",s);
	int res=0,flg=1;
	for(int i=0; s[i]; i++) {
		if(s[i]=='+') flg=1;
		else if(s[i]=='-') flg=-1;
		else if(s[i]>='0'&&s[i]<='9') {
			res=res*10+s[i]-'0';
			if(s[i+1]==0) p[0]=res*flg;
		} else if(s[i]=='x') {
			if(res==0) res=1;
			if(s[i+1]!='^') p[1]=res*flg;
			else p[s[i+2]-'0']=res*flg,i+=2;
			res=0,flg=1;
		}
	}
	//printf("%d %d %d\n",p[0],p[1],p[2]);
	for(int i=1; i*i<=p[2];i++) {
		if(p[2]%i!=0) continue;
		int a1=i,a2=p[2]/i,c1,c2;
		for(int j=-200; j<=200; j++) {
			if(j==0) continue;
			if(p[0]%j==0) {
				c1=j,c2=p[0]/j;
				if(a1*c2+a2*c1==p[1]) printf("%d %d %d %d\n",a1,c1,a2,c2),exit(0);
			}
		}
	}
	puts("No Answer!");
	return 0;
}
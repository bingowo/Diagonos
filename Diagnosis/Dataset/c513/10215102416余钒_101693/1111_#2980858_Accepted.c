#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char s[1005];
int p[10];
int cal(int x){
	return x*x*x*p[3]+x*x*p[2]+x*p[1]+p[0];
}
int main() {
	while(~scanf("%s",s)){
		int res=0,flg=1;
		p[0]=p[1]=p[2]=p[3]=0;
		for(int i=5;s[i];i++){
			if(s[i]=='+') flg=1;
			else if(s[i]=='-') flg=-1;
			else if(s[i]>='0'&&s[i]<='9'){
				res=res*10+s[i]-'0';
				if(s[i+1]==0) p[0]=res*flg;
			}else if(s[i]=='x'){
				if(res==0) res=1;
				if(s[i+1]!='^') p[1]=res*flg; 
				else p[s[i+2]-'0']=res*flg,i+=2;
				res=0,flg=1;
			}
		}
//		printf("%d %d %d %d\n",p[0],p[1],p[2],p[3]);
		for(int i=20;i>=-20;i--){
			for(int j=-20;j<=20;j++){
				if(i==cal(j)) putchar('*');
				else if(i==0){
					if(j==0) putchar('+');
					else if(j<20) putchar('-');
					else putchar('>');
				}else if(j==0){
					if(i==20) putchar('^');
					else putchar('|');
				}else putchar('.');
			}
			puts("");
		}
		puts("");
	}
	return 0;
}
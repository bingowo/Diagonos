#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int val[10],stk[10],top=0;
char s[10][10];
void outp(){
	if(top==0) printf("impossible");
	else{
		putchar('{');
		for(int i=1;i<=top;i++){
			if(stk[i]==0) putchar('O');
			else if(stk[i]==1) putchar('A');
			else if(stk[i]==2) putchar('B');
			else printf("AB");
			if(i==top) putchar('}');
			else putchar(',');
		}
	}
}
int main() {
	for(int i=1;i<=3;i++){
		scanf("%s",s[i]);
		if(s[i][0]=='?') val[i]=-1;
		else if(s[i][0]=='O')  val[i]=0;
		else if(s[i][0]=='B') val[i]=2;
		else if(s[i][1]=='B') val[i]=3;
		else val[i]=1;
	} 
	if(val[1]==-1){
		for(int c=1;;c++){
			c=c%4;
			if(((c&1)|(val[2]&2))==val[3]||((c&2)|(val[2]&1))==val[3]||((c&2)|(val[2]&2))==val[3]||((c&1)|(val[2]&1))==val[3]) stk[++top]=c;
			if(!c) break;
		}
		outp(),printf(" %s %s",s[2],s[3]);
	}
	else if(val[2]==-1){
		for(int c=1;;c++){
			c=c%4;
			if(((c&1)|(val[1]&2))==val[3]||((c&2)|(val[1]&1))==val[3]||((c&2)|(val[1]&2))==val[3]||((c&1)|(val[1]&1))==val[3]) stk[++top]=c;
			if(!c) break;
		}
		printf("%s ",s[1]), outp(),printf(" %s",s[3]);
	}else{
		for(int c=1;;c++){
			c=c%4;
			if(((val[2]&1)|(val[1]&2))==c||((val[2]&2)|(val[1]&1))==c||((val[2]&2)|(val[1]&2))==c||((val[2]&1)|(val[1]&1))==c) stk[++top]=c;
			if(!c) break;
		}
		printf("%s %s ",s[1],s[2]),outp();
	}
	return 0;
}
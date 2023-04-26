#include <stdio.h>
char table[]="0123456789ABCDEFGHIJKL";
int c;
int f1(int a,int b){            //a取余b 
	return a-(f2(a,b))*b;
}
int f2(int a,int b){            //a除以b 
	if(a<0&&a%b!=0)return a/b+1;
	return a/b;
}
int f3(int a,int b){
	c=f2(a,b);
	if(c){
		f3(c,b);
	}
	putchar(table[f1(a,b)]);
}
int main(){
	int n,r;
	scanf("%d%d",&n,&r);
	f3(n,r);
} 
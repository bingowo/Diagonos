#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int n;
char s[10005];
int check(int a,int b,int x,int y,int dx,int dy){
	if(dx==0){
		if(dy==0){
			if(x==a && b==y) return 1;
		}else{
			if(x==a && (b-y)%dy==0 && (b-y)/dy>=0) return 1;
		}
	}else if(dy==0){
		if( b==y && (a-x)%dx==0 && (a-x)/dx>=0) return 1;
	}else if((a-x)%dx==0&&(b-y)%dy==0&&(a-x)/dx==(b-y)/dy && (a-x)/dx>=0) return 1;
	return 0;
}
int main() {
	int x=0,y=0,dx,dy,a,b;
	scanf("%s",s);
	for(int i=0;s[i];i++){
		if(s[i]=='U') y++;
		else if(s[i]=='D') y--;
		else if(s[i]=='R') x++;
		else x--;
	}
	dx=x,dy=y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		int f=0;
		x=y=0;
		if(check(a,b,x,y,dx,dy)) f=1;
		for(int j=0;s[j];j++){
			if(s[j]=='U') y++;
			else if(s[j]=='D') y--;
			else if(s[j]=='R') x++;
			else x--;
			if(check(a,b,x,y,dx,dy)) f=1;
		}
		if(f==0) puts("No");
		else puts("YES");
	}
	return 0;
}

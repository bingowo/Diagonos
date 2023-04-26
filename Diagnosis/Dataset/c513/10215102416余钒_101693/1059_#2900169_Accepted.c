#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int n,s,a[100005];
int gcd(int a,int b){
	if(a%b==0) return b;
	else return gcd(b,a%b);
}
int main() {
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0]=1e9,a[n+1]=1e9;
	int pos=1,min=a[1];
	for(int i=1;i<=n;i++)
		if(a[i]<min) min=a[i],pos=i;
	int wid=1,h=a[pos],L=pos,R=pos;
	while(s){
		h++;
		while(a[L-1]<h) L--;
		while(a[R+1]<h) R++;
		if(s>=(R-L+1)) s-=R-L+1;
		else {
			int g=gcd((R-L+1),s);
			if(h-1>0) printf("%d+%d/%d\n",h-1,s/g,(R-L+1)/g);
			else printf("%d/%d\n",s/g,(R-L+1)/g);
			exit(0);
		}
	}
	printf("%d\n",h);
	return 0;
}
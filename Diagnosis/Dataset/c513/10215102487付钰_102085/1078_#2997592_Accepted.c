#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int h[100005],n,s,p;
int gcd(int a,int b) {
	int tmp;
	if(a<b) tmp=a,a=b,b=tmp;
	if(a%b==0) return b;
	else return gcd(b,a%b);
}
int main() {
	scanf("%d%d%d",&n,&p,&s);
	for(int i=1; i<=n; i++)
		scanf("%d",&h[i]);
	h[0]=1e9,h[n+1]=1e9;
	int nwsq=0,L=s,R=s;
	while(h[R]>=h[R+1]) R++;
	while(h[L]>=h[L-1]) L--;
	int equl,equr,G,ladd=p/2,radd=p/2,lres=p%2,rres=p%2;
	while(1) {
		//printf("%d %d %d %d %d %d %d %d\n",L,R,equl,equr,ladd,radd,lres,rres);
		equl=L,equr=R;
		int ldep=0,rdep=0;
		while(h[equr]==h[R]) equr--;
		while(h[equl]==h[L]) equl++;
		if(h[L]==h[s]) radd+=ladd,rres+=lres,radd+=rres/2,rres%=2,ladd=0,lres=0;
		else if(h[R]==h[s]) ladd+=radd,lres+=rres,ladd+=lres/2,lres%=2,radd=0,rres=0;
		if(equl-1==R && equr+1==L) {
			if(radd<R-L+1) break;
			for(int i=L;i<=R;i++) h[i]++,radd--;
			while(h[L]>=h[L-1]) L--;
			while(h[R]>=h[R+1]) R++;
			equl=L;
			while(h[equl]==h[L]) equl++;
			equr=R;
			while(h[equr]==h[R]) equr--;
			if(equl-1!=R){
				lres=rres=radd%2;
				ladd=radd/2;
				radd/=2;
			}
		} else {
			if(radd<(R-equr)&&ladd<(equl-L)) break;
			while(h[L]<h[s] && ladd>=(equl-L)) {
				for(int i=L; i<equl; i++) h[i]++,ladd--;
				while(h[L]>=h[L-1]) L--;
				equl=L;
				while(h[equl]==h[L]) equl++;
			}
			while(h[R]<h[s] && radd>=(R-equr)) {
				for(int i=equr+1; i<=R; i++) h[i]++,radd--;
				while(h[R]>=h[R+1]) R++;
				equr=R;
				while(h[equr]==h[R]) equr--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i>=L&&i<equl&&ladd+lres!=0) printf("%d+%d/%d ",h[i],(lres+2*ladd)/gcd(lres+2*ladd,2*(equl-L)),2*(equl-L)/gcd(lres+2*ladd,2*(equl-L)));
		else if(i<=R&&i>equr&&radd+rres!=0) printf("%d+%d/%d ",h[i],(rres+2*radd)/gcd(rres+2*radd,2*(R-equr)),2*(R-equr)/gcd(rres+2*radd,2*(R-equr)));
		else printf("%d ",h[i]);
	}
	return 0;
}

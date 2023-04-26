#include<stdio.h>
#include<string.h>

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }

    return GCD(b, a % b);
}

int cnt_1(unsigned char d){
	int n1;
	for(n1=0;d>0;d>>=1){
		if(d&1)n1++;
		}
	return n1;
}

void solve(){
    char s[130];
    fgets(s,sizeof(s),stdin);
    int i=0,n1=0,nall=0,gcd;
    while(s[i]!='\n'){
        n1+=cnt_1(s[i]);
        nall+=8;
        i++;
    }
    gcd=GCD(n1,nall);
    n1/=gcd,nall/=gcd;
    printf("%d/%d\n",n1,nall);
}

int main(){
	int n,i;
	scanf("%d\n",&n);
	for(i=0;i<n;i++) solve();
	return 0;
}

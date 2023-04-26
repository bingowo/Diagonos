#include<stdio.h>
#include<string.h>
int GCD(int m,int  n){
	if(n<=m&&n==0) return m;
	else if(m<n) return GCD(n,m);
	else return GCD(n,m%n);
}
int count(char c){
	int z=c;
	int co=0,one=1;
	for(int k=0;k<8;k++){
		if (z & one)
             co++;
          z = z >> 1;
	}
	return co;
}
int main(){
	int T;
	scanf("%d\n",&T);
	char s[121];
	int d=0,d1=0;
	for(int i=0;i<T;i++){
		gets(s);
		for(int j=0;j<strlen(s);j++){
			d1+=count(s[j]);
			d+=8;
		}
	int g=GCD(d,d1);
	printf("%d/%d\n",d1/g,d/g);
	}
return 0;


}
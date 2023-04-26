#include<stdio.h>
#include<string.h>
void text(char s[101]) {
	int i=0;
	while(i<sizeof(s)-1) {
		if(s[i]==s[i+1])
			return true;
		i++;
	}
	return false;
}
void f(char s[101]) {
	int i=0;
	char x[101];
	while(i<sizeof(s)) { //ABCCBCCAA
		if(s[i]==s[i+1]&&i+1<sizeof(s)) {
			int j = i;
			while(s[j]==s[j+1]&&j<sizeof(s)-1)j++;
			i=j+1;
		} else {
			x[i]+=s[i];
			i++;
		}
	}
	if(text(x)&&x!="")
		return f(x);
	else
		return x;
}
int main() {
	int t;
	scanf("%d",&t);
	for(int k=0; k < t; k++) {
		char s[101];
		scanf("%s",s);
		int sum=0;
		for(int i = 0; i < sizeof(s); i++) {
			char x,y,z;
			x=y=z=s;
			x.insert(i,"A");
			y.insert(i,"B");
			z.insert(i,"C");
			int a=sizeof(f(x));
			int b=sizeof(f(y));
			int c=sizeof(f(z));
			int Min=min(min(a,b),c);
			Min=sizeof(s)+1-Min;
			sum=max(sum,Min);
		}
		printf("case #%d:\n%d\n",k,sum);
	}

	return 0;
}

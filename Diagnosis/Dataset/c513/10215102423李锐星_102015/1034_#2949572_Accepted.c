#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double list[52];

double value(char c)
{
	if(c>='A'&&c<='Z'){
		return list[c-'A'];
	}
	return list[c-'a'+26];
}

int cmp(const void *a,const void *b)
{
	char x,y;
	x=*(char*)a;
	y=*(char*)b;
	double m,n;
	m=value(x);
	n=value(y);
	if(m>n){
		return -1;
	}
	else if(m<n){
		return 1;
	}
	else{
		if(x>y&&x==y+32){
			return -1;
		}
		else if(x<y&&x==y-32){
			return 1;
		}
		else{
			return x-y;
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	int i;
	char s[101];
	for (i=0;i<T;i++){
		for (int j=0,k=26;j<26&&k<52;j++,k++){
			scanf("%lf",&list[j]);
			list[k]=list[j];
		}
		scanf("%s",s);
		int len=strlen(s);
		qsort(s,len,sizeof(s[0]),cmp);
		printf("case #%d:\n",i);
		printf("%s\n",s);
	}
	return 0;
}
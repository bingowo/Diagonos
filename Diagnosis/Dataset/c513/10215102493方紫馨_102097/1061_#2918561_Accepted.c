#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	char s[16];
	long long int n;
}char_num;

long long int charTOnum(char s[]){
	char c[128];
	memset(c,-1,128);
	int R=0,d=0;
	c[s[0]] = 1;
	for(int i=0;i<strlen(s);i++){			
		if(c[s[i]]==-1){
			c[s[i]]=d;
			if(d==0)
				d+=2;
			else
				d++;	
		}
	}
	if(d<2)
		R=2;
	else
		R=d;
	long long ret=0;
	for(int i=0;i<strlen(s);i++){
		ret = ret*R+c[s[i]];
	}
	return ret;
}
int cmp(const void*p1,const void*p2){
	char_num* a = (char_num*)p1;
	char_num* b = (char_num*)p2;
	if(a->n > b->n)
		return 1;
	if(a->n < b->n)
		return -1;
	int i=0;
	while(a->s[i]==b->s[i]){
		i++;
	}
	return a->s[i]-b->s[i];
}
int main()
{
	int T;
	scanf("%d",&T);
	char_num str[T];
	for(int i=0;i<T;i++){
		scanf("%s",str[i].s);
		str[i].n = charTOnum(str[i].s);
	}
	qsort(str,T,sizeof(char_num),cmp);
	for(int i=0;i<T;i++){
		printf("%s\n",str[i].s);
	}
	return 0;
}
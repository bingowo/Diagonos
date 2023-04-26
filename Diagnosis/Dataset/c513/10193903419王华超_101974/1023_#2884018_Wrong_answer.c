#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
typedef struct{
	int num;
	char s[31];
}string;
int cmp(const void*p1,const void*p2){
	string a=*((string*)p1),b=*((string*)p2);
	if(a.num!=b.num){
		return a.num-b.num;
	}
	else{
		return strcmp(a.s,b.s);
	}
}
int main(int argc, char *argv[]) {
	int index=0;
	string l[100];
	while(scanf("%s",l[index].s)!=EOF){
		int len=strlen(l[index].s);
		l[index].num=-1;
		int i=len-1,nsum=0;
		while(l[index].s[i]>='0'&&l[index].s[i]<='9'){
			nsum+=(l[index].s[i]-'0')*pow(10,len-i-1);
			i--;
		}
		if(i!=(len-1)){
			l[index].num=nsum;
		}
		index++;
	}
	qsort(l,index,sizeof(l[0]),cmp);
	int i;
	for(i=0;i<index;i++){
		printf("%s ",l[i].s);
	}
	return 0;
}
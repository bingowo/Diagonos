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
		int i,len=strlen(l[index].s),nsum=0,flag=0;
		l[index].num=-1;
		for(i=len-1;i>=0;i--){
			if(l[index].s[i]>='0'&&l[index].s[i]<='9'){
				int j=i;
				while(l[index].s[j]>='0'&&l[index].s[j]<='9'){
					nsum+=(l[index].s[j]-'0')*pow(10,i-j);
					j--;
				}
				flag=1;
			}
		}
		if(flag==1){
			l[index].num=nsum;
		}
		index++;
	}	
	qsort(l,index,sizeof(l[0]),cmp);
	int n;
	for(n=0;n<index;n++){
		printf("%s ",l[n].s);
	}
	return 0;
}
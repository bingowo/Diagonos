#include <stdio.h>
int cmp(const void* a,const void* b){
	char* c=(char(*)[101])a;
	char* d=(char(*)[101])b;
	int sign1=1,sign2=1;
	if(c[0]=='+'){c++;}
	else if(c[0]=='-'){sign1=-1;c++;}
	if(d[0]=='+'){d++;}
	else if(d[0]=='-'){sign2=-1;d++;}
	if(sign1!=sign2){return sign1-sign2;}
	else{
		char *p1,*p2;
		for(p1=c;*p1&&*p1!='.';p1++);
		for(p2=c;*p2&&*p2!='.';p2++);
		int len1=p1-c,len2=p2-d;
		if(len1!=len2)return (len1-len2)*sign1;
		else return strcmp(c,d)*sign1;
	}
}
int main(){
	int n;scanf("%d",&n);
	int i;char num[n][101];
	for(i=0;i<n;i++){
		scanf("%s",num[i]);
	}
	qsort(num,n,101*sizeof(char),cmp);
} 
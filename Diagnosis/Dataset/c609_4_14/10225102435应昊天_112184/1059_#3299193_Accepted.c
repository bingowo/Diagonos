#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a,const void* b);
int main(){
	int n;
	scanf("%d",&n);
	char s[n][101];
	for(int i = 0;i < n;i++){
		scanf("%s",s[i]);	
	}
	qsort(s,n,sizeof(s[0]),cmp);
	for(int j = 0;j < n;j++){
		printf("%s\n",s[j]);
	}
	return 0;
}
int cmp(const void* a,const void* b){
	char* aa = (char*)a;
	char* bb = (char*)b;
	char* s1 = aa;
	char* s2 = bb;
	int sign1 = 1;
	int sign2 = 1;
	if(*s1 == '-'){
		sign1 = -1;
		s1++;	
	}
	else if(*s1 == '+'){
		s1++;
	}
	if(*s2 == '-'){
		sign2 = -1;
		s2++;	
	}
	else if(*s2 == '+'){
		s2++;
	}
	if(sign1 != sign2)
		return sign1 - sign2;	
	int len1 = 0;
	int len2 = 0;
	char* p1;
	char* p2;
	for(p1 = s1;*p1 && *p1 != '.';p1++);
	for(p2 = s2;*p2 && *p2 != '.';p2++);
	len1 = p1 - s1;
	len2 = p2 - s2;
	if(len1 != len2)
		return sign1 * (len1-len2);
	else
		return sign1 * strcmp(s1,s2);
}
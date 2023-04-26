#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct string{
	char s[21];
	int number;
};
int cmp(const void*a,const void*b){
	struct string p1,p2;
	p1=*(struct string*)a;p2=*(struct string*)b;
	if(p1.number!=p2.number)return p1.number>p2.number?-1:1;
    else return strcmp(p1.s,p2.s);	
}
int main() {
	int alpha[26]={}; 
	int t,i,j,k,n;
	struct string a[101];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		for(j=0;j<n;j++){
			for(k=0;k<26;k++)alpha[k]=0;
			a[j].number=0;
			scanf("%s",a[j].s);  //记录字符串
			for(k=0;k<strlen(a[j].s);k++){
				if(alpha[a[j].s[k]-'A']==0){
					a[j].number++;  //记录不同字符串 
					alpha[a[j].s[k]-'A']++;
				}  //没有出现过 
			}  //对字符串进行迭代 
		}  //对每个字符串进行输入
		qsort(a,n,sizeof(a[0]),cmp); 
		printf("case #%d:\n",i);
		for(j=0;j<n;j++)printf("%s\n",a[j].s);
	}
	return 0;
}
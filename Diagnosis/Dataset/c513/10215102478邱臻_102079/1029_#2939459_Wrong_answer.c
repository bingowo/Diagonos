#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void*a,const void*b){
	char *p1,*p2;
	p1=(char*)a;p2=(char*)b;
	return *p1<*p2?-1:1;
}
int main() {
	int t,i,j,k,z,x,y,p;
	char s[201],alpha[201];
	char c;
	int number[201];
	scanf("%d",&t);
	getchar();
	for(i=0;i<t;i++){
		j=0;k=0;z=0;
		while((c=getchar())!='\n'){
			s[j++]=c;  //总字符串  长度为j 
			if(isalpha(c))alpha[k++]=c;  //是字母 
			else number[z++]=j-1;  //其它字符串的下标  长度为z 
		}
		qsort(alpha,k,sizeof(alpha[0]),cmp);
		printf("case #%d:\n",i);
		y=0;p=0;
		for(x=0;x<j;x++){
			if(x==number[y]){  //其他字符 
				printf("%c",s[x]);
				y++;
			}
			else{
				printf("%c",alpha[p]);
				p++;
			}
		}
		printf("\n");
	}
	return 0;
}
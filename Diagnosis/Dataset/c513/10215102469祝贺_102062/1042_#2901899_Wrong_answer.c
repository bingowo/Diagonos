#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
	char n1=*((char*)a),n2=*((char*)b);
	return n1-n2;
}
int main(){
	int t;scanf("%d",&t);
	for(int m=0;m<t;m++){
		char s[20];scanf("%s",s);
		qsort(s,strlen(s),sizeof(s[0]),cmp);
		int begin=0;
		for(int end=1;end<strlen(s);end++){
			if(s[end]!=s[begin]){
				s[++begin]=s[end];
			}
		}
		printf("case #%d:\n",m);
		for(int start=0;start<=begin;start++){
			printf("%c\n",s[start]);
			for(int i=start+1;i<=begin;i++){
				for(int j=i;j<=begin;j++){
					printf("%c",s[start]); 
					for(int e=i;e<=j;e++)
						printf("%c",s[e]);
					printf("\n");
				}
			}
		}
		
	}
	return 0;
} 

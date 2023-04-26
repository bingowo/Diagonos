#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct string{
	int cnt;
	char str[21];
}S;
int cmp(const void * x,const void * y){
	S xx=*(S*) x;
	S yy=*(S*) y;
	if(xx.cnt==yy.cnt) return strcmp(xx.str,yy.str);
	else return yy.cnt-xx.cnt;
}
int main(){
	int i,T;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		printf("case #%d:\n",i);
		int n;
		scanf("%d",&n);
	    S s[101];
	    for(int y=0;y<101;y++){
	    	s[y].cnt=0;
	    	for(int r=0;r<21;r++){
	    		s[y].str[r]='0';
			}
		}
		char ch=getchar();
		for(int y=0;y<n;y++){
			
			int l=0;
			int table[128];
			for(int r=0;r<128;r++){
				table[r]=0;
			}
			while((ch=getchar())!='\n'){
				s[y].str[l]=ch;
				table[s[y].str[l]]++;
				l++;
			}
			for(int r=0;r<128;r++){
				if(table[r]>0) s[y].cnt++;
			}
			/*printf("\ntest:%d\n",s[y].cnt);
			for(int r=0;r<l;r++){
				printf("%c ",s[y].str[r]);
			}	
			printf("\n");*/
		}
		qsort(s,n,sizeof(S),cmp);
		for(int y=0;y<n;y++){
			int r=0;
			while(s[y].str[r]!='0'){
				printf("%c",s[y].str[r]);
				r++;
			}
			printf("\n");
		}
	}
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char a[35];
	int num;
	int d;
}p;
int strnumcmp(const void* a,const void *b){
	if((*(p*)a).num!=(*(p*)b).num) return (*(p*)a).num>(*(p*)b).num;
	else return strcmp((*(p*)a).a,(*(p*)b).a);
}
int main(){
	char cc;
	int cnt=0;
	p s[500];
	int f=0;
	int len=0;
	while(scanf("%c",&cc)!=EOF){
		if(cc<='9' && cc>='0'){
			if(f==0){
				f=1;
				s[cnt].d=len;
				s[cnt].num=cc-'0';
			}
			else s[cnt].num=s[cnt].num*10+cc-'0';
		}		
		else if(cc==' '){
			if(f==0){
				s[cnt].num=-1;
				s[cnt].d=-1;
			}
			f=0;
			cnt++;
			len=0;
		}
		else{
			s[cnt].a[len++]=cc;
		}
	}
	qsort((void *)s,cnt,sizeof(s[0]),strnumcmp);
	for(int i=0;i<cnt;i++){
		for(int j=0;j<=strlen(s[i].a);j++){
			if(j==s[i].d) printf("%d",s[i].num);
			if(j!=strlen(s[i].a))printf("%c",s[i].a[j]);
		}
		printf(" ");
	}
}
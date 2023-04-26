#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char a[35];
	char num[35];
	int num2;
	int d;
	char k[35];
}p;
int strnumcmp(const void* a,const void *b){
	if((*(p*)a).num2!=(*(p*)b).num2) return (*(p*)a).num2>(*(p*)b).num2;
	else if(strcmp((*(p*)a).num,(*(p*)b).num)!=0) return strcmp((*(p*)a).num,(*(p*)b).num);
	else return strcmp((*(p*)a).k,(*(p*)b).k);
}
int main(){
	char cc;
	int cnt=0,cnt2=0,cnt3=0;
	p s[500];
	int f=0;
	int len=0;
	while(scanf("%c",&cc)!=EOF){
		if(cc=='\n') break;
		s[cnt].k[cnt2++]=cc;
		if(cc<='9' && cc>='0'){
			if(f==0){
				f=1;
				s[cnt].d=len;
				s[cnt].num[cnt3++]=cc;
				s[cnt].num2=cc-'0';
			}
			else{
				s[cnt].num[cnt3++]=cc;
				s[cnt].num2=s[cnt].num2*10+cc;
			}
		}		
		else if(cc==' '){
			if(f==0){
				s[cnt].num2=-1;
				s[cnt].num[0]=' ';
				s[cnt].d=-1;
			}
			f=0;
			cnt++;
			cnt3=0;
			len=0;
			cnt2=0;
		}
		else{
			s[cnt].a[len++]=cc;
		}
	}
	if(f==0){
		s[cnt].num2=-1;
		s[cnt].num[0]=' ';
		s[cnt].d=-1;
	}
	f=0;
	cnt++;
	len=0;
	qsort((void *)s,cnt,sizeof(s[0]),strnumcmp);
	for(int i=0;i<cnt;i++){
		for(int j=0;j<=strlen(s[i].a);j++){
			if(j==s[i].d) printf("%s",s[i].num);
			if(j!=strlen(s[i].a))printf("%c",s[i].a[j]);
		}
		printf(" ");
	}
}
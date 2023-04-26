#include <stdio.h>
#define size 80
typedef struct{
	char num[size];
	int cnt;
}data;
int main(){
	char s[size+1];
	while(scanf("%s",s)!=EOF){
		data r[2*size+1];
		int i,j,k=size;
		for(i=0;i<2*size+1;i++){
			for(j=0;j<size;j++){
				r[i].num[j]=' ',r[i].cnt=0;
			}
		}
		r[k].num[0]=s[0],r[k].cnt=1;
		for(i=1;s[i];i++){
			if(s[i-1]<s[i]){
				k--;
				r[k].num[i]=s[i],r[k].cnt=i+1;
			}else if(s[i-1]>s[i]){
				k++;
				r[k].num[i]=s[i],r[k].cnt=i+1;
			}else{
				r[k].num[i]=s[i],r[k].cnt=i+1;
			}
		}
		for(i=0;i<2*size+1;i++){
			if(r[i].cnt){
				for(j=0;j<r[i].cnt;j++){
					printf("%c",r[i].num[j]);
				}
				printf("\n");
			}
		}
	}
} 
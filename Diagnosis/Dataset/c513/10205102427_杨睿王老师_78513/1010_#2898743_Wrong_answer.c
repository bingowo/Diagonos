//1010
#include <stdio.h>
int main(){
	char ch;
	char s[510];
	int l=0,lq=0,lt=0;
	int tmp[200],tmpp,tmpt[10],len[11],le=0;
	for(int j=0;j<200;j++){
		tmp[j]=0;
		tmpt[j]=0;
		len[j]=0;
	}
	int flag=0;
	while((ch=getchar())!='\n'){
		s[l]=ch;
		l++;
		if((l-1)%3==2){
			flag=1;
			tmp[lq]=(int)s[l-1]-48+((int)s[l-2]-48)*10+((int)s[l-3]-48)*100;
			//printf("\ntest:%d\n",tmp[lq]);
			lq++;
		}
	}
	//printf("test%d\n",flag);
	printf("0001");
//	printf("\n");
	int ll=l;
	while(ll>0){
		len[le]=ll%2;
		le++;
		ll/=2;
	}
	for(int j=10;j>=0;j--){
		printf("%d",len[j]);
	}
//	printf("\n");
	int i=0;
	for(i=0;i<lq;i++){
		if(flag==0) break;
		int tmpn[11],ln=0;
		for(int e=0;e<11;e++){
			tmpn[e]=0;
		}
		while(tmp[i]>0){
			tmpn[ln]=tmp[i]%2;
			ln++;
			tmp[i]/=2;
		}
		for(int e=9;e>=0;e--){
			printf("%d",tmpn[e]);
		}
//		printf("//");
	}
//	printf("\n");
	if(l%3==2){
		tmpp=(int)s[l-1]-48+((int)s[l-2]-48)*10;
		while(tmpp>0){
			tmpt[lt]=tmpp%2;
			lt++;
			tmpp/=2;
		}
		for(int e=6;e>=0;e--){
			printf("%d\n",tmpt[e]);
		}
	}
	if(l%3==1){
		tmpp=(int)s[l-1]-48;
		tmpt[lt]=tmpp%2;
		lt++;
		tmpp/=2;
		for(int e=3;e>=0;e--){
			printf("%d\n",tmpt[e]);
		}		
	}	
}
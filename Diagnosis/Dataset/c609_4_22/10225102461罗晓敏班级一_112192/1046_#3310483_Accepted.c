#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char c;
	int cnt;
}PAIR;
PAIR num[100000][100];
int issame(PAIR num[][100],int n,int count){
	int i,k;
	for(i=0;i<count;i++){
		for(k=0;k<n-1;k++){
			if(num[k][i].c!=num[k+1][i].c){
				return 0;
			}
		}
	}
	return 1;
}
int column;
int cmp(const void* a,const void* b){
	PAIR* aa=(PAIR*)a;PAIR* bb=(PAIR*)b;
	return (aa+column)->cnt-(bb+column)->cnt;
}
int ret(PAIR num[][100],int n,int count){
	int i,ret=0;
	for(i=0;i<count;i++){
		column=i;
		qsort(num,n,100*sizeof(PAIR),cmp);
		int j,z;
		if(n%2){
			z=num[n/2][i].cnt;
		}else{
			z=(num[n/2][i].cnt+num[n/2-1][i].cnt)/2;
		}
		for(j=0;j<n;j++){
			ret+=abs(num[j][i].cnt-z);
		}
	}
	return ret;
}
int main() {
	int n;scanf("%d",&n);
	int i,count=0,co=0;
	for(i=0;i<n;i++){
		char s[101];scanf("%s",s);
		int k;
 		for(k=0;k<100;k++){
 			num[i][k].cnt=1;
 		}count=0;
 		for(k=0;s[k];k++){
 			if(s[k]!=s[k+1]){
 				num[i][count++].c=s[k];
 			}else{
  				num[i][count].cnt++;
 			}
 		}
 		if(co<count){
 			co=count;
		}
 	}
	if(issame(num,n,co)==0){              //不要传入count，count是最后一个字符串的count 
		printf("-1");
	}else{
		printf("%d",ret(num,n,co));
	}
 	return 0;
}
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char alpha[]="0123456789ABCDEF";  //十六进制 
	long long int T,r,n,m,i,j,z;
	char result[100];
	scanf("%lld",&T);
	for(i=0;i<T;i++){
		for(j=0;j<100;j++)result[j]='0';
		scanf("%lld%lld",&n,&r);  //输入每一组的数据
		printf("case #%lld:\n",i);
		m=0;z=0;
		while(n!=0){
			m+=(n%r);n=n/r;
		}  //计算数位和
		if(m<r){
			if(r<10)printf("%lld\n",m);
			else printf("%c\n",alpha[m]);
		}  //不需要进一步计算
		else if(m>=r){
			while(m!=0){
				j=m%r;m=m/r;
				result[z++]=alpha[j];
			}
			for(j=z-1;j>=0;j--){
				printf("%c",result[j]);
			}
			printf("\n");
		} 
	} 
	return 0;
}
#include<stdio.h>
// int main(){
// 	int t,n,r;
// 	scanf("%d",&t);

// 	for(int i=0;i<t;i++){
// 		scanf("%d %d",&n,&r);
// 		char a[105]={0},j=0;
// /*		char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"  */
// 		if(n<0)
// 			printf("-"),n=-n;

// 		do{
// 			if( (n%r) < 10 )
// 				a[j++] = n % r + '0';
// 			else
// 				a[j++] = n % r - 10 + 'A';
// //            a[j++] = table[n%r];
// 			n/=r;
// 		}while(n);
// 		for(int k=--j;k>=0;k--){
// 			printf("%c",a[k]);
// 		}
// 		printf("\n");
// 	}
// 	return 0;
// }
void trans(int n, int r){
	char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
	if(n>0){
		trans(n/r,r);
		printf("%c",table[n%r]);
	}
}
int main(){
	int t,n,r;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d%d",&n,&r);
		char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" ; 
		
		if(n<0)
			printf("-"),n=-n;
		if(n==0)
			putchar('0');
		else
			trans(n,r);
		printf("\n");
	}
	return 0;
}
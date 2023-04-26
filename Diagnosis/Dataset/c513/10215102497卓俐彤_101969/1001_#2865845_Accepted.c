#include <stdio.h>
#include <stdlib.h>

printout(int a){
    if(a<10)printf("%c",'0'+a);
    else printf("%c",'A'+a-10);
}

divi(int n,int r){
    if(n/r!=0){
        divi(n/r,r);
    }
    printout(n%r);
}




int main(){
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
        int n,r;
        scanf("%d %d",&n,&r);
        if(n<0){
            n*=(-1);
            printf("-");
        }
        divi(n,r);
        printf("\n");
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void count(int * r,int n)
{
    int c,i,t;
    for(i=0;i<n;i++){
        t=r[i]*r[i]+c;
        c=t/10;
        r[i]=t%10;
    }


}

int main(){
	int T,i;
	scanf("%d",&T);
	for(i=0;i<T;i++){
	printf("case #%d:\n",i);
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	int r[n];
	for(int k=0;k<n;k++){
        r[k]=a%10;
        a=a/10;
	}
	for(int j=0;j<n-1;j++){
        count(r,n);
	}
	for(int k=n-1;k>=0;k--){
        printf("%d",r[k]);
	}
	printf("\n");

	}
}
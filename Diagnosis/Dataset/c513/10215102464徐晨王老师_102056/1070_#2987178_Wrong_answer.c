#include <stdio.h>
#include <stdlib.h>
int main(){
    long int a[20];
    a[0]=1;
    a[1]=2;
    a[2]=4;
    a[3]=7;
    a[4]=12;
    a[5]=21;
    int sign;
    for(int i=6;i<20;i++){
        a[i]=2*a[i-1];
        for(int j=i-3,sign=-1;j>=0;j-=2){
			a[i]=a[i]+sign*a[j];
			sign=-sign;
		}
    }
    int n;
    scanf("%d",&n);
    while(n!=-1){
        printf("%ld\n",a[n]);
        scanf("%d",&n);
    }
    return 0;
}
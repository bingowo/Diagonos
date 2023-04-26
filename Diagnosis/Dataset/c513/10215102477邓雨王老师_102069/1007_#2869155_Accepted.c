#include<stdio.h>
#include<string.h>
int main(){
    int chance;
    scanf("%d",&chance);
    int i;
    for(i=0;i<chance;i++){
        printf("case #%d:\n",i);
        int m;
        scanf("%d",&m);
        int n=0;
        int max=1;
        int sum=1;
        while(m>1){
		if((m%2)!=(m/2)%2){
			sum=sum+1;
			m=m/2;
			if(max<sum) max=sum;
		}
		else{
			sum=1;
			m=m/2;
		}
	}
	printf("%d\n",max);
	    
}
}
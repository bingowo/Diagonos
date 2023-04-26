#include<stdio.h>
#include<string.h>
int main(){
    int t;
    int n=0;
    int m,k;
    char a[123];
    scanf("%d",&t);
    while(n<t){
        scanf("%s",a);
        m=count(a);
        n++;
    }
}
int count(char* a){
    int i,k,j,m;
    int num=0;
    for(i=0;i<strlen(a);i++){
    	m=1;
    	k=i;
        for(j=0;j<k-1;j++){
        	if(a[i]==a[j]){
        		m=0;
			}			
		}
		if(m==1){
			num++;
		}
		
    }
    return num;
}
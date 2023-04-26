#include<stdio.h>
#include<stdlib.h>
int main(){
	char d;
	int a[1005]={0},t,ma=0,mi=1005;
	scanf("%c",&d);
	while(scanf("%d",&t)!=EOF){
		a[t]=1;
		if(t>ma) ma=t;
		if(t<mi) mi=t;
	}
	int i;
	if(d=='A'){
		for(i=0;i<=ma-1;i++){
			if(a[i]==1) printf("%d ",i);	
		}
		printf("%d",ma);
	}
	else{
		for(i=1005;i>mi;i--){
			if(a[i]==1) printf("%d ",i);
		}
		printf("%d",mi);
	}
}
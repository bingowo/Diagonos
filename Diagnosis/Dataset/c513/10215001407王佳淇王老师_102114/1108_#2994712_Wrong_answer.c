#include<stdio.h>
int main(){
	
	int T;
	scanf("%d",&T);
	for(int z=0;z<T;z++){
	int n,m;
     scanf("%d %d",&n,&m);
     int i=0,j,flag=0,a[10009]={0},h[10009]={0},b[10009]={0};
	 	printf("case #%d:\n",z);
	 	printf("0.");
	 while(n){
	 	i++;
        if (b[n]==0){
            b[n]=1;
            h[n]=i;
        }else{
        	flag=1;
            j=h[n];
            break;
        }
        n=n*10;
        a[i]=n/m;
        n=n%m;
	 }
	 int k=i;
	 if(flag){
	 	for(int p=1;p<k;p++) printf("%d",a[p]);
	 	printf("\n");
	 	printf("%d-%d",j,k-1);
	 }
	 else {
	 	for(int p=1;p<=k;p++) printf("%d",a[p]);
	 	printf("\n");
	 }
	}

} 
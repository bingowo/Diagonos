#include<stdio.h>
#include<math.h>
int main(){
	int T;
	scanf("%d",&T);
	for(int z=0;z<T;z++){
		printf("case #%d:\n",z);
	int a,count=0;
	for(int i=8;i>=0;i--){
      scanf("%d",&a);
   if(a!=0) count++;
        if(a){    
            if(i!=8&&a>0&&count>1)  printf("+");    
            if(abs(a)>1||i==0)   printf("%d",a);
            if(a==-1&&i)   printf("-"); 
            if(i>1)    printf("x^%d",i); 
            if(i==1)   printf("x"); 
        }
		
		}
		if(count==0) printf("0");
	printf("\n");		
		}
	return 0;
	
} 
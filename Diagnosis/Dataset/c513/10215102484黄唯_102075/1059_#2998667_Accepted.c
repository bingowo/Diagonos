#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a,const void *b){
	int a1 = *(int*)a;
	int b1 = *(int*)b;


	return (a1-b1);


} 

int gcd(int a,int b){
	if(a%b == 0)
	return b;
	else
	return gcd(b,a%b);
}

int main(){
	int n,s,ans_int = 0,ans_fz = 0,ans_fm =0,com = 0,water = 0; //com是最大公因数 
	scanf("%d %d",&n,&s);
	int a[1001];

	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),cmp);
    a[n] = 1000001;
	for(int i =1; i <= n ;i++){
	
		water = i*(a[i]-a[i-1]);
		if(water >s){
		 
		  ans_int =a[i-1] + s/i;
		  com = gcd(s%i,i);
		  ans_fz = (s % i) / com;
		  ans_fm = i / com;
		  break;
		}
		else{
			
			s -= water;
		}
		
		
	}
	if(ans_int != 0){
		printf("%d",ans_int);
		if(ans_fz >0){
		printf("+");
		printf("%d/%d",ans_fz,ans_fm);
		 }
	}
	else{
		printf("%d/%d",ans_fz,ans_fm); 
	}
	return 0;
}

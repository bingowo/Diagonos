#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int func(int n){
  int sum=0,i=0,a[64],b[64],c[64],len=0,j;
  if(n>0){
  while(n>0){
  	if(n%2==0){
  		n=n/2;
	  }
	else{
		i++;
		n=n/2;
		sum++;
	}
  }
  }
  else if (n==0){
  	sum=0;
  }
  else {
  	n=-n;
  	while(n>0){
  		if(n%2==0){
  		a[i]=0;
  		i++;
  		n=n/2;
  		len++;
	  }
	else{
		a[i]=1;
		i++;
		n=n/2;
		len++;
	}}
	j=len-1;
	for(i=0;i<64-len;i++){
		b[i]=0;
	}
	for(i=64-len;i<64;i++){
		b[i]=a[j];
		j--;
	}
	for(i=0;i<64;i++){
		if(b[i]==0)c[i]=1;
		else c[i]=0;
	}
	for(i=63;i>0;i--){
		if(c[i]==0){
			c[i]=1;
			for(int m=63;m>i;m--){
				c[m]=0;
			}break;
		}
	}
	for(i=0;i<64;i++){
		if(c[i]==1)sum++;
	}
	}
	
	return sum;
  }
int b_sort(int a[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(func(a[j])<func(a[j+1])){
			swap(&a[j],&a[j+1]);
		}	
		}
	}
	for(int i=0;i<n;i++){
		if(func(a[i])==func(a[i+1])&&a[i]>a[i+1])
		swap(&a[i],&a[i+1]);
	}
}

int main(){
  int T,N,a[10001],i,j,b[10][10001],k;
  scanf("%d",&T);
  for(i=0;i<T;i++){
  	scanf("%d",&N);
	  for(j=0;j<N;j++){
	  	scanf("%d",&a[j]);}
	  	b_sort(a,N);
		for(k=0;k<N;k++){
	    b[i][k]=a[k];}
	      
  }
  for(i=0;i<T;i++){ 
  printf("case #%d :\n",i);
  for(j=0;j<N;j++){
  	printf("%d ",b[i][j]);
  }
  printf("\n");
  }
	return 0;
}

#include<stdio.h>
int main(){
	int t,i,j,x,y,k,count,n=0,l;
	scanf("%d\n",&t);
	int a[t],b[2147483648],c[2147483648];
	for(i=0;i<t;i++) scanf("%d\n",&a[i]);
	for(i=0;i<t;i++){
		printf("case #%d\n",i);
		y=a[i];
		j=0;
		while(y!=0){
			x=y%2;
			y=y/2;
			b[j]=x;
			j++;
		}
		for(k=0;k<j-1;){
			count=1;
			while(b[k]!=b[k+1]){
				count++;
				k++;
			}
			k++;
			c[n]=count;
			n++;
		}
	}
	for(i=0;i<n-1;i++){
		l=c[0];
		if(c[i]<c[i+1]) l=c[i+1];
	}
	return 0;
} 
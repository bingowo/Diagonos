#include<stdio.h>
#include<string.h> 
int main()
{
	int n,r,i,j,a[32];
	scanf("%d%d",&n,&r);
	for(i=0;n!=0;i++){
		if(n%r<0){
			a[i]=n-(n/r+1)*r;
			n=n/r+1;}
		else {
		a[i]=n%r;
		n=n/r;}
	}
	for(j=0;j<i;j++){
		if(a[i-1-j]<10)printf("%d",a[i-1-j]);
		else printf("%c",a[i-1-j]+55);
	}
}
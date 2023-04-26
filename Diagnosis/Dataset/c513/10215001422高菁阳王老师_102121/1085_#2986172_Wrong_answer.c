#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void minus(int a[],int b[]){
	int i,l;
	for(i=500;i>=0;i--){
		l=a[i]-b[i];
		if(l<0){
			a[i]=l+10-b[i];
			a[i-1]--;}
		else a[i]=l;
	}
	
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[501]={0},b[501]={0},k=0,x;
	char s1[501],s2[501];
	scanf("%s%s",s1,s2);
	int i1,k1,i2,k2,len1=strlen(s1),len2=strlen(s2);
	for(i1=500,k1=len1-1;k1>=0;i1--,k1--)
    a[i1]=s1[k1]-'0';	
	for(i2=500,k2=len2-1;k2>=0;i2--,k2--)
    b[i2]=s2[k2]-'0';
    if(len1<len2) {
	minus(b,a);
    while(b[k]==0) k++;
       for(x=k;x<501;x++){
	   printf("-");
	printf("%d",b[x]);}
	printf("\n");
	}
    if(len1==len2&&a[i1]<b[i1]) {
	minus(b,a);
     while(b[k]==0) k++;
       for(x=k;x<501;x++){
	   printf("-");
	printf("%d",b[x]);}
	printf("\n");
	}
    minus(a,b);
     while(b[k]==0) k++;
       for(x=k;x<501;x++){
	printf("%d",a[x]);}
	printf("\n");
	return 0;
}
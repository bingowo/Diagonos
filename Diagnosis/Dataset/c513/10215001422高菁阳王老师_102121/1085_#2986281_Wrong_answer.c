#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void minus(int a[],int b[]){
	int i;
	for(i=500;i>=0;i--){
	
		a[i]-=b[i];
	    if(a[i]<0){
			a[i]+=10;
			a[i-1]-=1;		}
  }
	
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[501]={0},b[501]={0},k=0,x;
	char s1[501],s2[501];
	while(scanf("%s%s",s1,s2)!=EOF){
	int i1,k1,i2,k2,len1=strlen(s1),len2=strlen(s2);
	for(i1=500,k1=len1-1;k1>=0;i1--,k1--)
    a[i1]=s1[k1]-'0';	
	for(i2=500,k2=len2-1;k2>=0;i2--,k2--)
    b[i2]=s2[k2]-'0';
    if(len1<len2) {
	minus(b,a);
	 printf("-");
    while(b[k]==0) k++;
       for(x=k;x<501;x++){
	printf("%d",b[x]);}
	printf("\n");
	}
    if(len1==len2&&s1[0]<s2[0]) {
	minus(b,a);
	 printf("-");
     while(b[k]==0) k++;
       for(x=k;x<501;x++){
	printf("%d",b[x]);}
	printf("\n");
	}
    else {
	minus(a,b);
     while(a[k]==0) k++;
       for(x=k;x<501;x++){
	printf("%d",a[x]);}
	printf("\n");
    }
	}
	return 0;

}

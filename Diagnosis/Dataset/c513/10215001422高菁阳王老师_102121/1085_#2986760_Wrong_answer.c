#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(int a[],int b[]){
	int i;
	for(i=0;i<=500;i++){
		if (a[i]<b[i]) return -1;
	    
	}
	
}

void minus(int a[],int b[]){
	int i,j;
	for(i=500;i>=0;i--)
	a[i]-=b[i];
	    for(j=500;j>=0;j--){
		
		if(a[j]<0){
			a[j]+=10;
			a[j-1]-=1;		}
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
   k=500-len2;
    while(b[k]==0) k++;
       for(x=k;x<501;x++){
	printf("%d",b[x]);}
	printf("\n");
	}
    else if(len1==len2&&cmp(a,b)==-1) {
	minus(b,a);
	 printf("-");
    k=500-len1;
	 while(b[k]==0) k++;
       for(x=k;x<501;x++){
	printf("%d",b[x]);
	}
	printf("\n");
	}
    else {
	minus(a,b);
    k=500-len1;
	 while(a[k]==0&&k<500) k++;
       for(x=k;x<501;x++){
	printf("%d",a[x]);
	}
	printf("\n");
    }
for(int c=0;c<501;c++){
	a[c]=0;
	b[c]=0;
}
	
	}
	return 0;

}
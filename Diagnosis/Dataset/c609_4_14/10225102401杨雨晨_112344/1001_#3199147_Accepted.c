#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define M 32


int main()
{   int t,i,p,m,n,r;
    int c[M];
    scanf("%d",&t);
    for (i=0;i<t;i++){
    	scanf("%d%d",&n,&r);
    	if (n<0){n=-n;printf("%c",'-'); }
        if(r<10){
            for(p=0;n/r!=0;p++){
				c[p]=n%r+'0';
				n=n/r;
			}
            c[p]=n+'0';
        }else {
            for(p=0;n/r!=0;p++){
            m=n%r;
            if (m<10){c[p]=m+'0';}
            else {c[p]=m-10+'A';}
            n=n/r;
        }
            if (n<10){c[p]=n+'0';}
            else{c[p]=n-10+'A';}
        }
		for (;p>=0;p--){
		printf("%c",c[p]);
		}printf("\n");
}}
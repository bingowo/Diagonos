#include<stdio.h>
#include<string.h>
int main(){
    int n,i,j,num,num1,len,mask;
    int k,q;
    unsigned char s[200];
    scanf("%d",&n);
    char c = getchar();	
    int m=0;
    while(m<n){
        num=0;
        gets(s);
        len=strlen(s);
        num1=8*len;
        for(i=0;i<len;i++){
        	for(j=0;j<16;j++){
        		mask=1<<j;
        		k=s[i];
        		int u=k&mask;
        		if(u!=0){
        			num+=1;
        			
				}
			}
		}
		printf("%d/%d\n",num,num1);
        m++;
    }
}


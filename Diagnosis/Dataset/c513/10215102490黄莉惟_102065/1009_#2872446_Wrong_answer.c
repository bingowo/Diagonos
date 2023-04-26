#include<stdio.h>
#include<string.h>
int main(){
    int n,i,j,num,num1,len;
    char s[200];
    scanf("%d",&n);
    char c = getchar();	
    int m=0;
    while(m<n){
        num=0;
        gets(s);
        len=strlen(s);
        for(i=0;i<strlen(s);i++){
            for (j=0;j<=7;j++){
		        if(((s[i]<<(7-j))>>7)==1) {
		            num=num+1;
		        }
            }
        }
        printf("%d",num);
        m++;
    }
}

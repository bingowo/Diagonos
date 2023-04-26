#include<stdio.h>
#include<ctype.h>
#include<string.h>
char b[16]="0123456789abcdef";
int main()
{
    for(int i=0;i<50;i++){
        char c[50];
        scanf("%s",c);
        int len=strlen(c);
        if(c[0]!='-'){
        for(int j=0;j<len;j++){
                if(isdigit(c[j])){ continue;}
                else 
            }
            int r=0;
            for(len=len-1;len>=0;len--){
                r+=r*10+c[len]-'0';
            }
            char f[11]="00 00 00 00";
            int k=0;
            while(r){
                int m=r%16;
                if(m<10){ 
                    k+=1;
                    f[k]=m;
                    if(k=11) break;
                    k+=2;}
                else{
                    k+=1;
                    f[k]=b[m];
                    if(k=11) break;
                    k+=2;
                }    
                r/=16;
            }
            printf("%s",f);
            }
        }
        else
    }
    return 0;
}
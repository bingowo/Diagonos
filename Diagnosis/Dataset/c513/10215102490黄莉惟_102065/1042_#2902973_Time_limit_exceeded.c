#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char char_comb[17]="";
void comb(char *s,int depth,int k){
    if(depth) printf("%s\n",char_comb);
    for(int i=k;s[i];i++){
        char_comb[depth]=s[i];
        char_comb[depth+1]=0;
        comb(s,depth+1,i+1);
    }
}
int main(){
    int t,k,j,r;
    scanf("%d",&t);
    int i;
    char s[17];
    char m;
    for(i=0;i<t;i++){
        scanf("%s",s);
        for(j=0;j<strlen(s)-2;j++){
            k=j;
            for(r=j+1;r<strlen(s);r++){
                if(s[r]<s[k]){
                   k=r; 
                   m=s[j];
                   s[j]=s[k];
                   s[k]=m;
                }
            }
            printf("%s",s);
        }
        
    }
}
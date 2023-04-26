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
    int i,num;
    char s[17];
    char m;
    char s1[20];
    for(i=0;i<t;i++){
        scanf("%s",s);
        for(j=0;j<strlen(s)-1;j++){
            for(r=0;r<strlen(s)-1-j;r++){
                if(s[r]>s[r+1]){
                   m=s[r+1];
                   s[r+1]=s[r];
                   s[r]=m;
                }
            }
           
        } 
        printf("%s\n",s);
       /* memset(s1,0,sizeof(s1));
        s1[0]=s[0];
        num=1;
        for(j=1;j<strlen(s);j++){
            if(s[j]!=s[j-1]){
                s1[num]=s[j];
                num++;
            }
        }
        printf("%s\n",s1);*/
        
    }
}
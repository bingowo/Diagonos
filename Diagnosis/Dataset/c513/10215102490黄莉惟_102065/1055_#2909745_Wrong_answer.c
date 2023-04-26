#include <stdio.h>
#include<string.h>
int main(){
    int i,j,num,r,k,t;
    char s[10000];
    char s1[10000];
    char s2[10000];
    scanf("%s",s);
    j=0;
    num=0;
    int max=0;
    for(i=0;i<strlen(s);i++){
        s1[j]=s[i];
        j++;
        num++;
        for(r=0;r<num-1;r++){
            if(s1[j]==s1[r]){
                if(num>max){
                    max=num;
                    for(k=0;k<num;k++){
                        s2[k]=s1[k];
                    }
                    
                }
                num=0;
                j=0;
            }
        }
    }
    for(i=0;i<max;i++){
        printf("%c",s2[i]);
    }
    
}

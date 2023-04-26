#include <stdio.h>
#include <string.h>
#include <string.h>
int main(){
    char igwd[7][3]={"the", "a", "an", "of", "for", "and"};
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char s[100];
        while(scanf("%s",s)!=EOF){
            int jq=0
            for(int i=0;i<6;i++){
                if(strcmp(s,igwd[i]))jp++;
            }
            
        }
    }
    
    
}
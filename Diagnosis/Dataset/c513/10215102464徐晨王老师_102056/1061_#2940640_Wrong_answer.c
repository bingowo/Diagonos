#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int N;
    scanf("%d",&N);
    for(int n=0;n<N;n++){
        char s[16];
        scanf("%s",s);
        int lens=strlen(s);
        char s1[256]={-1};
        s1[s[0]]=1;
        int ant=0;
        for(int i=1;i<lens;i++){
            if(s1[s[i]]==-1){
                s1[s[i]]=ant;
            if(ant==0)ant=ant+2;
            else ant=ant+1;
            }
        }
        int sum=1;
        for(int j=lens-1;j<=0;j--){
            sum=sum+ant*s1[s[j]];
        }
        printf("%d",sum);
    }
    return 0;
}
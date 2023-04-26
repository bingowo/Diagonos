#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int N;
    scanf("%d",&N);
    for(int n=0;n<N;n++){
        char s[16];
        char* ss;
        scanf("%s",s);
        int lens=strlen(s);
        int s1[128];
        for(int i=0;i<128;i++){
            s1[i]=-1;
        }
        //printf("%s",s1);
        ss=s;
        s1[*ss]=1;
        int ant=0;
        while(*++ss){
            if(s1[*ss]==-1){
                s1[*ss]=ant;
                if(ant==0)ant=ant+2;
                else ant=ant+1;

            }
            printf("%d\n",ant);
        }
        //printf("%s",s1);
        if(ant<2)ant=2;
        int sum=1;
        char* sss=s;
        while(*sss){
            sum=sum*ant+s1[*sss++];
        }
        printf("%d",sum);
    }
    return 0;
}
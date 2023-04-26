#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    long long int a=0,b=0,cnt =1;
    char s[50] = {0},s1[50]= {0},s2[50] ={0};
    int ret[1000000] = {0};
    scanf("%s",s);
    if(!strchr(s,'i')){
        a = atoll(s);
    }
    else{
        int c = 0;
        for(int i =1;i< strlen(s);i++){
            if(s[i] == 'i'){
                strncpy(s1,s+c,i-c);
                if(strlen(s1) == 1) {
                    if(s1[0] == '-'){
                        b = -1;
                    }else{
                        b = 1;
                    }
                }
                else{
                    b = atoll(s1);
                }
                break;
            }
            if( s[i] == '-' || s[i] == '+'){
                strncpy(s2,s+c,i-c);
                a = atoll(s2);
                c = i;
            }
        }
    }
    int j=0;
    do{
        int r;
        if((a&1)^(b&1)){
            r = 1;
        }
        else{
            r =0;
        }
        ret[j++] = r;
        long long int a1= a;
        a  = (-a+b+r)/2;
        b = (-a1-b+r)/2;
    }while(a!=0 ||b!=0 );
    for(j = j-1;j>=0;j--){
        printf("%d",ret[j]);
    }
    return 0;
}

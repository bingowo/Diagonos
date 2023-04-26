#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double get(int a){
    double ret=1;
    while(a--){
        ret/=8;
    }
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    int idx=0;
    while(t--){
        char s[52];
        scanf("%s",s);
        double ret;
        int digit=1;
        for(int i=2;i<strlen(s);i++){
            ret+=(s[i]-'0')*get(digit);
            digit++;
        }
        printf("case #%d:\n%lf\n",idx++,ret);
    }
}
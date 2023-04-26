#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long double get(char a,int b){
    long double ret=a;
    int eight=1;
    while(b--){
        eight*=8;
    }
    return ret/eight;
}
int main(){
    int t;
    scanf("%d",&t);
    int idx=0;
    while(t--){
        char s[52];
        scanf("%s",s);
        long double ret=0;
        int digit=1;
        for(int i=2;i<strlen(s);i++){
            ret+=get(s[i]-'0',digit);
            digit++;
        }
        printf("case #%d:\n%llf\n",idx++,ret);
    }
}
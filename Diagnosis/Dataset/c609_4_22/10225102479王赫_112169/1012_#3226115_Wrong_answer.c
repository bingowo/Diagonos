#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    int T;
    scanf("%d",&T);
    double r=0.0;
    for(int i=0;i<T;i++){
        char s[52];
        scanf("%s",s);
        int len=strlen(s);
        for(int j=2,k=1;j<len,k<len-2;j++,k++){
        r+=(s[j]-'0')*pow(8,-k);    
        }
        printf("case #%d:\n%d",i,r);
    }
    return 0;
}
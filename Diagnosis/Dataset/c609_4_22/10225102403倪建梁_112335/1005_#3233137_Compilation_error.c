#include <stdio.h>
#include <string.h>
int char_to_int(char c){
    if (c=='-') return -1;
    if (c=='0') return 0;
    if (c=='1') return 1;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int sum=0,power=1;char s=[100];
        int len=strlen(s);
        for (int j=len-1;j>=0;j--){
            int num=char_to_int(s[j]);
            sum += num * power;
            power *= 3;
        }
        printf("case #%d:\n%d\n",i,sum);
        return 0;
    }
}
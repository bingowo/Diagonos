#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{

    char s[501];
    scanf("%s",&s);
    int len=strlen(s);
    char lenn[11]="0000000000";
    int len1=len;
    for(int i=9;i>=0;i--){
        if(len1%2==1){lenn[i]='1';}
        len1/=2;
    }
    printf("0001");
    printf("%s",lenn);
    int j=0;
    for(;j+3<len;j+=3){
        char tmp[11]="0000000000";
        int sum;
        sum=100*(s[j]-48)+10*(s[j+1]-48)+s[j+2]-48;
        for(int i=9;i>=0;i--){
            if(sum%2==1){tmp[i]='1';}
            sum/=2;
        }
        printf("%s",tmp);
    }
    if((j+2)==len){
        char tmpp[8]="0000000";
        int summ;
        summ=10*(s[j]-48)+s[j+1]-48;
        for(int i=6;i>=0;i--){
            if(summ%2==1){tmpp[i]='1';}
            summ/=2;
        }
        printf("%s",tmpp);
    }
    if((j+1)==len){
        char tmppp[5]="0000";
        int summm;
        summm=s[j]-48;
        for(int i=3;i>=0;i--){
            if(summm%2==1){tmppp[i]='1';}
            summm/=2;
        }
        printf("%s",tmppp);

    }

    return 0;
}

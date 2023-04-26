#include <stdio.h>
#include <string.h>

void myprint(int num, int len)
{
    if(len==3){
        int result[10]={0,0,0,0,0,0,0,0,0,0};
        int cet=9;
        while (num!=0){
            result[cet--]=num%2;
            num/=2;
        }
        for(int i=0;i<10;i++)
            printf("%d",result[i]);
    } else if(len==2){
        int result[7]={0,0,0,0,0,0,0,0};
        int cet=6;
        while (num!=0){
            result[cet--]=num%2;
            num/=2;
        }
        for(int i=0;i<7;i++)
            printf("%d",result[i]);
    } else if(len==1){
        int result[4]={0,0,0,0};
        int cet=3;
        while (num!=0){
            result[cet--]=num%2;
            num/=2;
        }
        for(int i=0;i<4;i++)
            printf("%d",result[i]);
    }
}

int main() {
    char s[501];
    scanf("%s",s);
    int len= strlen(s);
    int num=len/3;int r = len%3;int sum=0;
    printf("0001");
    myprint(len,3);
    for(int i=0;i<num;i++){
        for(int j=0;j<3;j++){
            sum=10*sum+s[3*i+j]-'0';
        }
        myprint(sum,3);
        sum=0;
    }
    for(int i=3*num;i<len;i++){
        sum=10*sum+s[i]-'0';
    }
    myprint(sum,r);
    printf("\n");
    return 0;
}

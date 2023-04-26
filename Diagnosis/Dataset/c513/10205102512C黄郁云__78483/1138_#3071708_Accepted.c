#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int differ_decimal(char* s,int ini,int length){
    int sum = 0;
    for(int i = 0; i< length;i++){
        if(s[i] == 'A'||s[i] == 'a'){
            sum = sum*ini+10;
        }else if(s[i] =='B'|| s[i] == 'b'){
            sum=sum*ini+11;
        }else if(s[i] =='C' || s[i] == 'c'){
            sum=sum*ini+12;
        }else if(s[i] =='D'||s[i] == 'd'){
            sum=sum*ini+13;
        }else if(s[i] =='E'||s[i] == 'e'){
            sum=sum*ini+14;
        }else if(s[i] == 'F'||s[i] == 'f'){
            sum=sum*ini+15;
        }else if(s[i] >= '0' && s[i]<='9'){
            sum=sum*ini+s[i] -'0';
        }

    }
    return sum;


}

char ANS[1000];

void decvoidal_final(int decimal,int change){
    int largest_power = (log(decimal)/log(change));
    //printf("%d\n",largest_power);
    int digit = 0;
    for(int i = largest_power;i>=0;i--){
        if(decimal >=0){
            int now=(decimal/pow(change,i));
            decimal=decimal-now*pow(change,i);
            //printf("%d\n",now);
            if( now>=9){
                if(now == 10){
                     ANS[digit++] = 'A';
                }else if(now == 11){
                     ANS[digit++] = 'B';
                }else if(now == 12){
                     ANS[digit++] = 'C';
                }else if(now == 13){
                     ANS[digit++] = 'D';
                }else if(now == 14){
                     ANS[digit++] = 'E';
                }else if(now == 15){
                     ANS[digit++] = 'F';
                }
            }else{
                ANS[digit++] = now+'0';
            }


        }else{
            ANS[digit++] = '0';
        }


    }

}



int main(){
    int ini = 0;
    scanf("%d",&ini);
    char S[1000];
    scanf("%s",S);
    int change = 0;
    scanf("%d",&change);
    int length = strlen(S);

    int decimal = differ_decimal(S,ini,length);
    if(decimal == 0){
        printf("0");
    }else {
    //printf("%d\n",decimal);
    decvoidal_final(decimal,change);
    printf("%s",ANS);
    }




}


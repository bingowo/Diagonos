#include<stdio.h>
#include<string.h>

int search(char sym1, char sym2, char*cmplx, int len){
    for(int i = 1; i != len; i++)
        if (cmplx[i] == sym1 || cmplx[i] == sym2) return i;
    return -1;
}

int main(){
    char cmplx[50];
    scanf("%s", cmplx);
    int len = strlen(cmplx);
    int aflag = 0, bflag = 0;
    if (cmplx[len - 1] != 'i'){
        bflag = len;
        aflag = len;
    }
    else if (cmplx[0] == '-'){
        if (search('-', '+', cmplx, len) == -1)
            aflag = 0;
            bflag = 0;
    }
    else if (search('-', '+', cmplx, len) == -1){
        aflag = 0;
        bflag = 0;
    }
    else
        bflag = aflag = search('-', '+', cmplx, len);
    
    int aneg = 0;
    long long int a = 0;
    for (int i = 0; i < aflag; i++){
        if (cmplx[i] == '-') {aneg = 1; continue;}
        a = 10 * a + (cmplx[i] - '0');
    }
    if (aneg) a = -a;
    
    int bneg = 0;
    long long int b = 0;
    if (len == 1 && a == 0 && cmplx[0] != '0') b = 1;
    for (int i = bflag; i < len-1; i++){
        if (cmplx[i] == '-'){
            if(i >= len-2) b = 1;
            bneg = 1;
            continue;
        }
        else if (cmplx[i] == '+'){
            if (i >= len-2) b = 1;
            continue;
        }
        b = 10 * b + (cmplx[i] - '0');
    }
    if (bneg) b = -b;
    
    int mod[200], index = 199;
    while(a || b){
        long long int temp1 = (b-a)/2;
        long long int temp2 = (-a-b)/2;
        if (!((2*temp1==(b-a)) && (2*temp2==(-a-b)))){
            long long int temp = a;
            a = (1 + b - a) / 2;
            b = (1 - temp - b) / 2;
            mod[index--] = 1;
        }
        else{
            a = temp1;
            b = temp2;
            mod[index--] = 0;
        }
    }
    for (int i = index+1; i < 200; i++)
        printf("%d", mod[i]);
    return 0;
}
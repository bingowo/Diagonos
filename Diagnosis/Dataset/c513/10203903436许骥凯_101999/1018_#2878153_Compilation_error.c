#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>

void reverse(char *p, int len);
void itoa(int source, char *target){
    int index = 0;
    do{
        target[index++] = source % 10 + '0';
        source /= 10; 
    }while(source);
    target[index] = 0;
    reverse(target, index);
}

void makeTable(char *table[], int *prime);
int isPrime(int);
void calRes(char *res, int *num, char *table[], int nlen);

int main(){
    char* table[25] = {1,2,6,30,210,2310,30030,510510,9699690,223092870,
    6469693230,200560490130,7420738134810,304250263527210,13082761331670030,
    614889782588491410,32589158477190044730,1922760350154212639070,
    117288381359406970983270,7858321551080267055879090,557940830126698960967415390,
    40729680599249024150621323470,3217644767340672907899084554130
    ,267064515689275851355624017992790,23768741896345550770650537601358310};
    
    int primeExp[25];
    int idx = 0;
    char c;
    do{
        scanf("%d", &primeExp[idx++]);
    }while ((c = getchar() != '\n') && c != EOF);

    if (idx == 1) printf("%d\n", primeExp[0]);
    else{
        char res[200];
        calRes(res, primeExp, table, idx);
    }
    return 0;
}


void add(char *res, char *oldres);
void reverseInt(int *num, int len);
void calRes(char *res, int *num, char *table[], int len){
    
    reverseInt(num, len);
    res[0] = num[0] + '0'; res[1] = 0; 
    
    char copy[200];
    if (num[1] * 2 >= 10) {copy[0] = num[1] * 2 - 10 + '0'; copy[1] = '1'; copy[2] = 0;}
    else {copy[0] = num[1] * 2 + '0'; copy[1] = 0;}

    add(res, copy);

    strcpy(copy, res);
   

    for (int i = 2; i != len; i++){
        char temp[200];
        itoa(num[i], temp);
        calTable(res, temp, table, i+1);
        add(res, copy);
        strcpy(copy, res);
    }
    for (int i = 0; i != 25; i++)
        free(table[i]);
    printf("%s", res);
}

void reverseInt(int *num, int len){
    int lo = 0, hi = len-1;
    while (lo <= hi){
        int temp = num[lo];
        num[lo++] = num[hi];
        num[hi--] = temp;
    }
}

void add(char *res, char *oldres){
    int rlen = strlen(res);
    int olen = strlen(oldres);
    reverse(res, rlen);
    reverse(oldres, olen);

    int len = (rlen > olen)? olen: rlen;
    int carry = 0, sum = 0, i = 0;
    for (; i != len; i++){
        sum = carry + (res[i] - '0') + (oldres[i] - '0');
        carry = 0;
        if (sum >= 10){carry++; sum-=10;}
        res[i] = sum + '0'; 
    }
    for (; i <= rlen; i++){
        sum = carry + (res[i] - '0');
        carry = 0;
        if (sum >= 10){carry++; sum -= 10;}
        res[i] = sum + '0'; 
    }
    for (; i <= olen; i++){
        sum = carry + (oldres[i] - '0');
        carry = 0;
        if (sum >= 10){carry++; sum -= 10;}
        res[i] = sum + '0';
    }
    res[i] = 0;
    oldres[i] = 0;
    reverse(res, strlen(res));
}
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
    int prime[25] = {2};
    for (int i = 3, j = 1; j != 25; i += 2)
        if (isPrime(i)) prime[j++] = i;
    
    char* table[25];
    makeTable(table, prime);
    
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

int isPrime(int a){
    for (int i = 3; i <= sqrt(a) + 1; i++)
        if (!(a % i)) return 0;
    return 1;
}


int calTable(char *p, char *num, char *table[], int i);
void makeTable(char *table[], int *prime){
    char *p;
    int oldlen = 1;
    for (int i = 0; i != 25; i++){
        char temp[4];
        if (i == 1) {temp[0] = '1'; temp[1] = 0;}
        else itoa(prime[i-1], temp);
        int len = strlen(temp);
        p = (char*) malloc(sizeof(char) * oldlen * (len + 1) + 1);
        oldlen = calTable(p, temp, table, i);
        table[i] = p;
    }
}



int calTable(char *p, char *num, char*table[], int idx){
    if (idx == 0){p[0] = '1'; p[1] = 0; return 1;} 
    if (idx == 1){p[0] = '2'; p[1] = 0; return 1;}

    char *temp = table[idx-1];
    int index = 0;
    int nlen = strlen(num), tlen = strlen(temp);
    for (int i = nlen-1; i >= 0; i--){
        index = nlen - 1 - i;
        int carry = 0, sum = 0, j = tlen-1;
        for (; j >= 0; j--){
            if (i == nlen - 1) sum = carry + (num[i] - '0') * (temp[j] - '0');
            else sum = carry + (num[i] - '0') * (temp[j] - '0') + (p[index] - '0');
            carry = 0;
            while (sum >= 10){carry++; sum -= 10;}
            p[index++] = sum + '0';
        }
        if (carry) p[index++] = carry + '0';
        else p[index++] = '0';
    }
    p[index] = 0;
    reverse(p, index);
    int zi = 0;
    for (; zi != index; zi++)
        if (p[zi] != '0') break;
    int tf = 0;
    for (int i = zi; i != index; i++)
        p[tf++] = p[i];
    p[tf] = 0; 
    return index;
}

void reverse(char *p, int len){
    int lo = 0, hi = len - 1;
    while (lo <= hi){
        char temp = p[lo];
        p[lo++] = p[hi];
        p[hi--] = temp;
    }
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
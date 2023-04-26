#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(int *a, int num){
    int * p = a;
    int temp;
    for(int i = 0; i < num / 2; i++){
        temp = p[i];
        p[i] = p[num - i - 1];
        p[num - i - 1] = temp;
    }
}


void readnum(char *tempC, int *a, int* numOfA){
    char *pc = tempC;
    int num = 0, j = 0; //a has lenA elements, a[n] = num;

    while(*pc == '0' && *(pc+1) == ','){
        pc += 2;
    }
    while(*pc) {
        if(*pc == ','){
            a[j++] = num;
            num = 0;
        }
        else {num = num * 10 + *pc - '0';}
        *pc = '\0';
        pc++;
    }

    a[j++] = num;
    *numOfA = j;

}

int main()
{
    int prime[26] = {2,3,5,7,11,
        13,17,19,23,29,31,37,41,43,47,
        53,59,61,67,71,73,79,83,89,97,101};
    int a[26] = {0};

    int index[26];
    index[0] = 1;
    index[1] = 2;
    index[2] = 6;
    for(int i = 3; i < 26; i++){
        index[i] = index[i-1] * prime[i-1];
    }

    char temp[25000] = {'\0'};
    int numOfA[1] = {0};
    scanf("%s",temp);
    readnum(temp,a,numOfA);
    reverse(a,numOfA[0]);

    long long int ans = a[0] * index[0];
    for(int i = 1; i < 26; i++){
        ans += a[i] * index[i];
    }

    printf("%lld",ans);

    return 0;
}

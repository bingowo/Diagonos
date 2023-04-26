#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 500

typedef struct{
    int f[1001];
}BIG;


BIG s2big(char *s, int len){
    BIG a = {{0}};
    int i = 0;
    while(s[i] != '\0' && s[i] != '.') i++;

    for(int j = 0; j < i; j++)
        a.f[M - i + j + 1] = s[j] - '0';
    for(int j = i + 1; j < len; j++)
        a.f[M + j - i] = s[j] - '0';
    return a;
}

int cmp(BIG a, BIG b){
    int ret;
    for(int i = 0; i <= 2*M; i++){
        if(a.f[i] != b.f[i]){
            ret = a.f[i] > b.f[i] ? 1 : -1;
            break;
        }
        else if(i == 2*M) ret = 0;
    }
    return ret;
}

BIG minus(BIG a, BIG b, int n, int flag){
    BIG r = {{0}};
    if(flag == 0) return r;

    int temp, carry = 0;
    for(int i = 2*M; i > M + n; i--){
        temp = a.f[i] - b.f[i];
        if(flag > 0) temp += carry;
        else temp = carry - temp;

        if(temp < 0){
            temp += 10;
            carry = -1;
        }
        else carry = 0;

        r.f[i] = temp % 10;
    }

    if(r.f[M + n + 1] > 5) carry++;

    for(int i = M + n; i >= 0; i--){
        temp = a.f[i] - b.f[i];
        if(flag > 0) temp += carry;
        else temp = carry - temp;

        if(temp < 0){
            temp += 10;
            carry = -1;
        }
        else carry = 0;

        r.f[i] = temp % 10;
    }

    return r;
}


int main()
{
    char s1[2*M+1], s2[2*M+1];
    int n;
    scanf("%s%s%d",s1,s2,&n);

    BIG a = s2big(s1,strlen(s1)), b = s2big(s2,strlen(s2)), r;
    int flag = cmp(a,b);
    r = minus(a,b,n,flag);


    //print
    if(flag == -1) printf("-");

    int i = 0;
    while(i <= M && r.f[i] == 0) i++;
    if(i == M + 1) printf("0.");
    else{
       while(i < M + 1)
            printf("%d",r.f[i++]);
       printf(".");
    }

    while(i <= M + n) printf("%d",r.f[i++]);

    return 0;
}

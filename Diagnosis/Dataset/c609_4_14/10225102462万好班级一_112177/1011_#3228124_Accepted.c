#include <stdio.h>



long long int sov_int(const char* arr){
    long long int ansi = 0;
    for (int j = 0;arr[j] != '\0'; ++j) {
        if(arr[j] == '.')break;
        switch(arr[j]){case '1':ansi = ansi*3 + 1;
            break;case '0':ansi = ansi*3 + 0;break;
            case '2':ansi = ansi*3 - 1;break;}
}return ansi;}

long long int sov_flo(const char* arr,int flag){
    long long int ansf = 0;
    for (int j = flag + 1;arr[j] != '\0'; ++j) {
        switch(arr[j]){case '1':ansf = ansf*3 + 1;
                break;case '0':ansf = ansf*3 + 0;break;
            case '2':ansf = ansf*3 - 1;break;}
}return ansf;}

int count_float(const char* arr){
    int i;
    for ( i = 0; arr[i] != '\0'; ++i) {
        if(arr[i] == '.') return  i;
    }return 0;
}

int base(const char* arr){int i = 0;
    for (;arr[i] != '\0'; ++i) {}
    int j = count_float(arr);
    return i - j - 1;
}

long long int acm(long long int a, long long int b){
    long long int divi;
    while (a%b)
    {divi = a % b;a = b;b = divi;}
    divi = b;return divi < 0 ? -divi:divi;
}

int main() {
    char arr[100];
    scanf("%s",arr) ;

    int flag = count_float(arr);
    long long int inp = sov_int(arr);
    if(flag == 0) {printf("%lld",inp);return 0;}
    else{
        int loop = base(arr);long long int bas = 1;
        while(loop--)bas = bas*3;
        long long int flp = sov_flo(arr,flag);
        if(inp == 0)printf("%lld %lld",flp/acm(flp,bas),bas/acm(flp,bas));
        else if(inp > 0 && flp > 0){
            printf("%lld %lld %lld",inp,flp/acm(flp,bas),bas/acm(flp,bas));
        }else if(inp < 0 && flp < 0){
            printf("%lld %lld %lld",inp,-flp/acm(flp,bas),bas/acm(flp,bas));
        }else if(inp > 0 && flp <0 ){
            printf("%lld %lld %lld",inp - 1,bas/acm(flp,bas) + flp/acm(flp,bas),
                   bas/acm(flp,bas));
        }else if(inp < 0 && flp > 0){
            printf("%lld %lld %lld",inp + 1,bas/acm(flp,bas) - flp/acm(flp,bas),
                   bas/acm(flp,bas));
        }
    }
}

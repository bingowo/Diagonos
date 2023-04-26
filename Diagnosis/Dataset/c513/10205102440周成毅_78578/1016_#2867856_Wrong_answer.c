#include <stdio.h>

int trans(char *s, int N, int R) {
    int num = 49, bit;
    float tmp1, tmp2;
    while (N != 0) {
        if ((N ^ R) < 0) {
            tmp1 = N * 1.0 / R;
            tmp2 = tmp1 - N / R;
            bit = tmp2 * R;
            bit = bit >= 0 ? bit:-bit;
            N/=R;
            if(bit<10)
                s[num--]=bit+'0';
            else
                s[num--]=bit+'A'-10;
        } else{
            tmp1=N*1.0/R;
            tmp2=tmp1-N/R;
            tmp2=tmp2>0? tmp2:-tmp2;
            if(tmp2!=0) tmp2=1-tmp2;
            bit=tmp2*(-R);
            N/=R;
            if(bit!=0) N++;
            if(bit<10)
                s[num--]=bit+'0';
            else
                s[num--]=bit+'A'-10;
        }
    }
    num++;
    return num;
}

int main() {
    int N, R,i;
    scanf("%d %d", &N, &R);
    char result[50];
    i=trans(result, N, R);
    for(;i<50;i++)
        printf("%c",result[i]);
    printf("\n");
    return 0;
}

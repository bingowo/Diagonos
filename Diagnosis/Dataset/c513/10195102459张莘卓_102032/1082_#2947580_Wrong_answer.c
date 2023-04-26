#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* set_array(int* ai, int* af, char *num) {
    int  i=0, *len = (int*)malloc(2*sizeof(int));
    char* p = strchr(num, '.');
    int l = strlen(num);
    if(p == NULL) {
        for(i=0; num[i]; ++i)
            ai[l-1-i] = num[i] - '0';
        len[0] = l;  len[1] = 0;
    }else if(p == num){
        for(p=p+1; *p; ++p) af[i++] = *p - '0';
        len[0] = 0; len[1] = l-1;
    }else {
        for(i=0; p>num; ++i, --p)
            ai[i] = *(p-1) - '0';
        len[0] = i;
        p = strchr(num, '.') + 1;
        for(i=0; *p; ++i, ++p)
            af[i] = *p - '0';
        len[1] = i;
    }
    return len;
}

int main()
{
    int N;
    char fa[501], fb[501];
    scanf("%s %s %d",fa,fb,&N);
    int ai[500]={0}, af[500]={0}, bi[500]={0}, bf[500]={0};
    int *la = set_array(ai, af, fa);
    int *lb = set_array(bi, bf, fb);
    int len_int = *la < *lb ? *lb : *la;
    int len_dou = la[1] < lb[1] ? lb[1] : la[1];
    int carry = 0;
    for(int i=len_dou-1; i>=0; --i) {
        int t = af[i] + bf[i] + carry;
        af[i] = t % 10;
        carry = t / 10;
    }
    for(int i=0; i<len_int; ++i) {
        int t = ai[i] + bi[i] + carry;
        ai[i] = t % 10;
        carry = t / 10;
    }
    if(carry) ai[len_int++] = carry;
    if(af[N] > 4) {
        carry = 1; int i = N-1;
        while (carry && i>=0) {
            int t = af[i] + carry;
            af[i--] = t % 10;
            carry = t / 10;
        }
        i = 0;
        while(carry && i<len_int) {
            int t = carry + ai[i];
            ai[i++] = t % 10;
            carry = t / 10;
        }
        if(carry) ai[len_int++] = carry;
    }
    
    
    for(int i=len_int-1; i>=0; --i)
        printf("%d",ai[i]);
    if(len_int == 0) printf("0");
    printf(".");
    for(int i=0; i<N; ++i) printf("%d",af[i]);
    printf("\n");
    free(la);  free(lb);
    return 0;
}

#include <stdio.h>
#include <string.h>
int cal(long a){
    int n = 0;
    int B[64];
    memset(B,0,64 * 4);
    int *b = B + 63;
    if(a > 0){
        while(a != 0){
            *b = a % 2;
            a = a / 2;
            b--;
        }
    }else{
        a = -1 * a;
        while(a != 0){
            *b = a % 2;
            a = a / 2;
            b--;
        }
        b = B + 63;
        B[0] = 1;
        for(int i = 1;i < 64;i++){
            B[i] = B[i] == 1 ? 0 : 1;
        }
        if(B[63] == 0) B[63] = 1;
        else{
            while(*b == 1) {*b = 0;b--;}
            *b = 1;
        }

    }
    for(int i = 0;i < 64;i++){
            if(B[i] == 1) n++;
        }
    return n;
}

int com(const void *arg1, const void *arg2){
    long a = *(long*)arg1;
    long b = *(long*)arg2;
    int n1 = cal(a);
    int n2 = cal(b);
    if(n1 > n2) return 0;
    if(n1 < n2) return 1;
    return (a - b);
}

int main()
{
    int num;
    scanf("%d",&num);
    for(int i = 0;i < num;i++){
        int x;
        scanf("%d",&x);
        long arr[x];
        long *in = arr;
        for(int j = 0;j <x;j++){
            scanf("%ld",in);
            in++;
        }
        in = arr;
        qsort(arr,x,sizeof(int),com);
        printf("case #%d:\n",i);
        for(int i = 0;i < x;i++) printf("%ld ", arr[i]);
        printf("\n");
    }
}

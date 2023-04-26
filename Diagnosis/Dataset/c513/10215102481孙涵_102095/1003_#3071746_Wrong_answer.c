#include <stdio.h>
#include <stdlib.h>

struct data{
    long long int num;
    int num1;
};

int numOf1(long long int num);

int cmp(const void *a, const void * b);

int numOf12(long long int num);

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        int N;
        scanf("%d",&N);
        struct data s[10000];
        for(int i = 0; i < N; i++){
            scanf("%lld",&(s[i].num));
            if(s[i].num > 0){
                s[i].num1 =numOf1(s[i].num);
            }else if(s[i].num == 0){
                s[i].num1 = 0;
            }else{
                s[i].num1 = numOf12(s[i].num);
            }

        }
        qsort(s,N,sizeof(s[0]),cmp);
        printf("case #%d:\n",t);
        for(int i = 0; i < N - 1; i++){
            printf("%lld ",s[i].num);
        }
        printf("%lld\n",s[N-1].num);
    }
    return 0;
}


int numOf1(long long int num){
    int i = 0;
    while(num > 0){
        if(num & 1 == 1){
            i++;
        }
        num = num >> 1;
    }
    return i;
}

int numOf12(long long int num){
    int i = 0;
    int flag = 0;
    while(num != 0 && flag < 64){
        if(num & 1 == 1){
            i++;
        }
        num = num >> 1;
        flag++;
    }
    return i;
}

int cmp(const void *a, const void * b){
    struct data d1;
    struct data d2;
    d1 = (*(struct data *)a);
    d2 = (*(struct data *)b);
    if(d1.num1 != d2.num1){
        return d2.num1 - d1.num1;
    }else{
        return d1.num - d2.num;
    }
}

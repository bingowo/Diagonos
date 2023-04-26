#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cmp(const void *a, const void *b);

struct data{
    long long int num;
    int firstNum;
    int flag;
};

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        int N;
        scanf("%d",&N);
        struct data s[10001];


        for(int i = 0; i < N; i++){
            long long int temp;
            scanf("%lld",&temp);
            s[i].num = temp;
            if(s[i].num < 0){
                s[i].flag = -1;
            }else{
                s[i].flag = 1;
            }
            if(temp > -10 && temp < 10){
                s[i].firstNum = abs(temp);
            }else{
                while(abs(temp) >= 10){
                    temp = temp / 10;
                }
                s[i].firstNum = abs(temp);
            }
        }


        qsort(s,N,sizeof(s[0]),cmp);
        printf("case #%d:\n",t);
        for(int i = 0; i < N-1; i++){
            printf("%lld ",s[i].num);
        }
        printf("%lld\n",s[N-1].num);
    }

    return 0;
}



int cmp(const void *a, const void *b){
    struct data d1;
    struct data d2;
    d1 = (*(struct data*)a);
    d2 = (*(struct data*)b);
    if(d1.firstNum != d2.firstNum){
        return d2.firstNum - d1.firstNum;
    }else{
        if(d2.num > d1.num){
            return -1;
        }else{
            return 1;
        }
    }
}

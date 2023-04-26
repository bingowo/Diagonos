#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define M 65
#define N 38

typedef struct{
    unsigned long long int a;
    int one;
    int flag;
}NUM;

int count1(unsigned long long int a, int flag){
    /*case 1*/
    if(a == 0) return 0;

    //all positive
    int res = 0;

    for(int i = 0; i < M; i++){
        if((a & ((unsigned long long int)1 << i)) != 0) res++;
    }

    if(flag == -1) res = 64-res;

    return res;
}

int cmp(const void *a, const void *b){
    NUM c = *(NUM*)a, d = *(NUM*)b;
    if(c.one != d.one) return d.one - c.one;
    return c.a - d.a;
}

int main()
{
    int r,t;
    scanf("%d",&t);
    for(r = 0;r < t; r++){

        /*initialize*/
        long long int n;
        scanf("%lld",&n);

        NUM *num;
        num = malloc(sizeof(NUM)*n);
        memset(num,0,sizeof(NUM)*n);

        /*input*/
        for(int i = 0; i < n; i++){
            char s[N] = {'\0'};
            int cnt = 0;

            scanf("%s",s);
            if(s[0] == '-'){
                num[i].flag = -1;
                cnt++;
            }
            else num[i].flag = 1;

            while(cnt < strlen(s)){
                num[i].a = num[i].a*10 + s[cnt] - '0';
                cnt++;
            }

            num[i].one = count1(num[i].a,num[i].flag);
        }

        /*sort*/
        qsort(num,n,sizeof(NUM),cmp);

        /*output*/
        printf("case #%d:\n",r);
        if(num[0].flag == -1) printf("-%u",num[0].a);
        else printf("%u",num[0].a);
        for(int i = 1; i < n; i++){
            if(num[i].flag == -1) printf(" -%u",num[i].a);
            else printf(" %u",num[i].a);
        }
        printf("\n");
    }

    return 0;
}

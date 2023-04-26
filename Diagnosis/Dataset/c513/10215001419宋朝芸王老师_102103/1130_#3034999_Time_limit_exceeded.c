#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
    int up;
    int down;
}cre;

int cmp(const void*a,const void*b){
    cre x=*(cre*)a, y=*(cre*)b;
    return x.up-y.up;
}

int main()
{   cre b[20];
    int T;
    scanf("%d",&T);

    for(int i=0;i<T;i++){
        unsigned long long int a;
        scanf("%llu",&a);

        int f = 0,flag = 0;
        for(int k = 2;k <= sqrt(a);k++){
            int temp = log(a)/log(k);
            for(int j = 2;j <= temp+1;j++){
                if(pow(k,j) == a){
                    if(flag == 0) flag = 1;
                    b[f].down = k;
                    b[f++].up = j;
                }
            }
       }

       if(flag == 0) printf("%llu is powerless.\n",a);
       else{
            qsort(b,f,sizeof(b[0]),cmp);
            printf("%llu",a);
            for(int l = 0;l < f;l++) printf("=%d^%d",b[l].down,b[l].up);
            printf("\n");
       }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct{
    long long int up;
    long long int down;
}INDEX;

static int index[102];
static int power[65];
static INDEX in[100];
static int cnt = 0;

long long int Power(long long int x,long long int y){
    long long int ret = x;
    for(long long int i = 1;i <= y; i++) ret *= x;
    return ret;
}

void process(long long int a, long long int down, long long int up, int flag){
    if(a < 4) {
        printf("%lld is powerless.",a);return;
    }
    if(a <= 101 && index[a] == 1) {
        printf("%lld is powerless.",a);return;
    }

    if(down >= 2 && up >= 2){
        in[cnt].down = down;
        in[cnt++].up = up;
    }
    if(down <= 101 && index[down] == 1) return;

    for(long long int i = sqrt(down)+1; i > 1; i--){
        long long int temp = log(down)/log(i);
        if(down == pow(i,temp)){
            if(flag == 0) printf("%lld",a);

            if(power[up*temp] == 1) continue;
            process(a,i,up*temp,1);

            power[up*temp] = 1;
            flag = 1;
        }
    }
    if(flag == 0) {printf("%lld is powerless.",a);return;}
}

int cmp(const void *one, const void *two){
    INDEX a = *(INDEX*)one, b = *(INDEX*)two;
    return a.up - b.up;
}

int main()
{
    //initialize
    memset(index,0,102);
    index[1] = 0; index[2] = 1; index[3] = 1;
    index[5] = 1; index[7] = 1; index[11] = 1; index[13] = 1; index[17] = 1;
    index[19] = 1; index[23] = 1; index[29] = 1; index[31] = 1; index[37] = 1;
    index[41] = 1; index[43] = 1; index[47] = 1; index[53] = 1; index[59] = 1;
    index[61] = 1; index[67] = 1; index[71] = 1; index[73] = 1; index[79] = 1;
    index[83] = 1; index[89] = 1; index[97] = 1; index[101] = 1;

    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        long long int a;
        scanf("%lld",&a);

        memset(power,0,65);
        memset(in,0,100*sizeof(INDEX));
        cnt = 0;

        process(a,a,1,0);

        if(cnt != 0){
            qsort(in,cnt,sizeof(INDEX),cmp);
            for(int k = 0; k < cnt; k++)
                printf("=%lld^%lld",in[k].down,in[k].up);
        }

        printf("\n");
    }

    return 0;
}

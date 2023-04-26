#include <stdio.h>
#include <string.h>

void trans(long long *array) {
    for (int i = 9005; i > 0; i--) {
        array[i - 1] += array[i] / 10;
        array[i] %= 10;
    }
}

void multi(long long *array, int num,int len) {
    for (int i = 9005; i >= 0; i--) {
        array[i] *= num;
    }
    trans(array);
}

int main() {
    int T;
    long long num[9006];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int a,b,n;
        memset(num,0,sizeof (num));
        num[9005]=1;
        int res=9005,tmp,len=0;
        scanf("%d %d %d",&a,&b,&n);
        printf("case #%d:\n",i);
        tmp=a;
        while (tmp!=0){
            len++;
            tmp/=10;
        }
        for(int j=0;j<b;j++)
            multi(num,a,len);
        for(int j=9006-n;j<9006;j++)
            printf("%lld",num[j]);
        printf("\n");
    }
    return 0;
}

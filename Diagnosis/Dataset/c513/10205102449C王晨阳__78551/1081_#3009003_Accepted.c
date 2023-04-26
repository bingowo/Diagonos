#include <stdio.h>
#include <string.h>

void trans(int *array) {
    for (int i = 109; i > 0; i--) {
        array[i - 1] += array[i] / 10;
        array[i] %= 10;
    }
}

void multi(int *array, int num) {
    for (int i = 109; i > 0; i--) {
        array[i] *= num;
    }
    trans(array);
}

int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int a,n;
        int jj[110];
        memset(jj,0,sizeof (jj));
        scanf("%d %d",&a,&n);
        jj[99]=1;
        for(int j=0;j<n;j++)
            multi(jj,a);
        printf("case #%d:\n",i);
        int j=0;
        while (jj[j]==0)
            j++;
        for(;j<100;j++)
            printf("%d",jj[j]);
        printf("\n");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

/*int cal(int** a,int i,int j){
    int temp,res = 0;

    temp = a[i][j] > a[i-1][j-1] ? 0: 1;
    res = res*2 + temp;
    temp = a[i][j] > a[i-1][j] ? 0: 1;
    res = res*2 + temp;
    temp = a[i][j] > a[i][j+1] ? 0: 1;
    res = res*2 + temp;
    temp = a[i][j] > a[i][j-1] ? 0: 1;
    res = res*2 + temp;
    temp = a[i][j] > a[i+1][j-1] ? 0: 1;
    res = res*2 + temp;
    temp = a[i][j] > a[i+1][j] ? 0: 1;
    res = res*2 + temp;
    temp = a[i][j] > a[i+1][j+1] ? 0: 1;
    res = res*2 + temp;

    return res;
}*/

int cmp(int temp, int min){
    for(int i = 0; i < 8; i++){
        if(i != 0){
            temp *= 2;
            if(temp > 255) temp = temp - 255;
        }
        min = temp < min ? temp : min;
    }
    return min;
}

int main()
{
    int w,h;
    scanf("%d%d",&w,&h);

    int a[101][101];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++)
            scanf("%d",&a[i][j]);
    }

    for(int i = 1; i < h-1; i++){
        for(int j = 1; j < w-1; j++){

            int min = 255;
            int temp,res = 0;

            temp = a[i][j] > a[i-1][j-1] ? 0: 1;
            res = res*2 + temp;
            temp = a[i][j] > a[i-1][j] ? 0: 1;
            res = res*2 + temp;
            temp = a[i][j] > a[i-1][j+1] ? 0: 1;
            res = res*2 + temp;
            temp = a[i][j] > a[i][j+1] ? 0: 1;
            res = res*2 + temp;
            temp = a[i][j] > a[i+1][j+1] ? 0: 1;
            res = res*2 + temp;
            temp = a[i][j] > a[i+1][j] ? 0: 1;
            res = res*2 + temp;
            temp = a[i][j] > a[i+1][j-1] ? 0: 1;
            res = res*2 + temp;
            temp = a[i][j] > a[i][j-1] ? 0: 1;
            res = res*2 + temp;


            //temp = cal(a,i,j);
            min = cmp(res,min);

            if(j != w-2 )printf("%d ",min);
            else printf("%d\n",min);
        }
    }

    return 0;
}

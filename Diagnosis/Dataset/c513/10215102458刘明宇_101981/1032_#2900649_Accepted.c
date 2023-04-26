#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
    int *s1,*s2;
    s1 = (int *)a;
    s2 = (int *)b;
    while(*s1 != -1 && *s2 != -1&&*s1 == *s2){
        s1++;
        s2++;
    }
    return *s2 - *s1;
}


int main()
{
    int T;
    scanf("%d", &T);
    while(T-->0){
        int N;
        int line_data[1000][51];
        scanf("%d",&N);
        for(int k = 0;k < N;k++){
            int j = 0;
            while(scanf("%d",&line_data[k][j])&&line_data[k][j] != -1) j++;
        }
        qsort(line_data,N,sizeof(line_data[0]),cmp);
        for(int k = 0;k < N;k++){
            int j =0;
            for(;line_data[k][j+1] != -1;j++){
                printf("%d ", line_data[k][j]);
            }
            printf("%d\n",line_data[k][j]);
        }
    }
}
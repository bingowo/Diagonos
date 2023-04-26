#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int cmp(const void *a,const void *b)
{
    int *s1,*s2;
    s1=(int *)a;
    s2=(int *)b;
    while(*s1!=-1&&*s2!=-1&&*s1==*s2) s1++,s2++;
    return *s2-*s1;

}


int main(void)
{
    int n;
    int line_data[1001][51];
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; ++i) {
        scanf("%d",&n);
        for (int i = 0; i < n; ++i) {
            int j=0;
            int a[n];
            while (scanf("%d",&line_data[i][j])&&line_data[i][j]!=-1) j++;
        }
        qsort(line_data,n, sizeof(line_data[0]),cmp);
        for (int i = 0; i < n; ++i) {
            for (int k = 0; line_data[i][k]!=-1; k++) {
                printf("%d ", line_data[i][k]);
                if (line_data[i][k+1]==-1) printf("\n");
            }

        }
    }

    return 0;
}
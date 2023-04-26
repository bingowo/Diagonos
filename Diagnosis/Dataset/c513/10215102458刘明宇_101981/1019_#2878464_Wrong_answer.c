#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b);

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int s1[200];
    int s2[200];
    int s3[200];
    for(int i = 0;i < m;i++)
    {
        scanf("%d %d %d", &s1[i], &s2[i],&s3[i]);
    }
    int score[5];
    memset(score, 0, sizeof(score));
    for(int i = 0;i < m;i++)
    {
        if(s3[i] == 1) {int m = s1[i];int n = s2[i];score[m]+=3;score[n] -= 1;}
        if(s3[i] == 0) {int m = s1[i];int n = s2[i];score[m]++;score[n]++;}
        if(s3[i] == -1){int m = s1[i];int n = s2[i];score[m]-=1;score[n] +=3;}
    }
    qsort(score, 5,sizeof(score[0]),cmp);
    for(int i = 0;i < 4;i++)
    {
        printf("%d ", score[i]);
    }
}

int cmp(const void *a, const void *b)
{
    return(*(int *)b - *(int *)a);
}
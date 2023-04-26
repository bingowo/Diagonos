#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 70000
#define BigNUm 10007
#define N 100000

int cmp(const void*a, const void*b)
{
    int *p1=(int*)a, *p2=(int*)b;
    return *p1-*p2;
}
int main()
{
    int T, I;
    scanf("%d",&T);
    for(I=0; I<T; I++)
    {
        char code[200];
        int i, l, cnt[26]={0}, num[100];
        scanf("%s",code);
        l=strlen(code);
        for(i=0; i<l; i++) cnt[code[i]-'A']++;
        i=0;
        while(cnt[6]>0) {cnt[6]--; cnt[4]--; cnt[7]--; cnt[8]--; cnt[19]--; num[i++]=8;}//判断8
        while(cnt[20]>0) {cnt[20]--; cnt[5]--; cnt[14]--; cnt[17]--; num[i++]=4;}//判断4
        while(cnt[23]>0) {cnt[23]--; cnt[8]--; cnt[18]--; num[i++]=6;}//判断6
        while(cnt[25]>0) {cnt[25]--; cnt[4]--; cnt[14]--; cnt[17]--; num[i++]=0;}//判断0
        while(cnt[7]>0) {cnt[7]--; cnt[4]-=2; cnt[17]--; cnt[19]--; num[i++]=3;}//判断3
        while(cnt[5]>0) {cnt[5]--; cnt[4]--; cnt[8]--; cnt[21]--; num[i++]=5;}//判断5
        while(cnt[18]>0) {cnt[18]--; cnt[4]-=2; cnt[13]--; cnt[21]--; num[i++]=7;}//判断7
        while(cnt[19]>0) {cnt[14]--; cnt[19]--; cnt[22]--; num[i++]=2;}//判断2
        while(cnt[14]>0) {cnt[14]--; cnt[4]--; cnt[13]--; num[i++]=1;}//判断1
        while(cnt[4]>0) {cnt[4]--; cnt[8]--; cnt[13]-=2; num[i++]=9;} //判断9
        qsort(num, i, sizeof(int), cmp);
        printf("case #%d:\n",I);
        for(l=0; l<i; l++) printf("%d",num[l]);
        printf("\n");
    }
    return 0;
}

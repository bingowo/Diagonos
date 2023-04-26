#include<stdio.h>
struct data
{
    long long int a; //整数
    int number; //64位二进制补码中1的位数
};

int cmp (const void *a, const void *b)
{
    struct data d1, d2;
    d1 = *((struct data *)a);
    d2 = *((struct data *)b);
    if (d2.number != d1.number)
        return d2.number - d1.number; //降序排列
    else{
        if (d1.a < d2.a) // 因为cmp返回值为int 而 a为long long 所以不能直接相减 
            return -1;
        else 
            return 1;
    }
}
int main (void)
{   
    int n;
    struct data p[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%I64d", &p[i].a);
        int d=1;
        p[i].number = 0;
        for (int t=0; t<64;t++){
            if(p[i].a & d)
                p[i].number++;
            d = d << 1;
        }
    }
    int i;
    qsort(p,n, sizeof(p[0]), cmp);
    for (i = 0; i < n - 1; i++)
        printf("%I64d ",p[i].a);
    printf("%l64d\n",p[i].a);
}
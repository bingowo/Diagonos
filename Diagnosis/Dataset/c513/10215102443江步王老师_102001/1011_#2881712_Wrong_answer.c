#include<stdio.h>

int h2b(long long a, int *b);
void count(int *b, int n, long long *numz, long long *numi);
void bino_count(int n, long long *numz, long long *numi);
int main()
{
    long long int a;
    long long numz=0,numi=0;
    int n;
    //numz储存实部值,numi储存虚部值
    int b[64];
    scanf("%X",&a);
    n=h2b(a,b);
    count(b,n,&numz,&numi);
    if (numz==0){
        if (numi==0)
            printf("0");
        else{
            printf("%lldi",numi);
        }
    }
    else{
        if (numi==0){
            printf("%lld",numz);
        }
        else{
            if (numi > 0){
                printf("%lld+%lldi",numz,numi);
            }
            else{
                printf("%lld%lldi",numz,numi);
            }
        }
    }
    return 0;
}

int h2b(long long a, int *b)
{
    int i=0;
    while (a>0){
        *(b+i)=a%2;
        a=a/2;
        i++;
    }
    return i;
}

void count(int *b, int n, long long *numz, long long *numi)//b为存放二进制数的数组,n为数组的长度
{
    int i;
    for (i=0;i<n;i++){
        if (b[i]==1){
            bino_count(i,numz,numi);
            //printf("numz=%lld,numi=%lld\n",*numz,*numi);
        }
    }
    return;
}

void bino_count(int n, long long *numz, long long *numi)//专用于计算(-1+i)的n次方的函数,函数内容为二项式定理的代码实现
{
    int i;
    int c;
    int k;
    if (n==0){
        *numz=*numz+1;
        return;
    }
        
    for (i=0;i<n+1;i++){
        k=1;
        if (i==0 || i==n){
            c=1;
        }
        else{
            c=c*(n-i+1)/i;
        }
        if ((n-i)%2 == 1){
            k=-1;
        }
        if (i%4 == 0){
            *numz=*numz+k*c;
        }
        else if (i%2 == 0){
            *numz=*numz-k*c;
        }
        else{
            if ((i/2)%2 == 1){
                *numi=*numi-c*k;
            }
            else{
                *numi=*numi+c*k;
            }
        }
    }
    return;
}
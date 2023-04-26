#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
#define ll long long

int table[30] = {1,2,3,5,7,11, 13,17,19,23,29, 31,37,41,43,47, 53,59,61,67,71, 73,79,83,89,97};

void copy(int a[],int b[])
{
    for (int i=0;i<N;i++) a[i] = b[i];
}

void prime(int a[],int i)
{
    int p = 0;
    do
    {
        a[p++] = table[i]%10;
        table[i] /= 10;
    } while (table[i]>0);
    
}

void mul(int a[],int b[],int c[])
{
    for (int i=0;i<N/2;i++)
        for (int j=0;j<N/2;j++) c[i+j] += a[i]*b[j];
    for (int i=0;i<N;i++)
    {
        c[i+1] += c[i]/10;
        c[i] %= 10;
    }
}

void plus(int a[],int b[])
{
    for (int i=0;i<N/2;i++)
    {
        a[i] += b[i];
        a[i+1] += a[i]/10;
        a[i] %= 10;
    }
}

int main(){
    char s[N] = {0};
    gets(s);
    int arr[N][N] = {0};
    int p=0, t=0;
    for (int i = strlen(s)-1; i >= 0; i--){
        if (s[i] == ','){
            p++;
            t = 0;
            continue;
        }
        arr[p][t++] = s[i]-'0';
    }

    int val[N] = {}, a[N]={}, b[N]={}, c[N]={1}, res[N] = {0};
    //val位值 a b c res最终结果
    for (int i = 0; i <= p; i++){
        prime(b,i);
        mul(b,c,a);
        mul(a,arr[i],val);
        plus(res,val);
        copy(c,a);
        memset(b,0,sizeof(b));
        memset(a,0,sizeof(a));
        memset(val,0,sizeof(val));
    }
    int index;
    for (index = N-1; index >= 0; index--) if (res[index] != 0) break;
    if (index == -1) printf("0\n");
    else for (int i = index; i >= 0; i--) printf("%d", res[i]);
    printf("\n");
    return 0;
}
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Num
{
    long long int NumLLI;
    char NumCHAR[64];
    int c;
}Num;

void DEC2BIN(Num* x)
{
    if(x->NumLLI>=0)
    {
        long long int res = x->NumLLI;
        long long int remainder = 0;
        for(int i = 63;i>=0;i--)
        {
           remainder = res%2;
           res = res/2;
           x->NumCHAR[i] = remainder+48;
        }
        return;
    }
    else
    {
        x->NumCHAR[0] = '1';
        long long int res = -(x->NumLLI);
        long long int remainder = 0;
        for(int i = 63;i>=1;i--)
        {
           remainder = res%2;
           res = res/2;
           x->NumCHAR[i] = remainder;
           if(x->NumCHAR[i]==1)
           {
               x->NumCHAR[i] = '0';
           }
           else{
            x->NumCHAR[i] = '1';
           }

        }
        for(int i = 63;i>=1;i--)
        {
           if(x->NumCHAR[i]=='0')
           {
               x->NumCHAR[i]='1';
               break;
           }
           else{x->NumCHAR[i]='0';continue;}
        }
        return;
    }
}

void Count(Num* x)
{
    x->c = 0;
    for(int i = 0;i<64;i++)
    {
        if(x->NumCHAR[i]=='1')
        {
            x->c = x->c+1;
        }
    }
}

int cmp(const void*a, const void*b)
{
    Num*p1 = (Num*)a;
    Num*p2 = (Num*)b;
    if((*p1).c>(*p2).c)
    {
        return -1;
    }
    else if((*p1).c==(*p2).c)
    {
        if((*p1).NumLLI>(*p2).NumLLI)
        {
            return 1;
        }
        else{return -1;}
    }
    else{return 1;}
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int q = 0;q<T;q++)
    {
        printf("case #%d:\n",q);
        int N;
        scanf("%d",&N);
        Num *numbers = (Num*)malloc(sizeof(Num)*N);
        //printf("N = %d\n",N);
        for(int i = 0;i<N;i++)
        {
            scanf("%lld",&((numbers+i)->NumLLI));
            DEC2BIN(numbers+i);
            Count(numbers+i);
        }
        qsort(numbers,N,sizeof(Num),cmp);
        for(int i = 0;i<N;i++)
        {
            printf("%lld ",((numbers+i))->NumLLI);
        }
        printf("\n");
        free(numbers);
    }

    return 0;
}
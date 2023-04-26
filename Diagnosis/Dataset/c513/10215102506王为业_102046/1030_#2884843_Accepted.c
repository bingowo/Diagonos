#include <stdio.h>
#include <stdlib.h>
struct num{
    long long value;
    int highvalue;
};
typedef struct num dig;
dig arr[10100];

int cmp(dig*x,dig*y)
{
    if(x->highvalue==y->highvalue)
        return x->value>y->value?1:-1;
    else
        return x->highvalue>y->highvalue?-1:1;
}

char input[30];
int main()
{
    int T;
    scanf("%d",&T);
    for(int iT=0;iT<T;++iT){
        printf("case #%d:\n",iT);
        int N;
        scanf("%d",&N);
        memset(arr,0,N*sizeof(arr[0]));
        for(int iN=0;iN<N;++iN){
            scanf("%s",input);
            int first=input[0]=='-'?1:0;
            arr[iN].highvalue=input[first]-'0';
            long long tem=0;
            long long now=1;
            int len=strlen(input);
            for(int i=len-1;i>=first;--i){
                tem+=now*(input[i]-'0');
                now*=10;
            }
            if(first==1)tem=-tem;
            arr[iN].value=tem;
        }
        qsort(arr,N,sizeof(arr[0]),cmp);

        for(int iN=0;iN<N-1;++iN){
            printf("%lld ",arr[iN].value);
        }printf("%lld\n",arr[N-1].value);

    }
}

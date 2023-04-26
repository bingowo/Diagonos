#include<stdio.h>
#include<stdlib.h>

int cmp(const void* _a, const void* _b)
{
    int* a = (int*)_a ; int* b = (int*)_b ;
    return *a - *b ;
}

int gcd(int a,int b)
{ 
    if(a%b==0)
        return b ;
    else
        return gcd(b,a%b) ;
}

int issit(int a, int b)
{
    int _gcd = gcd(a,b) ;
    if(_gcd==1) return 1 ;
    return 0;
}

int main()
{
    int t ;
    scanf("%d",&t) ;
    int* a ;
    for(int i=0; i<t; i++){
        int n ;
        scanf("%d",&n) ;
        a = (malloc)(n*sizeof(int)) ;
        for(int j=0; j<n; j++)
            scanf("%d",&a[j]) ;
        qsort(a,n,sizeof(int),cmp) ;
        int count = 0 ;
        for(int j=0; j<n; j++){
            if(a[j] == a[j-1]) continue ;
            for(int k=j+1; k<n; k++){
                if(a[k]==a[k-1]) continue ;
                if(issit(a[j],a[k])) count++ ;
            }
        }
        printf("case #%d:\n%d\n",i,count) ;
        free (a) ;
    } 
}
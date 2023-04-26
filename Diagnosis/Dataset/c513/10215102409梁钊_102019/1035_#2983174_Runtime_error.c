#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int r , h ;
    long long area ;
} cylinder ;

int cmp(const void *_a , const void *_b)
{
    cylinder *a = (cylinder*)_a , *b = (cylinder*)_b ;
    return (*b).area > (*a).area ;
}

int main()
{
    int n , m ;
    cylinder* a ;
    cylinder* sel ;
    scanf("%d %d",&n,&m) ;
    a = (cylinder*)malloc(n*sizeof(cylinder)) ;
    for(int i=0; i<n; i++){
        scanf("%d %d",&a[i].r,&a[i].h) ;
        a[i].area = 2 * a[i].r * a[i].h ;
    }
    long long result = 0 ;
    for(int i=0; i<n; i++){
        int count = 0 ;
        sel = (cylinder*)malloc(m*sizeof(cylinder)) ;
        for(int j=0; j<n; j++){
            if(j!=i && a[i].r >= a[j].r)
                sel[count++] = a[j] ;
        }
        qsort(sel,count,sizeof(sel[0]),cmp) ;
        long long area = 0 ;
        if(count != 0 && count > m - 1)
            for(int j=0; j<m-1; j++)
                area += sel[j].area ;
        free (sel) ;
        area = area + a[i].area + (long long)a[i].r * a[i].r ;
        if(result < area)
            result = area ;        
    }
    free (a) ;
    printf("%lld",result) ;
}
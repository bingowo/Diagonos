#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct
{
    double p ;
    double angle ;
} p_angle;

int cmp(const void *_a , const void *_b)
{
    p_angle* a = (p_angle*)_a ; p_angle* b = (p_angle*)_b ;
    if((*a).angle == (*b).angle)
        return (*b).p - (*a).p > 0 ? 1 : -1 ;
    return (*a).angle - (*b).angle > 0 ? 1 : -1 ;
}

int main()
{
    int t = 0 ; int n = 0 ;
    double x = 0 ,  y = 0 ;
    double p = 0 , angle = 0 ;
    scanf("%d",&t) ;
    for(int i = 0 ; i < t ; i++){
        scanf("%d",&n) ;
        p_angle p_a[n] ;
        for(int j = 0 ; j < n ; j++){
            scanf("%lf %lf",&x,&y) ;
            p = sqrt(x*x+y*y) ;
            angle = atan2(y,x) ;
            if(y < 0)
                angle += 6.283185 ;
            p_a[j].p = p ;
            p_a[j].angle = angle ; 
        }
        qsort(p_a,n,sizeof(p_a[0]),cmp) ;
        printf("case #%d:\n",i) ;
        for(int k = 0 ; k < n ; k++){
            printf("(%.4lf,%.4lf)\n",p_a[k].p,p_a[k].angle) ;
        }
    }
}
#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    int N[T],R[T];
    int *n=N,*r=R;
    for(int i=0;i<T;i++){
        scanf("%d %d",&n,&t);
        n++;
        t++;
    }
    n=N,t=T;
    int each;
    char result[100];
    char *p=result;
    for(int i=0;i<T;i++){
        while(*n!=0){
            each=(*n)/(*r);
            (*n)/(*r);
            if(each<=9){
                *p=each;
            }
            else{
                *p=(char)each;
            }
            p++;
        }
    for(;p>=result;p--){printf("%s",*p);}
    }
    return 0;
}

//simu\1107.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
/*
    one word pressure test
*/

//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;


int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    unsigned long long n;
    scanf("%llu",&n);
    if(n<4){
        switch(n){
        case 0:
            printf("(0,0)");
            break;
        case 1:
            printf("(0,1)");
            break;
        case 2:
            printf("(-1,1)");
            break;
        case 3:
            printf("(-1,0)");
            break;
        }

    }else{
        LL k=1;
        while(n>=4*k*k)
            ++k;

        --k;
        n-=4*k*k;
        long long x=-k;
        long long y=-k;
        while(n!=0){
            if(n<=2*k){
                x+=n;
                break;
            }else{
                x+=2*k;
                n-=2*k;
                if(n<=2*k+1){
                    y+=n;
                    break;
                }else{
                    n-=2*k+1;
                    y+=2*k+1;
                    if(n<=2*k+1){
                        x-=n;
                        break;
                    }else{
                        x-=2*k+1;
                        n-=2*k+1;
                        if(n<=2*k+2){
                            y-=n;
                            break;
                        }else{
                            printf("ERROR");
                        }

                    }
                }
            }
            ++k;
        }
        printf("(%lld,%lld)",x,y);
    }
}


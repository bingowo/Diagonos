#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 500500
#define BigNUm 10007



int main()
{
   int T;scanf("%d",&T);
   for(int I=0;I<T;I++){
        int n;scanf("%d",&n);
        int w=0,x=0,y=0,z=0;
        int cnt=0;
        for(w=0;w<=n/4;w++){
            for(x=0;x<=n/3;x++){
                if(4*w+3*x>n) break;
                for(y=0;y<=n/2;y++){
                    z=n-4*w-3*x-2*y;
                    if(z<0) break;
                    else cnt++;
                }
            }
        }

        printf("%d\n",cnt);
   }

    return 0;
}

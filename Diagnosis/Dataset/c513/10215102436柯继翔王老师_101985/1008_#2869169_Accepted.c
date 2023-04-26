#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int T,x,y;
   scanf("%d",&T);
   for(int i = 0;i < T;i++){
        scanf("%d%d",&x,&y);
        int n = 0;
        while(x >0 ||y>0){
            if(x%2 != y%2)n++;
            x /= 2;
            y /= 2;
        }
        printf("%d\n",n);
   }
    return 0;
}

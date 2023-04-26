#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int r=0;
        int n = 0;
        scanf("%d%d",&n,&r);
        char b[33];
        int m = 0;
        if (n =0) {
            printf("%d",0);
            continue;
        }
        else if(n<0){
            m = 1;
            n = -1 * n;
        }
        else{
            int p;
            do{
                p = n%r;
                n = n/r;
                if(p<10)
                    b[0] = '0'+p;
                else{
                    b[0] = 'A'+p-10;
                }
            }
            while(n);

        }
        int q = 32;
        if(m = 1)
            printf('-');
        while(b[q]) {

            printf("%c",b[q]);
            q = q -1;
        }
    }

    return 0;
}

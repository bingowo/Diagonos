#include <stdio.h>
#include <stdlib.h>



int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int a=0,b=0,aa=0,bb=0;
        scanf("%d%d",&a,&b);
        int count=0;
        while(a>0 && b>0){
            aa=a&1;
            bb=b&1;
            if(aa!=bb){count++;}
            a=a>>1;
            b=b>>1;
        }
        if((a&1)!=(b&1))count++;


        printf("%d\n",count);

    }





    return 0;
}

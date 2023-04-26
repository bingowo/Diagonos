#include <stdio.h>
#include <stdlib.h>



int main()
{
    int sushu[25]={2},sscnt=1;
    for(int i=2;sscnt<25;i++){
        for(int j=2;j<i;j++){
            if(i%j==0){break;}
            if(2*j>i){sushu[sscnt]=i;sscnt++;break;}
        }
    }
    for(int i=0;i<25;i++){printf("%d ",sushu[i]);}

    return 0;
}
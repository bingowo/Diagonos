#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//字典序全排列
void swap(char *a, char *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        char N[30];memset(N,0,30*sizeof(char));
        scanf("%s",N);


        for(int i = strlen(N)-1;i>0;i--){
            int j = i-1;
            if(N[j]<N[i]){
                int k = strlen(N)-1;
                for(;k>j;k--){
                    if(N[k]>N[j]){
                        break;
                    }
                }
                swap(&N[j],&N[k]);
                for(int k1 = j+1,k2 = strlen(N)-1;k1<k2;k1++,k2--){
                    char tmp = N[k1];
                    N[k1] = N[k2];
                    N[k2] = tmp;
                }
            }
        }

        printf("%s\n",N);
    }


    return 0;
}

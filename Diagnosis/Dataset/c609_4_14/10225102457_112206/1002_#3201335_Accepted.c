#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
    unsigned int T,n,out;
    unsigned int b,b1;
    scanf("%u",&T);

    for(int i = 0;i < T;i++){
        scanf("%u",&n);
        int max = 1;
        char bi[32] = {0};

        for(int v = 0;n != 0;n/=2,v++){
            bi[v] = n%2+'0';
        }
        for(int v = 0;v < strlen(bi)-1;v++){
            if(bi[v]!=bi[v+1]){
                for(int test = 1;bi[v] != bi[v+1] && v < strlen(bi)-1;){
                	v++;
                    test++;
                    if(test > max) max = test;
                }
            }
        }
        printf("case #%u:\n",i);
        printf("%u\n",max);
    }
    return 0;
}
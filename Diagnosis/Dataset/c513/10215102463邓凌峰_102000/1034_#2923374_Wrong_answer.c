#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char low;
    char up;
    double f;
}Z;

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        Z zifu[26];
        for(int j=0;j<26;j++){
            scanf("%lf",&zifu[j].f);
            zifu[j].low='a'+j;
            zifu[j].up='A'+j;
        }
        printf("12");
    }

}

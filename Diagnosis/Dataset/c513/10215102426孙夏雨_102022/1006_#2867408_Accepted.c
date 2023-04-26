#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char s[100];
} S;

int main()
{
    int T;
    scanf("%d",&T);
    S* p=(S*)malloc(T*sizeof(S));
    for (int i=0;i<T;i++) scanf("%s",(p+i)->s);
    for (int j=0;j<T;j++){
        int length=0;
        int x=0;
        length=strlen((p+j)->s);
        char* s1=(p+j)->s;
        for (int k=0;k<length;k++){
            if(*(s1+k)=='1') x=x+pow(3,length-1-k);
            else if(*(s1+k)=='-') x=x-pow(3,length-1-k);
        }
        printf("case #%d:\n",j);
        printf("%d\n",x);
    }
    free(p);
    return 0;
}

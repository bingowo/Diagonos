#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int T,R,res;

    scanf("%d",&T);
    for(R=0;R<T;R++){
        printf("case #%d:\n",R);
        char a[100];
        scanf("%s",a);

        char *p=a;
        res=0;
        while(*p){
            switch(*p){
            case'0':res=res*3;break;
            case'1':res=res*3+1;break;
            case'-':res=res*3-1;break;}
            p++;
        }
        printf("%d\n",res);
    }
    return 0;
}

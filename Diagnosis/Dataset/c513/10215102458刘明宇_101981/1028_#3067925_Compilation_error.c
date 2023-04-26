#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



//升序
int cmp1(const void *a,const void *b){
    int *d1 = (int *)a;
    int *d2 = (int *)b;
    return *d1 - *d2;
}


//降序
int cmp2(const void *a,const void *b){
    int *d1 = (int *)a;
    int *d2 = (int *)b;
    return *d2 - *d1;
}


int main()
{
    char cx;
    int flag = 0;
    scanf("%c",&cx);


    if(cx == 'A') flag = 1;
    if(cx == 'D') flag = 0;

    int L[101];
    int i = 0;
    char ch;

    while(ch != '\n'){
        scanf("%d",&L[i]);
        ch = getchar();
        i++;
    }

    if(flag == 1)
        qsort(L,i,sizeof(L[0]),cmp1);
    if(flag == 0)
        qsort(L,i,sizeof(L[0]),cmp2);


    for(int j = 0;j < i-1;j++){
        if(L[j+1]!=L[j]) printf("%d ",L[j]);
    }
    if(L[i-1] != L[i-2]) printf("%d ",L[i-1]);
    return 0;
}
return 0;
}

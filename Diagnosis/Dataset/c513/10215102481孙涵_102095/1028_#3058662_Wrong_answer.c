#include <stdio.h>
#include <stdlib.h>
int cmpA(const void * a, const void *b);
int cmpD(const void * a, const void *b);


int main()
{
    char c;
    scanf("%c",&c);
    //A->升序排序 D->降序排序
    int s[100];
    int spl = 0;
    while(scanf("%d",&s[spl]) != EOF){
        spl++;
    }//此时spl是数组的最大下标
    if(c == 'A'){
        //升序排序
        qsort(s,spl + 1,sizeof(s),cmpA);
    }else if(c == 'D'){
        //降序排序
        qsort(s,spl + 1,sizeof(s),cmpD);
    }
    int j;
    for(int i = 0; i <= spl; i++){
        if(s[i] == s[i + 1]){
            for(j = i + 1; j <= spl - 1; j++){
                s[j] = s[j + 1];
            }
            i--;
            s[spl] = 0;
            spl--;
        }
    }
    int k;
    for(k = 0; k <= spl; k++){
        printf("%d",s[k]);
    }

    return 0;
}

int cmpA(const void * a, const void *b){
    int i1;
    int i2;
    i1 = *(int *)a;
    i2 = *(int *)b;
    return i1 > i2 ? 1 : -1;
}

int cmpD(const void * a, const void *b){
    int i1;
    int i2;
    i1 = *(int *)a;
    i2 = *(int *)b;
    return i1 > i2 ? -1 : 1;
}






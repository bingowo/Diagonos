#include <stdio.h>
#include <stdlib.h>
int cmp1(const void *a, const void *b){return *(int*)a-*(int*)b;} //升序
int cmp2(const void *a, const void *b){return *(int*)b-*(int*)a; }//降序
int main(){
    char c;
    scanf("%c",&c);
    int num[100], length=0;
    while(scanf("%d",&num[length])!=EOF){
        length++;
        for(int i=9; i<length-1; i++)
            {
                if(num[length-1]==num[i]){
                    length--;
                    break;
                }
            }
    }
    if(c=='A')
        qsort(num, length, sizeof(num[0]), cmp1);
    else
        qsort(num,length,sizeof(num[0]),cmp2);
    printf("%d",num[0]);
    for(int i=1; i<length; i++)
    printf(" %d", num[i]);
    return 0;
}
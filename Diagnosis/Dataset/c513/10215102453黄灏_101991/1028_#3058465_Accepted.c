#include <stdio.h>
#include <stdlib.h>

int main()
{
    char key;
    scanf("%c\n",&key);
    int num[1000]={0};
    int i=0;
    while(scanf("%d",&num[i])!=EOF) i++;

    int cmp(const void *a,const void *b){
        int *x=a;int *y=b;
        if(key=='A') return *x-*y;
        else return *y-*x;
    }

    qsort(num,i,sizeof(int),cmp);

    printf("%d",num[0]);printf(" ");

    for(int j=1;j<i;j++){
        if(num[j]==num[j-1]) continue;
        else{
            if(j!=i-1) {printf("%d",num[j]);printf(" ");}
            else printf("%d",num[j]);
        }
    }
    return 0;
}

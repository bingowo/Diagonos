#include <stdio.h>
#include <stdlib.h>



//int cmp(const void *a,const void *b){
//
//}

int main()
{
    int a[500],b[500];
    char ca[501]={0},cb[501]={0};
    while((scanf("%s",ca)+scanf("%s",cb)!=EOF)){
        for(int i=0;ca[i]&&cb[i];i++){
            a[i]=ca[i]-'0';
            b[i]=cb[i]-'0';
        }

        printf("done\n");
    }

}

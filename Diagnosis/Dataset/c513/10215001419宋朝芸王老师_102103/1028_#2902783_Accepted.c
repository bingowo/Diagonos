#include <stdio.h>
#include <stdlib.h>

int main()
{
    char seq;
    scanf("%c",&seq);

    char a[1001] = {'\0'};   //index
    int num = 0;
    int temp;
    while(scanf("%d",&temp) != EOF){
        num++;
        a[temp] = '1';
    }

    int flag = 0;

    if(seq == 'A'){
        for(int i = 0; i < 1000; i++){
            if(a[i] == '1' && flag == 0){
                printf("%d",i);
                flag = 1;
            }
            else if(a[i] == '1' && flag == 1)
                printf(" %d",i);
        }
        printf("\n");

    }
    else if(seq == 'D'){
        for(int i = 1000; i >= 0; i--){
            if(a[i] == '1' && flag == 0){
                printf("%d",i);
                flag = 1;
            }
            else if(a[i] == '1' && flag == 1)
                printf(" %d",i);
        }
        printf("\n");
    }

    return 0;
}

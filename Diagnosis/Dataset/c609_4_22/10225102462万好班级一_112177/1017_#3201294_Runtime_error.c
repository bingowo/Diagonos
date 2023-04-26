#include <stdio.h>
#include <stdlib.h>

int cmpA(const void* e1,const void* e2){
    return *(int*)e1 - *(int*)e2;
};
int cmpB(const void* e1,const void* e2){
    return *(int*)e2 - *(int*)e1;
};

int main()
{
    char in_put;
    scanf("%c",&in_put);

    int count = 0;

    int arr[100];
    int i = 1;
    int j = 1;

    int act[100] = {0};

    scanf("%d",&arr[0]);
    act[0] = arr[0];

    if(getchar() == '\n')
    {
        printf("%d",act[0]);
    }

    do
    {
        scanf("%d",&arr[i]);

        for (int k = 0; k < i; ++k) {
            if(arr[k] == arr[i])count++;
        }if(count == 0)
        {
            act[j++] = arr[i];
        }
        count = 0;
        i++;
    }while(getchar() != '\n');

    if(in_put == 'A')
        qsort(act,j,sizeof(int),cmpA);
    else if(in_put == 'D')
        qsort(act,j,sizeof(int),cmpB);

    for (int k = 0;act[k]; ++k) {
        printf("%d ",act[k]);
    }
}

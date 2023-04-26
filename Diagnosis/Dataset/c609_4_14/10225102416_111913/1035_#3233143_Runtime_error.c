#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count(char a[]);
int main()
{
    int T,i;
    scanf("%d",&T);
    char a[T][101];
    for(i=0;i<T;i++){
        scanf("%s",&a[i]);
        printf("case #%d:\n",i);
        printf("%d\n",count(a[i]));
    }
    return 0;
}

int count(char a[])
{
    int i=0,num=1,j;
    int count = 0;
    for(i=0;i<strlen(a)-1;i++){
        if(a[i]!=a[i+1]){
            for(j=i-num;j<i;j++){
                a[j]="0";
            }
        }else{
            num++;
        }
    }
}
    
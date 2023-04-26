#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d",&T);
    int num;
    int i;
    for (i=0;i<T;i++){
        char a[50000];
        scanf("%s",a);
        int flag;
        int j;
        int sum=0;
        for(j=0;j<strlen(a);j++){
        if (a[j]=='-'){
            flag=-1;
        }else if(a[j]=='1'){
            flag=1;
        }else if(a[j]=='0'){
            flag=0;
        }
        sum=(sum+flag)*3;
        }
        sum=sum/3;
        printf("case #%d:\n%d\n",i,sum);
    }
    return 0;
}

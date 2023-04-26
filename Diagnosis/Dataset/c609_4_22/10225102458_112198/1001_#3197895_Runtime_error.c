#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n,cnt=0,min,N,m;

    scanf("%d",&N);
    for(int i=0;i<n;i++){
        scanf("%d%d",&m,&n);
        char a[100];
        if(n<0){a[cnt++]='-';n=-n;}

        do{
            min=m%n;
            if(min>=0 && min<=9)a[cnt++]=min+'0';
    else a[cnt++]=min+'A';
        }while(m/n);
        for(int j=cnt-1;j>=0;j--)printf("%c",a[j]);
        printf("\n");

    }
    return 0;
}

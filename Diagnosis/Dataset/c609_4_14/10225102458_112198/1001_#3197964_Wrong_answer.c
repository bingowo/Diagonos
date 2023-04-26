#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n,cnt=0,min,N,m,mi;

    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d%d",&m,&n);
        mi=m;
        char a[100];
        if(m<0){m=-m;}

        do{
            min=m%n;
            if(min>=0 && min<=9)a[cnt++]=min+'0';
            else a[cnt++]=min+'A';
        }while(m/=n);
        if(mi!=m)a[cnt++]='-';
        for(int j=cnt-1;j>=0;j--)printf("%c",a[j]);
        printf("\n");
        cnt=0;

    }
    return 0;
}

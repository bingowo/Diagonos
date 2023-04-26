#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n,cnt=0,min,N,m,mi;

    scanf("%d",&N);
    char a[N][100];
    int b[N];
    for(int i=0;i<N;i++){
        scanf("%d%d",&m,&n);
        mi=m;
        if(m<0){m=-m;}

        do{
            min=m%n;
            if(min>=0 && min<=9)a[i][cnt++]=min+'0';
            else a[i][cnt++]=min-10+'A';
        }while(m/=n);
        if(mi<m)a[i][cnt++]='-';
        b[i]=cnt;
        cnt=0;

    }
    for(int i=0;i<N;i++){
        for(int j=b[i]-1;j>=0;j--)printf("%c",a[i][j]);printf("\n");
    }
    return 0;
}

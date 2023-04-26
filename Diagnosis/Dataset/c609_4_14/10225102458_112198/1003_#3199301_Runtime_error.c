#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,m,m1,cnt=0,count=0,bet=0,add=0;
    int mn[10000],mn1[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        m1=m;
        do{
            cnt++;
        }while(m/=2333);
        mn1[bet++]=cnt;
        count+=cnt;
        for(int j=cnt-1;j>=0;j--){mn[count-(cnt-j)]=m1%2333;m1/=2333;}
        cnt=0;
    }
    for(int j=0,i=0;j<count;j++){
        printf("%d",mn[j]);
        if(j==0)printf(" ");
        else if((j+1-add)%mn1[i]==0){printf("\n");add=mn1[i];i++;}
        else if(j!=count-1)printf(" ");
    }
    return 0;
}

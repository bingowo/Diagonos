#include <string.h>

int main()
{
    int n,m,m1,cnt=0,count=0;
    int mn[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        m1=m;
        do{
            cnt++;
        }while(m/=2333);
        count+=cnt;
        for(int j=cnt-1;j>=0;j--){mn[count-(cnt-j)]=m1%2333;m1/=2333;}
        mn[count++]=2333;
        cnt=0;
    }
    for(int j=0;j<count;j++){

        if(mn[j]>=0){printf("%d ",mn[j]);}


    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n,m1,max=1,cnt=0,count=0,m;
    scanf("%d",&n);
    int ap[n];
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        m1=m;
        do{
            cnt++;
        }while(m>>=1);
        int a[cnt],b[cnt];
        for(int j=cnt-1;j>=0;j--){a[j]=m1&1;m1>>=1;}
        for(int i=1;i<cnt;i++){
            if(a[i]!=a[i-1]){max++;}
            else {b[count++]=max;max=1;i--;}
        }
        b[count]=max;
        for(int j=0;j<count+1;j++){
            if(b[cnt]>max)max=b[cnt];
        }
        ap[i]=max;
    }
    for(int i=0;i<n;i++)printf("case #%d:\n%d\n",i,ap[i]);
    return 0;
}

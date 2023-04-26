#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long t,j,k,c,m,z,x,flag,i=0,r=0;
    long long a[123]={-1};
    char num[60];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s",&num);
        r=0;c=0;flag=0;  //r是进制数，c是最终得到的数字,flag表示是否应该填0
        for(j=0;num[j]=='0';j++){
            k=num[j];
            if(a[k]==-1){
                if(j==0){flag=1;a[k]=1;r++;}
                else if(flag==1){flag=0;r++;a[k]=0;}
                else {a[k]=r;}
                c=c*10+a[k];
            }
            else if(a[k]!=-1){c=c*10+a[k];}
        }
        if(r==1)r=2;
        m=0;z=0;
        while(c!=0){
            x=c%10;c=c/10;
            m=m+x*pow(r,z);
            z++;
        }
        printf("case #%lld\n",i);
        printf("%lld\n",m);
    }
    return 0;
}

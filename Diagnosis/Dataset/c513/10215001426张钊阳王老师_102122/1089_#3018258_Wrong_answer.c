#include <stdio.h>
#include <stdlib.h>
#define l0 10000
int main()
{
    int T;
    scanf("%d",&T);
    for(int z=0;z<T;z++)
    {
        int a,b,n;
        scanf("%d %d %d",&a,&b,&n);
        int s[10001];
        int temp[10001];
        int temp0[10001];
        memset(s,0,sizeof(s));
        memset(temp,0,sizeof(temp));
        memset(temp0,0,sizeof(temp0));
        int i=l0;
        int time=b;
        while(a!=0)
        {
            s[i]=a%10;
            temp[i]=a%10;
            a/=10;
            i--;
        }

        int start=i+1;
        for(int t=1;t<time;t++)//s不动 每次相乘都把结果放在temp0中 相乘后进位 之后把temp0中的全部放在temp中 并且让temp0清零
        {
            for(int j=l0;j>=start;j--)
            {
                for(int z=l0,move=0;z>=start;z--,move++)
                {
                    temp0[j-move]+=s[j]*temp[z];
                }
            }//做完乘法之后进位
            for(int k=l0;k>=0;k--)
            {
                if(temp0[k]>=10) {temp0[k-1]+=temp0[k]%10;temp0[k]/=10;}
            }//进位
            for(int k=0;k<=l0;k++) temp[k]=temp0[k];
            memset(temp0,0,sizeof(temp0));
        }

        printf("case #%d:\n",z);

        for(int zz=n-1;zz>=0;zz--)
        {
            printf("%d",temp[l0-zz]);
        }
        printf("\n");
    }
    return 0;
}

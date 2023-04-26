#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    unsigned long long int num1,num2;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b;
        num1=1,num2=1;
        scanf("%d%d",&a,&b);
        if(b>a/2)b=a-b;
        for(int i=0;i<b;i++){
            num1*=(a-i);
            if(num1%(b-i)==0)num1/=(b-i);
            else num2*=(b-i);
        }
        printf("case #%d:\n",i);
        printf("%lld\n",num1/num2);
    }
    return 0;
}

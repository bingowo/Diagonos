#include <stdio.h>
#include<stdlib.h>

int Differentdigit(int m,int n)
{
    int ret = 0;
    int flag = 0;
    int num = 1;
    flag = m^n;
    for(int i=0;i<32;i++,num = num<<1){
        if((flag & num) == num){
            ret++;
        }
    }
    return ret;
}


int main()
{
    int n,num1=0,num2=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&num1,&num2);
        int ret = Differentdigit(num1, num2);
        printf("%d\n",ret);
    }
    return 0;
    
}


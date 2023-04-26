#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0;j<T;j++){
        int a,b,m,n;
        int count=0;
        scanf("%d %d",&a,&b);
        while(a!=0||b!=0)
        {
            m=a%2;
            n=b%2;
            if(m!=n) count+=1;
            a=a/2;
            b=b/2;
        }
        printf("%d\n",count);
    }

    return 0;
}

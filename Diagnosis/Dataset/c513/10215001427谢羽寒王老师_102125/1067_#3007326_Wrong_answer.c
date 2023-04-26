#include <stdio.h>
#include <string.h>
#include<malloc.h>

int main()
{
    int T,j;

    scanf("%d",&T);
    for(j=0;j<T;j++){
        long long n,result;

        scanf("%d",&n);
      result=count(n);



        printf("case #%d:\n",j);
        printf("%d\n",result);
    }



}
int count(int n)
{
    if(n <= 1) return n;
    else return trib(n-2, 1, 1, 0); 
}

int trib(int n, int a, int b, int c)
{
    if(n == 0) return a;
    else return trib(n-1, a+b+c, a, b);
}


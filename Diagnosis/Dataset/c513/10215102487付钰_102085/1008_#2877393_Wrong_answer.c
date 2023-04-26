#include<stdio.h>
#include<string.h>
#include <math.h>
#include <stdlib.h>
int conversion(int x,int k,int f[])
{
    int n = abs(x);
    char out[1000];
    int i = 0, p = 0;
    while(n>0)
    {
        out[i++] = n % k;
        n /= k;
    }
    for(int j = i - 1;j >= 0;j--)
    {
           f[p]=out[j];
           p++;
    }
	f[p] = -1;
}
int fun1(int a,int b)
{
    int f1[100],f2[100],length=0;
    conversion(a,2,f1);
    conversion(b,2,f2);
    for(int p1 = 0;f1[p1] != -1 && f2[p1] != -1;p1++)
        {
			if(f1[p1] != f2[p1])
			{
				length ++;
			}
        }
    return length;

}
int main()
{

    int t,i,x,y,result;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&x,&y);
        result=(fun1(x,y));
        printf("%d",result);
        if(i!=t-1) printf("\n");
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
#include <math.h>
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

int main()
{

    int i = 0, x, n;
    scanf("%d", &n);
    int y[1000];
    for(i = 0 ; i < n ; i ++)
    {
        printf("case #%d:\n",i);
        scanf("%d",&x);
        conversion(x, 2, y);
        int max = 1, length = 1;
        for(int p1 = 0, p2 = 1;y[p2] != -1 && y[p1] != -1;p2++)
        {
			if(y[p2] != y[p1]){
				length ++;
			}else{
				if(length > max){
					max = length;
				}
				length = 1;
			}
			p1 = p2;
        }
        if(length > max) max = length;
        printf("%d", max);
        if(i != n - 1) printf("\n");
    }
	
	return 0;
}

#include <stdio.h>

int
main()
{
    int a,m;
    int n,x;
    int temp_a=0;
    int temp_b=0;
    int temp;
    int res;
    
    int in[2][21] = {0};
    int out[2][21] = {0};
    
    scanf("%d%d%d%d",&a,&n,&m,&x);
    
    in[0][1] = 1;
    in[1][1] = 0;
    in[0][2] = 0;
    in[1][2] = 1;
    out[0][1] = 0;
    out[1][1] = 0;
    out[0][2] = 0;
    out[1][2] = 1;
    
    for (int i=3; i<n; i++)
    {
        in[0][i] = in[0][i-1] + in[0][i-2];
        in[1][i] = in[1][i-1] + in[1][i-2];
        out[0][i] = in[0][i-1];
        out[1][i] = in[1][i-1];
    }
    
    for (int i=1; i<n; i++)
    {
        temp_a += in[0][i];
        temp_a -= out[0][i];
        temp_b += in[1][i];
        temp_b -= out[1][i];
    }
    temp = (m - temp_a*a)/temp_b;
    
    temp_a = 0;
    temp_b = 0;
    for (int i=1; i<=x; i++)
    {
        temp_a += in[0][i];
        temp_a -= out[0][i];
        temp_b += in[1][i];
        temp_b -= out[1][i];
    }
    res = temp_a*a + temp_b*temp;
    printf("%d\n",res);
    
    return 0;
}
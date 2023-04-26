#include <stdio.h>
#include <string.h>
int gcd(int a, int b)
{
    return b > 0 ? gcd(b, a % b) : a;
}
int main()
{
    int n;
    scanf("%d", &n);
    char a[100][10000];
    int fz[100];
    int fm[100];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
        int l = strlen(a[i]);
        int flag = 0;
        
        for (int j = 0; j < l; j++)
        {
            if (a[i][j] == '/')
                {
                    flag = 1;
                    continue;
                }
            if (flag)
            {
                fm[i] = fm[i] * 10 + a[i][j] - '0';
            }
            else
                fz[i] = fz[i] * 10 + a[i][j] - '0';
        }
        
    }
    int z=fz[0],m=fm[0];
    for(int j=1;j<n;j++){
        if(fm[j]==m)z+=fz[j];
        else{
            int lcm=m*fm[j]/gcd(m,fm[j]);
            
            z=lcm/m*z+lcm/fm[j]*fz[j];
            m=lcm;
        }
    }
    int t = gcd(z, m);
    printf("%d/%d", z/t, m/t);
    return 0;
}
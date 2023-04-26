#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int hp_a[28] = {0};
    int hp_b[28] = {0};
    hp_a[0] = 1;
    hp_a[1] = 0;
    hp_b[0] = 0;
    hp_b[1] = 1;
    for(int i =2;i<25;i++)
    {
        hp_a[i] = hp_a[i-1]+hp_a[i-2];
        hp_b[i] = hp_b[i-1]+hp_b[i-2];
    }
    int a;
    int b;
    int n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    long long add[20];
    int c_a = 0;
    int c_b =0;
    for(int q =2;q<n-1;q++)
    {
        c_a +=hp_a[q-2];
        c_b+= hp_b[q-2];
    }
    if(c_b ==0)
    {
     if(x<3)printf("%d",a);
     if(x==3)printf("%d",2*a);
    }
    else
    {
        b = (m-(c_a+1)*a)/c_b;
        int s_a=0,s_b =0;
        for(int g=2;g<=x-1;g++)
        {
            s_a +=hp_a[g-2];
            s_b+= hp_b[g-2];
        }
        long long res = (s_a+1)*a+s_b*b;
        printf("%lld",res);
    }
    return 0;
}


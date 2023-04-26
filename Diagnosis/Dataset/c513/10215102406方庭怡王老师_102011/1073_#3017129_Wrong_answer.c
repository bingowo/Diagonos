#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long long N2T(long long a)
 {
    return (a < 9)? a: N2T(a/10)*9 + a%10;	 // Nine system to Ten system, f in 1096.PPT
}
long long f(long long a) {
    long long d0 = a%10;
    for (long long x = a - d0; x <= a; x++) {	 // g in 1096.PPT
        char str[100] = {0};
        sprintf(str, "%lld", x);
        if (x%9 == 0 || strchr(str, '9') != 0) d0--;
    }
    return d0 + 8*N2T(a - a%10)/9;	 // Ans in 1096.PPT
}

int main()
{  
int a,b;
scanf("%d%d",&a,&b);
printf("%lld", f(b) - f(a) + 1);

}

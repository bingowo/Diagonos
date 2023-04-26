#include <stdio.h>
#include <stdlib.h>
int Gcd(int a, int b){
    if(b%a==0) return a;
    else return Gcd(b%a,a);
}
int main()
{
    int n;
    scanf("%d", &n);
    wchar_t c;
    getchar();
    int temp, count, ret, len;
    for(int k=0; k<n; k++){
       count = 0;
       len = 0;
       while((c=getchar())!='\n'){
            len++;
            if(c>=0x4e00 && c<=0x9fbb) len++;
            while(c!=0){
                if(c%2==1) count++;
                c /= 2;
            }
       }
       ret = Gcd(count, len*8);
       printf("%d/%d\n", count/ret, len*8/ret);
    }

    return 0;
}

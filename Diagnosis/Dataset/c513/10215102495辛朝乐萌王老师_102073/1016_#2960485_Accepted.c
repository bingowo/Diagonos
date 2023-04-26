#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

const double ep = 1e-8;

void itob(int n,char s[],double b)
{
    int remainder = 0,quotient = 0,tempb = (int)b;
    int index = 18;
    while (n!=0) {
        if(fabs(n/b)<ep){
            quotient=(int)(n/b);
        }
        else{
            quotient = ceil(n/b);
        }
        remainder = n-tempb*quotient;
        s[index--]=remainder>=10?(remainder-10+'A'):(remainder+'0');
        n=quotient;
    }
    memmove(s, s+index+1, 19-index);
}
int main(void){
    int n,r;
    scanf("%d %d",&n,&r);
    char s[20]={0};
    if(n==0){
        printf("0");
    }
    else{
        itob(n, s, (double)(r));
        printf("%s",s);
    }
    return 0;
}

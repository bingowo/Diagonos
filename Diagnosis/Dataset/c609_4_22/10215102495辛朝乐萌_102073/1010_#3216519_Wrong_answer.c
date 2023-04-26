#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void itob(int n,char s[],double r)
{
    int remainder=0,qout=0,temp=(int)r;
    int index=18;
    while (n!=0){
        if (fabs(n/r)<1e-8){
            qout=(int)n/r;
        }
        else{
            qout= ceil(n/r);
        }
        remainder=n-qout*temp;
        s[index--]=remainder>10?remainder-10+'A':remainder+'0';
        n=qout;
    }
    memmove(s,s+index+1,19-index);
}


int main()
{
    int n,r;
    scanf("%d %d",&n,&r);
    char s[20]={0};
    if (n==0) printf("0");
    else{

    }
}
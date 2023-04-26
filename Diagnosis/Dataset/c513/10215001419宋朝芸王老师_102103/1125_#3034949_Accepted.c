#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define M 17

long long int GCD(long long int m,long long int n)
{
    long long int temp;
    if(m<n) temp=m,m=n,n=temp;     //m中放较大数
    if(m%n==0) return n;
    temp=n,n=m%n,m=temp;
    return(GCD(m,n));
}

int main()
{
    int T,R;
    scanf("%d",&T);
    for(R = 0; R < T; R++){

        char a[M] = {'\0'};
        scanf("%s",a);
        int len = strlen(a);

        long long int full = 0;
        int i = 0;
        while(i < len){
            if(a[i] != '.') full = full*10 + a[i++] - '0';
            else if(a[i] == '.') {i++;break;}
        }

        //case 1:
        if(i == len) {printf("case #%d:\n%lld",R,full);continue;}

        long long int down = 0, up = 0, temp = 0;
        int no_loop = 0, loop = 0, loopflag = 0;

        while(i < len){
            if(isdigit(a[i])){
                up = up*10 + a[i] - '0';
                if(loopflag == 0) no_loop++;
                else loop++;
                i++;
            }
            else{
                loopflag = 1;
                if(a[i] == '[') temp = up;
                i++;
            }
        }
        if(loopflag == 0){
            down = pow(10,no_loop);
        }
        if(loopflag == 1){
            while(loop > 0) {down = down*10 + 9;loop--;}
            down *= pow(10,no_loop);
            up = up - temp;
        }

        up += full*down;
        long long int gcd = GCD(up,down);
        up = up/gcd;
        down = down/gcd;

        printf("case #%d:\n%lld/%lld\n",R,up,down);
    }
    return 0;
}

#include <stdio.h>
#include <math.h>
int main()
{
    long long int A = 0,B = 0,C,i = 0,j,m;
    char b[31],a[] = "201";
    gets(b);
    while(b[i] != '.' &&b[i]!='\0')
    {
        for(j = 0;j<3;j++)
            if(b[i]==a[j]) A = A*3+j-1;
        i++;

    }
    if(b[i]=='\0') printf("%lld",A);
    else
    {m =i+1;
    while(b[m]!='\0')
    {
        for(j = 0;j<3;j++)
        if(b[m]==a[j]) B = B*3+j-1;
        m++;
    }
    C = pow(3,m-i-1);
    if(A==0) printf("%lld %lld",B,C);
    else {
    if(B<0) {A = A-1;B = C + B;}
    else if(A<0) {A = A+1;B = C -B;}
    printf("%lld %lld %lld",A,B,C);}}

    return 0;

}

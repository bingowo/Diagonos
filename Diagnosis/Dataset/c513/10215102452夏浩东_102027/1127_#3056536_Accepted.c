#include <stdio.h>
int gcd(int a, int b)
{
    if(a>b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if(b%a==0) return a;
    else return gcd(b%a,a); 
}
int main()
{
    int a,A,b,B,num;
    scanf("%d",&num);
    scanf("%d/%d",&a,&A);
    for(int i=1;i<num;i++)
    {
        scanf("%d/%d",&b,&B);
        int temp1 = a*B+b*A;
        int temp2 = A*B;
        a = temp1 / gcd(temp1,temp2);
        A = temp2 / gcd(temp1,temp2);
    }
    printf("%d/%d",a,A);
}
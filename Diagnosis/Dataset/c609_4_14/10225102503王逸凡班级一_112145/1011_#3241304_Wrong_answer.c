#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char a[100]={0};
    scanf("%s",a);
    int A = 0,B = 0,C;
    int count = 0;
    int l;
    int i;
    for (i = 0;a[i]!='.'&& a[i]!='\0';i++){
        l = a[i] - '0';
        if ( l == 2 ){
            l = -1;
        }
        A = (A+l)*3;
    }
    A = A/3;
    for (i = i+1;a[i]!='\0';i++){
        l = a[i] - '0';
        if ( l == 2 ){
            l = -1;
        }
        B = (B+l)*3;
        count++;
    }
    B = B/3;

    if (A>0 && B<0){
        A-=1;
        B+=9;
    }
    if (A<0 && B>0){
        A+=1;
        B-=9;
        B=-B;
    }
    C = pow (3,count);
    if (A!=0){
        printf("%d ",A);
    }
    if (B!=0){
        printf("%d %d",B,C);
    }
    return 0;
}

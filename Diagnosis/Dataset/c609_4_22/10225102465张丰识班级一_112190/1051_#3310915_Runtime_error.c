#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 500
typedef struct {
  int a[2*L+1];
  char q[2*L+1];
} Big;
void Input(Big X)   //input a float number

{

    char s[L+1];

    scanf("%s",s);
    strcpy(X.q,s);
    int i=0,j,k;

    while(s[i] && s[i]!='.') i++; //定位小数点



    for(j=i-1,k=L;j>=0;j--,k--)

         X.a[k] = s[j]-'0';  //整数部分

    for(j=i+1,k=L+1;j<strlen(s);j++,k++)

         X.a[k] = s[j]-'0';   //小数部分

}
void sub(int a[],int b[],int N)

{   int i;

    for(i=2*L;i>L+N;i--)

    {

        a[i] -= b[i];
        if (a[i]<0) {
                a[i]+=10;
                a[i-1]--;
        }
    }

    if(a[i+1] >= 5) a[i]++;
for(i=L+N;i>0;i--)

    {

        a[i] -= b[i];
        if (a[i]<0) {
                a[i]+=10;
                a[i-1]--;
        }

    }

}
void output(int a[],int N)

{

    int i=0;

    while(i<=L && a[i]==0) i++;  //跳过前置0

    if(i>L) printf("%d",0);   //整数部分为0

    else

    {

        while(i<=L) printf("%d",a[i++]); //整数部分

    }

    printf("%c",'.');

    while(i<=L+N) printf("%d",a[i++]);  //小数部分

    printf("\n");

}

int main () {
//int A[2*L+1]={0}, B[2*L+1]={0},N;
int N;
Big A={0,{0}};
Big B={0,{0}};
Input(A);

Input(B);
scanf ("%d", &N);
if (strcmp(A.q,B.q)==1) {
sub(A.a,B.a,N); //A+=B

output(A.a,N);
}
else if (strcmp(A.q,B.q)==-1) {
    sub(B.q,A.q,N);
    output(B.a,N);
}
else printf('0');
return 0;
}

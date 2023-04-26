#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 500

void Input(int a[])   //input a float number

{

    char s[L+1];

    scanf("%s",s);

    int i=0,j,k;

    while(s[i] && s[i]!='.') i++; //定位小数点



    for(j=i-1,k=L;j>=0;j--,k--)

         a[k] = s[j]-'0';  //整数部分

    for(j=i+1,k=L+1;j<strlen(s);j++,k++)

         a[k] = s[j]-'0';   //小数部分

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
        //printf ("%d\n", a[i]);
    }

    if(a[i+1] >= 5) a[i]++;
for(i=L+N;i>0;i--)

    {

        a[i] -= b[i];
        if (a[i]<0) {
                a[i]+=10;
                a[i-1]--;
        }
         //printf ("%d\n", a[i]);
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
int cmp(int a[],int b[]) {
 int j=0;
 int k=0;
 while (a[j]==0) j++;
 while (b[k]==0) k++;
 if ((L-j)!=(L-k)) {
     if ((L-j)>(L-k)) return 1;
     else return -1;
 }

 else {
    for (;j<L+1;j++) {
        if (a[j]>b[j]) return 1;
        else if (a[j]<b[j]) return -1;
    }
    for (;j<2*L;j++) {
        if (a[j]>b[j]) return 1;
        else if (a[j]<b[j]) return -1;
    }
 }

}

int main () {
int A[2*L+1]={0}, B[2*L+1]={0},N;

Input(A);

Input(B);
scanf ("%d", &N);
if (cmp(A,B)==1) {
sub(A,B,N);
output(A,N);
}
else if (cmp(A,B)==-1) {
    sub(B,A,N);
    printf ("-");
    output(B,N);
}
else printf('0');
return 0;
}

#include <stdio.h>
#include <string.h>
void Input(int A[1001])
{
    char s[501];
    scanf("%s",s);
    int i=0,j,k;
    while (s[i] && s[i]!='.') i++;
    for (j=i-1,k=500;j>=0;j--,k--) A[k]=s[j]-'0';
    for (j=i+1,k=501;j<strlen(s);j++,k++) A[k]=s[j]-'0';
}
void add(int A[1001],int B[1001],int N)
{
    int i;
    for (i=1000;i>500+N;i--)
    {
        A[i]+=B[i];
        A[i-1]+=A[i]/10;
        A[i]%=10;
    }
    if (A[i+1]>=5) A[i]+=1;
    for (i=500+N;i>0;i--)
    {
        A[i]+=B[i];
        A[i-1]+=A[i]/10;
        A[i]%=10;
    }

}
void output(int A[1001],int N)
{
    int i=0;
    while (i<=500 && A[i]==0) i++;
    if (i>500) printf("%d",0);
    else
    {
        while (i<=500) printf("%d",A[i++]);
    }
    printf ("%c",'.');
    while (i<=500+N) printf ("%d",A[i++]);
    printf("\n");
}

int main()
{
    int A[1001]={0},B[1001]={0},N;
    Input(A);
    Input(B);
    scanf("%d",&N);
    add(A,B,N);
    output(A,N);
    return 0;
}

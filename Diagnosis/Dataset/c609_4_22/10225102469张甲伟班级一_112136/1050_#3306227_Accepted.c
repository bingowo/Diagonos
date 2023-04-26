#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define L 500
int A[2*L+1],B[2*L+1],N;
void Input(int a[])
{
    char s[L+1];
    scanf("%s",s);    
    int i=0,j,k;
    while(s[i] && s[i]!='.')
		i++; 
    for(j=i-1,k=L;j>=0;j--,k--) 
         a[k] = s[j]-'0'; 
    for(j=i+1,k=L+1;j<strlen(s);j++,k++) 
         a[k] = s[j]-'0';   
}
void add(int a[],int b[],int N)
{   int i;
    for(i=2*L;i>L+N;i--)
    {
        a[i] += b[i];
        a[i-1] += a[i]/10;
        a[i] %= 10;
    }
    if(a[i+1] >= 5) 
		a[i]++;
    for(i=L+N;i>0;i--)
    {
        a[i] += b[i];
        a[i-1] += a[i]/10;
        a[i] %= 10;
    }
}
void output(int a[],int N)
{
    int i=0;
    while(i<=L && a[i]==0) 
		i++;  
    if(i>L) 
		printf("%d",0);
    else
        while(i<=L)
			 printf("%d",a[i++]); 
    printf("%c",'.');
    while(i<=L+N) 
		printf("%d",a[i++]); 
}
int main()
{
	Input(A);
	Input(B);
	scanf("%d",&N);
	add(A,B,N); 	
	output(A,N);
	return 0;
}
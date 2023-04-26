#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define L 500
int A[2*L+1],B[2*L+1],N;
void Input(int a[],int b[])
{
    char s1[L+1],s2[L+1];
    scanf("%s",s1);
	scanf("%s",s2);    
    int i=0,j,k;
    while(s1[i] && s1[i]!='.')
		i++; 
    for(j=i-1,k=L;j>=0;j--,k--) 
         a[k] = s1[j]-'0'; 
    for(j=i+1,k=L+1;j<strlen(s1);j++,k++) 
         a[k] = s1[j]-'0'; 
	i=0;
	while(s2[i] && s2[i]!='.')
		i++; 
    for(j=i-1,k=L;j>=0;j--,k--) 
        b[k] = s2[j]-'0'; 
    for(j=i+1,k=L+1;j<strlen(s2);j++,k++) 
        b[k] = s2[j]-'0'; 
    
}
int compare(int a[],int b[])
{
	int i=0;
	while(1)
	{
		if(a[i]!=b[i])
			return a[i]-b[i];
		i++;
	}
}
void substract(int a[],int b[],int N)
{   int i;
	int k=0;
    for(i=2*L;i>L+N;i--)
    {
        if (a[i] + k >= b[i]) {
            a[i] = a[i] + k - b[i];
            k = 0;
        }  else { //借位的情况
            a[i] = a[i] + 10 + k - b[i];
            k = -1;
        }
    }
    if(a[i+1] >= 5) 
		a[i]++;
    for(i=L+N;i>0;i--)
    {
        if (a[i] + k >= b[i]) {
            a[i] = a[i] + k - b[i];
            k = 0;
        }  else { //借位的情况
            a[i] = a[i] + 10 + k - b[i];
            k = -1;
        }
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
	Input(A,B);
	int sign=compare(A,B);
	scanf("%d",&N);
	if(sign>0)
	{
		substract(A,B,N); 	
		output(A,N);
	}
	else
	{
		substract(B,A,N);
		printf("-"); 	
		output(B,N);
	}
	return 0;
}
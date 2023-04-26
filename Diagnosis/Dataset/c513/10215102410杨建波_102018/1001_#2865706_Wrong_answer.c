#include<stdio.h>
int main()
{
    int T,N,R;
    int rem,i = 0,m,t,flag = 1;
    char c[100];
    scanf("%d",&T);
    for(int n = 0;n<T;n++)
    {
        scanf("%d %d",&N,&R);
    if(N<0)
    {
        N = -N;
        flag = 0;
    }
    while(N > 0){
    rem = N % R; 
    if(rem >= 10)
    {
        t = rem -10 ;
        c[i] = 'A'+t;
    }
    else
    {
        c[i] = '0'+rem;
    }
    N = N / R;
    i++;
    }
	if(flag == 0 )
	c[i]='-';
	else{
	i--;
	}
    for(i;i >= 0;i--)
    {
       printf("%c",c[i]); 
    }
    printf("\n");
    i = 0;
    }
}
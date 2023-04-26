#include<stdio.h>
int main()
{
    int T,N,R;
    int rem = b,i = 0,m,t;
    scanf("%d",&T);
    for(int n = 0;n<T;n++)
    {
        scanf("%d %d",&N,&R);
        char str = {"ABCDEFG"},c[100];
    while(rem >= b){
    rem = a % b; 
    if(rem >= 10)
    {
        t = rem -10 ;
        c[i] = str[t];
    }
    else
    {
        c[i] = '0'+rem;
    }
    a = a / b;
    i++;
    }
    i--;
    for(int j = 0,i;j<i;i--,j++)
    {
        m = c[i];
        c[i] = c[j];
        c[j] = m;
    }
        printf("%s",c);
    }
}
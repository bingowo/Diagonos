#include<stdio.h>
char itob(int a,int b)
{char str = {"ABCDEFG"},c[100];
    int rem = b,i = 0,m,t;
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
    return c[100];
}
int main()
{
    int T,N,R;
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        scanf("%d %d",&N,&R);
        printf("%s",itob(N,R));
    }
}
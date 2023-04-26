#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 50
int main()
{
    long res;
    int k=0,i=0,j=0,kuo=0,L=0,z=0,y=0,s[M]={0},left[M]={0},right[M]={0},num[M]={0};
    char c;
    while((c=getchar())!='\n')
    {
        if(c=='(')
        {
            s[L]=-1;
            left[i]=L+1;
            i++;
        }
        else if(c==')')
        {
            right[j]=L-1;
            s[L]=-2;
            j++;
        }
        else if(c=='I')
            s[L]=1;
        else if(c=='V')
            s[L]=5;        
        else if(c=='X')
            s[L]=10;  
        else if(c=='L')
            s[L]=50; 
        else if(c=='C')
            s[L]=100; 
        else if(c=='D')
            s[L]=500; 
        else if(c=='M')
            s[L]=1000; 
        L++;
    }
    y=L;
    kuo=i;
    while(kuo!=0)
    {
    }
    for(i=z;i<y;i++)
    {
        if(s[i]>=k)
        k=i;
    }
    if(s[k-1]<s[k])
    {
        if((s[k-1]==1)||(s[k-1]==10)||(s[k-1]==100))
        {
            if(s[k-1]*50>=s[k])
            {
                
            }
        }
    }
    
    return 0;
}
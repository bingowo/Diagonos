#include <stdio.h>

char exchange[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};

int mod(int n,int r)
{
    if(n%r<0)
    {
        return n-(n/r+1)*r;
    }
    else{
        return n%r;
    }
    
}

int main()
{
    int n,r;
    scanf("%d %d",&n,&r);
    int count=0;
    char result[1001];
    while(n)
    {
        result[count++]=exchange[mod(n,r)];
        if(n%r<0)
        {
            n=n/r+1;
        }
        else{
            n/=r;
        }
    }
    count--;
    while(count)
    {
        printf("%c",result[count]);
        count--;
    }
    printf("%c\n",result[0]);
    return 0;
    
}
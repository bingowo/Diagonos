#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void solve(int x,int p)
{
    int i,res[15]={0};
    for(i=p-1;i>=0;i--)
    {
        if(x==0) break;
        res[i]=x%2;
        x/=2;
    }
    for(i=0;i<p;i++)
    {
        printf("%d",res[i]);
    }
}

int main()
{
    char input[600]={'\0'};
    scanf("%s",&input);
    printf("0001");
    solve(strlen(input),10);
    int i=0;
    while (strlen(input)-i>=3)
    {
        int tmp=(input[i]-'0')*100+(input[i+1]-'0')*10+(input[i+2]-'0');
        solve(tmp,10);
        i+=3;
    }
    if(strlen(input)-i==2)
    {
        int tmp=(input[i]-'0')*10+(input[i+1]-'0');
        solve(tmp,7);
    }
    else if (strlen(input)-i==1)
    {
        int tmp=(input[i]-'0');
        solve(tmp,4);
    }
    
    return 0;
}
#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    gets(a);
    int x=strlen(a),y=0;
    for(int i=0;i<x;i++)
    {
        if(a[i]==a[i+1])
        {
            int ming;
        }
        else
        {
            y++;
        }
    }
    printf("%d",y);
    
    
}
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,T;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",n);
        
        
        printf("case #%d:\n",i);
        printf("%d\n",n/5+n/25+n/125+n/625);
    }
    
    
    
    
    
    
}
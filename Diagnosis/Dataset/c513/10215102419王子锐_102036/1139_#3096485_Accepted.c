#include <stdio.h>  
  
int HasOnlyOneAndZero(unsigned int n)
{  
    while(n) 
    {  
        if(n % 10 >= 2) return 0;  
        n /= 10;  
    }  
    return 1;  
}  
  
int main() 
{  
    int n, m; 
    scanf("%d", &n);
    if(n==1)printf("10");
    else
    {  
        for(m = 1;;m++) 
        {  
            if(HasOnlyOneAndZero(n*m)&&m<10000) 
            {  
                printf("%d",n*m);  
                break;  
            } 
            else if(HasOnlyOneAndZero(n*m)&&m>=10000) 
            {  
                printf("-1");  
                break;  
            } 
        }  
    }  
    return 0;  
}  
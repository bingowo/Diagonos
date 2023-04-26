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
  
int main() {  
    int n, m;  
    while(scanf("%d", &n) != EOF) 
    {  
        for(m = 1;;m++) 
        {  
            if(HasOnlyOneAndZero(n*m)&&m<10000) 
            {  
                printf("%d",n*m);  
                break;  
            }  
        }  
    }  
    return 0;  
}  
#include<stdio.h>
#include<string.h>

int main(){
    int t,m=0;
    scanf("%d",&t);
    while(m<t){
        int a;
        scanf("%d",&a);
        int fir = a % 2,sec;
        int count = 1;
        int temp = 1;
        while(a)
        {   
            
            a >>= 1;
            sec = a % 2;
            if(sec != fir)
            {temp++;}
            else
            {
                if(temp > count)
                    {count = temp;}
                temp = 1;
            }
            
            fir = sec;
        }
    
        if(temp > count){count = --temp;}
        printf("case #%d:\n%d\n",m,count);
        m++;
    }
}

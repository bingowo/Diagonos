#include<stdio.h>
int main()
{
    int T,len,max,n;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d\n",&n);
        max=1;
        for(int k=0;k<32;k++)
        {    len=1;
            int l;
            for(l=k;l<31;l++)
            {
                if(((n>>l)&1)^((n>>(l+1))&1)==1) len++;
                else break;
                
            }
        if((n>>(l+1))&1==0) len--;
            if(len>max) max=len;
        
            
        }
        printf("case #%d:\n",i);
        printf("%d\n",max);
    }
    return 0;
}
        
        
    
    

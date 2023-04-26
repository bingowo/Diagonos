#include<stdio.h>
#include<string.h>

int main()
{
    int N=200,u,i,j,k,l,c=0,n,a,b=0;
    int s[N];
    scanf("%d",&n);
    for(u=0;u<n;u++){
        s=getchar();
        for(i=0;i<strlen(s);i++){
            itob(s[i]);
            
        }
        
    
        
        
        printf("%d/%d",c,b+c);
    }
    
   
    
    return 0;
}

int itob(int d)
{
    for(;d>0;){
        if(d%2 == 0){b++;}  //0的个数
        if(d%2 == 1){c++;}  //1的个数
        d=d/2；
        
    }
}
#include<stdio.h>
#include<string.h>

int main()
{
    int N=200,u,i,j,k,l,c=0,n,e,r,a,b=0;
    int s[N];
    scanf("%d",&n);
    for(u=0;u<n;u++){
       
        for(i=0;(k=getchar())!='\n';i++){
            
            itob(k);
            c=c+e;
            b=b+r;
        }
        
    
        
        
        printf("%d/%d",c,b+c);
    }
    
   
    
    return 0;
}

int itob(int d)
{ int e=0,r=0;
    for(;d>0;){
        if(d%2 == 0){r++;}  //0的个数
        if(d%2 == 1){e++;}  //1的个数
        d=d/2；
        
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i,m,p,n,c,d,e,f;
    long long int res=0;
    int a[123]=-1;
    char b[60];
    int l[60];
    scanf("%d",&t);
    for(i = 0;i<t;i++){
        m = 1;
        n = 1;
        c = 0;
        while(scanf("%c",&b[m++])){
            p = b[m++];
            
            if(a[p]==-1){
                    n++;
                l[m] = n;
                a[p]= n;
                n++
                
            
            }else{
                l[m]=n
            }
            
        }
    }
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{   int n;
    scanf("%d",&n);
    int i;
    int m,max,l,y;
    for(i=0;i<n;i++){
       scanf("%d",&m);
       l=1;max=0;
       while(m/2>0){
        y=m%2;
        if(y!=m/2%2){
            l++;
        }
        else{
            if (max<l) max=l;
            l=1;
        }
        m/=2;
       }
       if(max<l) max=l;
       printf("case #%d:\n",i);
       printf("%d\n",max);
    }
    return 0;
}

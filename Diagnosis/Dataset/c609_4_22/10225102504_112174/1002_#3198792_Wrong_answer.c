#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,a,b=1,c=1,d,e,f[100],g;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
     scanf("%d",&a);
     d=a%2;
     while(a){
        a>>=1;
        e=a%2;
        if(d!=e)
            b++;
        else {
            if(b>c)
            c=b;
            b=1;
     }
        d=e;
    }
    if(b>c)
        c=--b;
    f[i]=c;
    }
    for(g=0;g<t;g++){
    printf("case #%d:\n",g);
    printf("%d\n",f[g]);
    }
    return 0;
}

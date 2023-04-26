#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pros;
int c,n,r,last;

int main(){
    scanf("%d",&pros);
    for(int cnt=0;cnt<pros;cnt++){
        scanf("%d",&c);
        r=0;
        n=1;
        last=c&1;
        c>>=1;
        while(c){
            if(c&1^last) n++;
            else{
                if(n>r) r=n;
                n=1;
            }
            last=c&1;
            c>>=1;
        }
        if(n>r) r=n;
        printf("case #%d\n",cnt);
        printf("%d\n",r);
    }
    return 0;
}

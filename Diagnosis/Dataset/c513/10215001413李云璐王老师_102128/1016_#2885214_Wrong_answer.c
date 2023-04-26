#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    int N,R;
    scanf("%d%d",&N,&R);
    int n=N;
    while(n!=0)

       {
           char r1;
           int r=n%R;
           if(r<0)
           {
               r=r-n;
               n=n/R+1;
           }
           else n=n/R;
           if(r>=10)
            r1=r-10+'A';
        else r1=r+'0';
        printf("%c",r1);


       }

    return 0;
}
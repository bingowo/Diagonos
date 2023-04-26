#include <stdio.h>
#include <stdlib.h>


#define max 32

int main()
{
    int T,N,R; scanf("%d",&T);

    const char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int j=0;

    while( j<T && scanf("%d %d",&N,&R)==2)

     {
            char r[max]= {0};
            int yu;

            int i=0;
            int sign = 1;       /* initialization essential */

         if(N<0){
            N = -N;         /* record minus sign  */

            sign = -1;      /* keep positive    */
         }


        do{
            yu = N % R;
            N = N / R;
            r[i] = table[yu];
            i = i + 1;
        } while (N);



        if(sign==-1) r[i++] = '-';


        int m,n,temp;
        for(m=0,n = --i;m<n;m++,n--)
        {
            temp=r[m], r[m] = r[n], r[n] = temp;
        }

        printf("%s\n",r);

        j++;
    }


    return 0;
}

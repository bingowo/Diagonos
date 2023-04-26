#include <stdio.h>
#include <stdlib.h>


#define max 32

int main()
{
    int i,T; scanf("%d",&T);

    for(i=0;i<T;i++)
    {
        int N, R;

        while(scanf("%d %d",&N,&R)==2)

         {
                char r[max];
                int yu;

                int i=0;
                int sign;

             if(N<0){
                N = -N;         /* record minus sign  */

                sign = -1;      /* keep positive    */
             }


            do{
                yu = N % R;
                N = N / R;
                if(yu<=9) r[i] = yu + '0';
                else r[i] = yu - 10 + 'A';
                i = i + 1;
            } while (N);

                r[i] = '\0';

            if(sign==-1) r[i++] = '-', r[i]='\0';


            int m,n,temp;
            for(m=0,n = --i;m<n;m++,n--)
            {
                temp=r[m], r[m] = r[n], r[n] = temp;
            }

            printf("%s\n",r);
        }


    }

    return 0;
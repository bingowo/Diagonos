#include <stdio.h>
#include <stdlib.h>


#define max 32

int main()
{
    int a,T; scanf("%d",&T);

    for(a=0;a<T;a++)
    {
        int ten, r;




    while(scanf("%d %d",&ten,&r)==2)

        {
                char yu[max];
                int y;

                int i=0;
                int sign;

            sign = ten<0? '-':'\0';

            ten = ten<0? -ten:ten;

            do{
                y = ten % r;
                ten = ten / r;
                if(y<=9) yu[i] = y + '0';
                else yu[i] = y - 10 + 'A';
                i = i + 1;
            } while (ten);


                yu[i]='\0';

            if(sign=='-') yu[i++] = '-', yu[i]='\0';
            //reverse

            int m,n,temp;
            for(m=0,n = --i;m<n;m++,n--)
            {
                temp=yu[m], yu[m] = yu[n], yu[n] = temp;
            }

            printf("%s\n",yu);
        }


    }


    return 0;
}

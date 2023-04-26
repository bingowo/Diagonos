#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 32

int main()
{
    int a,T; scanf("%d",&T);

    for(a=0;a<T;a++)
    {
        int ten, r;


    char yu[max];
    int y;



    while(scanf("%d %d",&ten,&r)==T)    //wrong

        {
            int i=0, sign;

            sign = ten<0? '-':'\0';
            do{
                y = ten % r;
                ten = ten / r;
                if(y<=9) yu[i] = y;
                else yu[i] = y - 10 + 'A';
                i = i + 1;
            } while (ten);

            if(sign=='-') yu[i] = '-';
            //reverse

            int m,n,temp;
            for(m=0,n=strlen(yu)-1;m<n;m++,n++) temp=yu[m], yu[m] = yu[n], yu[n] = temp;

            printf("%s",yu);
        }


    }


    return 0;
}

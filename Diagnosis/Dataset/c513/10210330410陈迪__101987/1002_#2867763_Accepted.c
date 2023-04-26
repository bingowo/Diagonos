#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ON 1
#define OFF 0
int main()
{
    int T; scanf("%d",&T);  /* question number  */
    int j=0;        /* T-counter  */
    char s[61];     /* string   */

    while(j<T && scanf("%s",s)==1)
    {
        int a[123]; for(int m=0;m<123;m++) a[m] = -1;   /* initialization   */

        int i=0;  /* s-counter    */
        int br=0; /* bit rights   */
        int v = 2;      /* value    */
        int sign = ON;      /* check second bit */

        for(i=0;s[i]!='\0';i++)
        {

            if(a[*(s+i)]==-1) {
                    br++;
                if(i==0) a[*(s+i)]=1;
                else if(sign==ON) a[*(s+i)]=0, sign=OFF;
                else a[*(s+i)]=v++;
            }       /* table established    */
        }

        // convention
        long long int A = 0;
        if(br==1) br = 2;
        for(i=0;s[i]!='\0';i++)
        {
            A = A * br + a[*(s+i)];
        }

        printf("case #%d:\n",j);
        printf("%lld\n",A);

        j++;        /* back again   */
    }

    return 0;
}

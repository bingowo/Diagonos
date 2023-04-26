#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T,R;
    scanf("%d",&T);

    for(R = 0; R < T; R++)
    {
        //printf("case #%d:\n",R);

        char a[52];
        for(int i = 0;i < 52;i++) {a[i]='\0';}
        scanf("%s\n",a);

        char *p = a;
        int flag = 0;
        int i = -1;
        double output = 0;
        while(*p != '\0')
        {
            if(*p == '.') {flag = 1;continue;}
            if(flag == 0) continue;

            output = output + (*p - '0') * pow(8,i);
            i--;
            p++;
        }
        printf("case #%d:\n%f\n",R,output);
    }
    return 0;
}

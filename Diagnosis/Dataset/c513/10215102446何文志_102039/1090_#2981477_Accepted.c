#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int N = 0;
    while(1){
        scanf("%d",&N);
        if(N==0){
            break;
        }
        double d = N*log10(N);
        double d1 = d-(int)d;
        double r = pow(10.0,d1);
        //printf("d = %lf, d1 = %lf ",d,d1);
        //printf("r = %lf\n",r);
        char res[100];memset(res,0,100*sizeof(char));
        sprintf(res,"%lf",r);
        printf("%c\n",res[0]);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char k[50];
        printf("0.");
        scanf("%s",k);
        double sum=0.0;
        for(int j=0;j<strlen(k);j++)
        {
            sum=sum+(k[j]-'0')*pow(8,-j-1);
        }
        printf("case #%d:\n",i);
        printf("%lf\n",sum);
    }

    return 0;
}

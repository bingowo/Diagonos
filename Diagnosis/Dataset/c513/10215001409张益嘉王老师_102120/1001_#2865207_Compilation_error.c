#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t,i,z,j;
    scanf("%d",&t);
    int* n=(int*)malloc(t*sizeof(int));
    int* r=(int*)malloc(t*sizeof(int));
    char re[100];
    for(i=0;i<t;i++)
    {
        scanf("%d%d",&n[i],&r[i]);
    }
    for(i=0;i<t;i++)
    {
        for(j=0;n[i]>=0;j++)
        {
            z=n[i]%r[i];
            if(z<10) re[j]=z+'0';
            else re[j]=z+'A';
            n[i]/=r[i];
        }
        re[j]=0;
        strrev(re);
        printf("%s\n",re);
    }

    return 0;

}

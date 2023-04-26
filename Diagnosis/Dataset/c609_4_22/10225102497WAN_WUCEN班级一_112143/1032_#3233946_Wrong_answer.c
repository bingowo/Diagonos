#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *fence;
    fence=malloc(50*sizeof(char));
    int i=0,j=0,max=0,n=0;
    while (scanf("%c",fence+i)!=EOF) i++;
    for (j=0;j<i-1;j++)
        {if (*(fence+j)!=*(fence+j+1)) n++;
        else {if(n>=max) max=n+1;
              n=0;}
        }
    printf("%d",max);

}

#include<stdio.h>
#include<string.h>
void main()
{

    int y,i=0,n,j=0,o,sum=0,z;
    char x[20];
    char arr[20][20];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("case #%d:\n",i);
        scanf("%s",x);
        for(int z=0;x[z]!='\0';z++)
        {
        }
        for(int k=0;k<z;k++)
        {
            switch(x[k]){
            case '1':{sum+=1*pow(3,(j-k-1));}break;
            case '-':{sum+=(-1)*pow(3,(j-k-1));}break;
            case '0':{sum+=0*pow(3,(j-k-1));}break;

        }
        printf("%d",sum);
        if(i!=n-1) printf("\n");

    }
    }
}

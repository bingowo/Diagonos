#include <stdio.h>
#include <stdlib.h>

int main()
{   int n=0,i,inte,j;
    int *intp;
    char a[100][100];
    char out [100][8];
    int isint [100];
    double doub;
    double *doup;
    while(scanf("%s",&a[n++])!=EOF)
    {
        if(strchr(a[n-1],'.')==NULL)
            {inte=atoi(a[n-1]);
            intp=&inte;
            isint[n-1]=1;
            for(i=0;i<4;i++)
                out[n-1][i]=*((char*)intp+i);
            }
        else
            {doub=atof(a[n-1]);
            doup=&doub;
            isint[n-1]=0;
            for(i=0;i<8;i++)
                out[n-1][i]=*((char*)doup+i);
            }
    }
    for(i=0;i<n;i++)
    {   if(isint[i])
            {for(j=0;j<4;j++)
                if(out[i][j]<=15&&out[i][j]>=0) printf("0%0x ",(unsigned char)out[i][j]);
                else printf("%0x ",(unsigned char)out[i][j]);
                    printf("\n");}
        else
            {for(j=0;j<8;j++)
                {if(out[i][j]<=15&&out[i][j]>=0) printf("0%0x ",(unsigned char)out[i][j]);
                else printf("%0x ",(unsigned char)out[i][j]);}
                    printf("\n");}
    }

}


#include<stdio.h>
#include<math.h>
int main()
{
    int m,n,tab[500][500];
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) scanf("%d",&tab[i][j]);
    }
    int bin[16],res[500][500];
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<m-1;j++)
        {
            bin[0]=tab[i-1][j-1]>=tab[i][j]?1:0;
            bin[1]=tab[i-1][j]>=tab[i][j]?1:0;
            bin[2]=tab[i-1][j+1]>=tab[i][j]?1:0;
            bin[3]=tab[i][j+1]>=tab[i][j]?1:0;
            bin[4]=tab[i+1][j+1]>=tab[i][j]?1:0;
            bin[5]=tab[i+1][j]>=tab[i][j]?1:0;
            bin[6]=tab[i+1][j-1]>=tab[i][j]?1:0;
            bin[7]=tab[i][j-1]>=tab[i][j]?1:0;
            for(int p=0;p<8;p++) bin[8+p]=bin[p];
            int min=500,tmp;
            for(int p=0;p<8;p++)
            {
                tmp=0;
                for(int q=0;q<8;q++) tmp+=pow(2,7-q);
                min=tmp<min?tmp:min;
            }
            res[i][j]=min;
        }
    }
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<m-1;j++) printf("%d ",res[i][j]);
        printf("\n");
    }
}

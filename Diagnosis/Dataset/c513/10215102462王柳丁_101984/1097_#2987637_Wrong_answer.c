#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[80];
    char b;
    do
    {
        scanf("%s",a);
        char res[161][161];
        int i,j;
        for(i=0;i<161;i++)
        {
            for(j=0;j<161;j++){res[i][j]=-1;}
        }
        int sign[161];//记录是否有char
        for(i=0;i<161;i++){sign[i]=0;}
        int line=81;
        res[line][0]=a[0];
        sign[line]=1;
        for(i=1;i<strlen(a);i++)
        {
            (a[i]>a[i-1])?line--:line++;
            sign[line]++;res[line][i]=a[i];
        }
        for(i=0;i<161;i++)
        {
            j=0;
            while(sign[i]>0)
            {

                while(res[i][j]==-1){printf(" ");j++;}
                printf("%c",res[i][j]);sign[i]--;
                if(sign[i]==0)printf("\n");
                j++;
            }
        }
    }while((b=getchar())!=EOF);
    return 0;
}

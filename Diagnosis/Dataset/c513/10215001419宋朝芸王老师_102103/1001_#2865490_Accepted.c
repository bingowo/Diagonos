#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count,cases,R,ori,w;
    char res[100];

    scanf("%d",&cases);
    for(count=0; count<=cases; count++) {
        scanf("%d %d",&ori,&R);
        w=0;

        if(ori<0) {
            printf("-");
            ori=-ori;
        }

        while(ori>0){
            if((ori%R)>9)
                res[w]=ori%R-10+'A';
            else
                res[w]=ori%R+'0';
            ori=ori/R;
            w++;
        }


        while(w>=1){
            printf("%c",res[w-1]);
            w--;
        }
        printf("\n");
    }
    return 0;
}

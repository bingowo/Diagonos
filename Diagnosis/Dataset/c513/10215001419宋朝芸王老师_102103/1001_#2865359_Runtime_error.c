#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count,cases,R,ori,w,flag;
    char res[20];

    scanf("%d",&cases);
    for(count=0; count<=cases; count++) {
        scanf("%d %d",&ori,&R);
        w=0;
        if(ori<0) {
            flag=-1;
            ori=-ori;
        }

        while(ori>0){
            if((ori%R)>9) {
                res[w]=ori%R-10+'A';
                ori=ori/R;
                w++;
            }
            else {
                res[w]=ori%R+'0';
                ori=ori/R;
                w++;
            }
        }
        if(flag==-1) {
            res[w]='-';
            w++;
        }

        while(w>=1){
            printf("%c",res[w-1]);
            w--;
        }
        w=0,flag=1;;
        printf("\n");
    }
    return 0;
}

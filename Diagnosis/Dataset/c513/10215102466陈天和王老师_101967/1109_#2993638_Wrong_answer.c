#include <stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){

        int a[9]={0},allzero=1,isinit=1;
        for(int i=8;i>=0;i--){
            scanf("%d",&a[i]);
            if(a[i]!=0) allzero=0;
        }
        printf("case #%d:\n",t);

        if(allzero==1) printf("0");
        else{
            int j=8;
            while(a[j]==0) j--;
            for( ;j>=2;j--){
                if(isinit){
                    if(a[j]==1) printf("x^%d",j);
                    else if(a[j]==-1) printf("-x^%d",j);
                    else printf("%dx^%d",a[j],j);
                    j--;
                    isinit=0;
                }
                else {
                    if (a[j] == 0) continue;
                    else if (a[j] == 1) printf("+x^%d", j);
                    else if (a[j] == -1) printf("-x^%d", j);
                    else {
                        if (a[j] > 0) printf("+%dx^%d", a[j], j);
                        else printf("%dx^%d", a[j], j);
                    }
                }
            }

            if(j==1){
                if(isinit){
                    isinit=0;
                    int pass = 0;
                    if (a[j] == 0) pass = 1;
                    else if (a[j] == 1) printf("x");
                    else if (a[j] == -1) printf("-x");
                    else {
                        if (a[j] > 0) printf("%dx", a[j]);
                        else printf("%dx", a[j]);
                    }
                }
                else {
                    int pass = 0;
                    if (a[j] == 0) pass = 1;
                    else if (a[j] == 1) printf("+x");
                    else if (a[j] == -1) printf("-x");
                    else {
                        if (a[j] > 0) printf("+%dx", a[j]);
                        else printf("%dx", a[j]);
                    }
                }
                j--;
            }

            if(j==0){
                if(isinit){
                    isinit=0;
                    int pass = 0;
                    if (a[j] == 0) pass = 1;
                    else if (a[j] == 1) printf("1");
                    else if (a[j] == -1) printf("-1");
                    else {
                        if (a[j] > 0) printf("%d", a[j]);
                        else printf("%d", a[j]);
                    }
                }
                else {
                    int pass = 0;
                    if (a[j] == 0) pass = 1;
                    else if (a[j] == 1) printf("+1");
                    else if (a[j] == -1) printf("-1");
                    else {
                        if (a[j] > 0) printf("+%d", a[j]);
                        else printf("%d", a[j]);
                    }
                }
            }

        }
        printf("\n");
    }


    return 0;
}
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char st[123][123];

int check(int x,int y){
    char stx[123],sty[123];
    strcpy(stx,st[x]);
    strcpy(sty,st[y]);
    int fx=0;
    int fy=0;
    int numx=0;
    int numy=0;
    for (int i=0;i<strlen(stx);i++)
        if (stx[i]>='0' && stx[i]<='9') {
            fx=1;
            for (int j=i;stx[j]>='0' && stx[j]<='9';j++){
                numx*=10;
                numx+=stx[j]-'0';
            }
            break;
        }
    for (int i=0;i<strlen(sty);i++)
        if (sty[i]>='0' && sty[i]<='9') {
            fy=1;
            for (int j=i;sty[j]>='0' && sty[j]<='9';j++){
                numy*=10;
                numy+=sty[j]-'0';
            }
            break;
        }
    if (fx==fy && fx==0) return strcmp(sty,stx);
    if (fx==fy && fx==1) return numy-numx;
    if (fx==0 && fy==1) return 1;
    else return -1;
}

int main(){
    int n=0;
    char temp[123];
    while (scanf("%s",st[n++])!=EOF);
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++){
            if (check(i,j)<0){
                strcpy(temp,st[i]);
                strcpy(st[i],st[j]);
                strcpy(st[j],temp);
            }
        }
    for (int i=1;i<n;i++){
        printf("%s ",st[i]);
    }
    printf("\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSubZero(int *a,int *b){
    int idxa=0,idxb=0;
    for(;a[idxa]==0;idxa++);
    for(;b[idxb]==0;idxb++);
    if(idxa<idxb) return 0;
    else if(idxa>idxb){
        for(int i=0;i<1000;i++){
            int tmp=a[i];
            a[i]=b[i];
            b[i]=tmp;
        }
        return 1;
    }
    else if(idxa==idxb){
        for(;a[idxa]==b[idxb] && idxa<1000;idxa++,idxb++);
        if(a[idxa]>b[idxb]) return 0;
        else if(a[idxa]<b[idxb]){
            for(int i=0;i<1000;i++){
                int tmp=a[i];
                a[i]=b[i];
                b[i]=tmp;
            }
            return 1;
        }
        else return 0;
    }

}


int main()
{
    int a[1000]={0},b[1000]={0};
    char ca[1000]={0},cb[1000]={0};
    while((scanf("%s",ca)!=EOF)){
        scanf("%s",cb);
        int lena=strlen(ca),lenb=strlen(cb);
        for(int i=0;i<lena;i++){
            a[1000-lena+i]=ca[i]-'0';
        }
        for(int i=0;i<lenb;i++){
            b[1000-lenb+i]=cb[i]-'0';
        }

        int isFuShu=isSubZero(a,b);


        int delt[1000]={0};
        for(int i=999;i>=0;i--){
            int tmp=0;
            if(a[i]<0){
                a[i]+=10;
                a[i-1]-=1;
            }
            tmp=a[i]-b[i];
            if(tmp>=0) delt[i]=tmp;
            else if(tmp<0){
                tmp+=10;
                a[i-1]-=1;
                delt[i]=tmp;
            }
        }
        printf("ans:\t");

        if(isFuShu) printf("-");
        int idx=0;
        for(;delt[idx]==0 && idx<1000;idx++);
        if(idx==1000) printf("0");
        else{
            for(;idx<1000;idx++){
                if(idx<0);
                else printf("%d",delt[idx]);
            }
        }
        printf("\n");
        for(int i=0;i<1000;i++){
            a[i]=0;b[i]=0;
        }
    }

}

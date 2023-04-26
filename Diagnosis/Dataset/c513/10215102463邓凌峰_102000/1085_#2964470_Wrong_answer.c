#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSubZero(int *a,int *b){
    int idxa=0,idxb=0;
    for(;a[idxa]==0;idxa++);
    for(;b[idxb]==0;idxb++);
    if(idxa<idxb) return 0;
    else if(idxa>idxb){
        for(int i=0;i<500;i++){
            int tmp=a[i];
            a[i]=b[i];
            b[i]=tmp;
        }
        return 1;
    }
    else if(idxa==idxb){
        for(;a[idxa]==b[idxb] && idxa<500;idxa++,idxb++);
        if(a[idxa]>b[idxb]) return 0;
        else if(a[idxa]<b[idxb]){
            for(int i=0;i<500;i++){
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
    int a[500]={0},b[500]={0};
    char ca[501]={0},cb[501]={0};
    while((scanf("%s",ca)!=EOF)){
        scanf("%s",cb);
        int lena=strlen(ca),lenb=strlen(cb);

        for(int i=0;i<lena;i++){//对齐位方便做减法
            a[500-lena+i]=ca[i]-'0';
        }
        for(int i=0;i<lenb;i++){
            b[500-lenb+i]=cb[i]-'0';
        }

        int isFuShu=isSubZero(a,b);//判断a-b是不是小于0，如果小于0就将a、b数值对调

        int delt[500]={0};
        for(int i=499;i>=0;i--){
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
        if(isFuShu) printf("-");
        int idx=0,z=0;
        for(;delt[idx]==0 && idx<500;idx++);//跳过前面的0
        printf("idx is %d\t",idx);
        if(idx==500) printf("%d",z);//如果全是0就输出0
        else if(idx<500){
            printf("is not 0\t");
            for(;idx<500;idx++){
                if(idx<0);
                else printf("z=%d ",delt[idx]);
            }
        }
        printf("\n");
        for(int i=0;i<500;i++){
            a[i]=0;b[i]=0;
        }
    }



}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char word[36];
    int length;
}WORD;

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int hkuan=0;
        scanf("%d",&hkuan);
        WORD* p=(WORD* )malloc(2000*sizeof(WORD));
        int ciall=0;
        char c=getchar(),s[36];
        do{
            int len1=0;
            c=getchar();
            while(c!=' '&&c!='\n'){
                s[len1]=c;
                len1++;
                c=getchar();
            }
            s[len1]=0;
            if(len1>0) {
            (p+ciall)->length=strlen(s);
            strcpy((p+ciall)->word,s);
            ciall++;}
        }while(c!='\n');
        printf("case #%d:\n",t);
        int cihk=0,cidc=0,zkg=0,hdcs=0,shudc=0,houkg=0,zuihou=0;
        while(cidc<ciall){
            while(cihk+houkg<=hkuan){
                if(cihk+((p+cidc)->length)+houkg>hkuan) break;
                cihk+=((p+cidc)->length);
                houkg++;
                hdcs++;
                cidc++;
                if (cidc==ciall) {zuihou=1;break;}
            }
            if(zuihou==1){
                for(int ii=0;ii<hdcs;ii++) printf("%s ",(p+shudc+ii)->word);
            }
            else{zkg=hkuan-cihk;
            int sheng=zkg%(hdcs-1),mei=zkg/(hdcs-1);
                for(int i=0;i<hdcs;i++){
                    printf("%s",(p+shudc+i)->word);
                    for(int j=0;j<mei;j++) printf(" ");
                    if(sheng>0&&i>=(hdcs-1-sheng)) printf(" ");
                }
            }
            printf("\n");
            shudc+=hdcs;
            cihk=0;
            hdcs=0;
            houkg=0;
        }
        free(p);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char type[3];
    char gene[3];
}PER;

int cmp(const void* p3,const void* p4)
{
    int* p1=(int* )p3;
    int* p2=(int* )p4;
    return (*(p1))-(*(p2));
}

int main()
{
    PER* p=(PER* )malloc(3*sizeof(PER));
    int unknow=-1;
    int possible[4];
    int num=0,nn=0;
    for(int i=0;i<3;i++){
        char s[3];
        scanf("%s",s);
        if(strlen(s)==2) {
            strcpy((p+nn)->type,s);
            strcpy((p+nn)->gene,s);
            nn++;
        }
        else{
            if(s[0]=='?') unknow=i;
            else{
                strcpy((p+nn)->type,s);
                (p+nn)->gene[0]=s[0];
                (p+nn)->gene[1]='O';
                nn++;
            }
        }
        (p+i)->gene[2]=0;
    }
    if(unknow==2){
        char fir,sec;
        for(int j=0;j<2;j++){
            for(int jj=0;jj<2;jj++){
                fir=p->gene[j];
                sec=(p+1)->gene[jj];
                int cha=fir-sec,ca=1;
                if(cha==0) {
                    for(int kk=0;kk<num;kk++) {if(possible[kk]==((fir-'A'==1) ? 2:fir-'A')) ca=0;}
                    if(ca){
                    possible[num]=(fir-'A'==1) ? 2:fir-'A';
                    num++;}
                }
                else if(cha>1||cha<-1){
                    if(cha>0){
                        for(int kk=0;kk<num;kk++) {if(possible[kk]==((sec-'A'==1) ? 2:sec-'A')) ca=0;}
                        if(ca){
                        possible[num]=(sec-'A'==1) ? 2:sec-'A';
                        num++;}
                    }
                    else{
                        for(int kk=0;kk<num;kk++) {if(possible[kk]==((fir-'A'==1) ? 2:fir-'A')) ca=0;}
                        if(ca){
                        possible[num]=(fir-'A'==1) ? 2:fir-'A';
                        num++;}
                    }
                }
                else {
                    for(int kk=0;kk<num;kk++) {if(possible[kk]==1) ca=0;}
                    if(ca){
                    possible[num]=1;
                    num++;}
                }
            }
        }
    }
    int poss=0;
    if(unknow==0||unknow==1){
        int aa=0,bb=0;
        for(;aa<2;aa++){
            for(;bb<2;bb++){
                if((p->gene[aa])==((p+1)->gene[bb])) {poss=1;break;}
            }
            if(poss==1) break;
        }
        if(poss){
            int cc=(bb==0) ? 1:0;
            int ww1=1,ww2=1,ww3=1;
            if ((p+1)->gene[cc]=='O') {
                for(int ww=0;ww<num;ww++) {
                    if(possible[ww]==0) ww1=0;
                    if(possible[ww]==2) ww2=0;
                    if(possible[ww]>2)  ww3=0;
                }
                if(ww1) {
                    possible[num]=0;
                    num++;
                }
                if(ww2){
                    possible[num]=2;
                    num++;
                }
                if(ww3){
                    possible[num]=3;
                    num++;
                }
            }
            else if((p+1)->gene[cc]=='A'){
                for(int ww=0;ww<num;ww++) {
                    if(possible[ww]==0) ww1=0;
                    if(possible[ww]==1) ww2=0;
                }
                if(ww1) {
                    possible[num]=0;
                    num++;
                }
                if(ww2){
                    possible[num]=1;
                    num++;
                }
            }
            else{
                for(int ww=0;ww<num;ww++) {
                    if(possible[ww]==1) ww1=0;
                    if(possible[ww]==2) ww2=0;
                }
                if(ww1) {
                    possible[num]=1;
                    num++;
                }
                if(ww2){
                    possible[num]=2;
                    num++;
                }
            }
            if(aa==0){
                if((p->gene[1])==(p->gene[cc])){
                    cc=(cc==0) ? 1:0;
                    ww1=1,ww2=1,ww3=1;
                    if ((p+1)->gene[cc]=='O') {
                for(int ww=0;ww<num;ww++) {
                    if(possible[ww]==0) ww1=0;
                    if(possible[ww]==2) ww2=0;
                    if(possible[ww]>2) ww3=0;
                }
                if(ww1) {
                    possible[num]=0;
                    num++;
                }
                if(ww2){
                    possible[num]=2;
                    num++;
                }
                if(ww3){
                    possible[num]=3;
                    num++;
                }
            }
            else if((p+1)->gene[cc]=='A'){
                for(int ww=0;ww<num;ww++) {
                    if(possible[ww]==0) ww1=0;
                    if(possible[ww]==1) ww2=0;
                }
                if(ww1) {
                    possible[num]=0;
                    num++;
                }
                if(ww2){
                    possible[num]=1;
                    num++;
                }
            }
            else{
                for(int ww=0;ww<num;ww++) {
                    if(possible[ww]==1) ww1=0;
                    if(possible[ww]==2) ww2=0;
                }
                if(ww1) {
                    possible[num]=1;
                    num++;
                }
                if(ww2){
                    possible[num]=2;
                    num++;
                }
            }
                }
            }
        }
    }
    qsort(possible,num,sizeof(int),cmp);
    if(unknow==2){
    for(int t=0;t<2;t++) printf("%s ",(p+t)->type);
    printf("{");
    for(int k=0;k<num;k++){
        int ans=possible[k];
        if(ans==0) printf("A");
        else if(ans==1) printf("AB");
        else if(ans==2) printf("B");
        else printf("O");
        if(k<num-1) printf(",");
    }
    printf("}");
    }
    else if(unknow==0){
    if(poss==0) printf("impossible ");
    else{
    printf("{");
    for(int k=0;k<num;k++){
        int ans=possible[k];
        if(ans==0) printf("A");
        else if(ans==1) printf("AB");
        else if(ans==2) printf("B");
        else printf("O");
        if(k<num-1) printf(",");
    }
    printf("} ");}
    for(int t=0;t<2;t++) printf("%s ",(p+t)->type);
    }
    else{
        printf("%s ",p->type);
        if(poss==0) printf("impossible ");
    else{
    printf("{");
    for(int k=0;k<num;k++){
        int ans=possible[k];
        if(ans==0) printf("A");
        else if(ans==1) printf("AB");
        else if(ans==2) printf("B");
        else printf("O");
        if(k<num-1) printf(",");
    }
    printf("} ");}
    printf("%s",(p+1)->type);
    }
    return 0;
}

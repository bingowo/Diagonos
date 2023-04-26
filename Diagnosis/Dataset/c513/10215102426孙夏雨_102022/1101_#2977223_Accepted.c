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
    int T=0;
    scanf("%d",&T);
    for(int tt=0;tt<T;tt++){
    PER* p=(PER* )malloc(3*sizeof(PER));
    int unknow=-1;
    int possible[4];
    int num=0,nn=0;
    int Rn[3]={-1};
    for(int i=0;i<3;i++){
        char s[4];
        scanf("%s",s);
        if(strlen(s)==3) {
            char s1[3];
            s1[0]=s[0];
            s1[1]=s[1];
            s1[2]=0;
            strcpy((p+nn)->type,s1);
            strcpy((p+nn)->gene,s1);
            nn++;
            if(s[2]=='+') Rn[i]=1;
            else Rn[i]=0;
        }
        else{
            if(s[0]=='?') unknow=i;
            else{
                char s1[3];
                s1[0]=s[0];
                s1[1]=0;
                strcpy((p+nn)->type,s1);
                (p+nn)->gene[0]=s[0];
                (p+nn)->gene[1]='O';
                nn++;
                if(s[1]=='+') Rn[i]=1;
                else Rn[i]=0;
            }
        }
        (p+i)->gene[2]=0;
    }
    if(unknow==2){
        char fir,sec;
        if(Rn[0]==0&&Rn[1]==0) Rn[2]=0;
        else Rn[2]=1;
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
        if(unknow==0){
            if(Rn[1]==0&&Rn[2]==1) Rn[0]=1;
            else Rn[0]=2;
        }
        if(unknow==1){
            if(Rn[0]==0&&Rn[2]==1) Rn[1]=1;
            else Rn[1]=2;
        }
        int aa=0,bb=0;
        for(;aa<2;aa++){
            for(bb=0;bb<2;bb++){
                if((p->gene[aa])==((p+1)->gene[bb])) {poss=1;break;}
            }
            if(poss==1) break;
        }
        if((!strcmp(p->type,"AB"))&&((!strcmp((p+1)->type,"A"))||(!strcmp((p+1)->type,"B")))){
            for(int rr=0;rr<4;rr++){
                possible[num]=rr;
                num++;
            }
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
                if((p->gene[1])==((p+1)->gene[cc])){
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
    for(int t=0;t<2;t++) {
        printf("%s",(p+t)->type);
        if(Rn[t]==1) printf("+ ");
        else printf("- ");
    }
    if(num>1||Rn[2]==1) printf("{");
    for(int k=0;k<num;k++){
        int ans=possible[k];
        if(ans==0) {
            if(Rn[2]==0) printf("A-");
            else printf("A+,A-");
        }
        else if(ans==1) {
            if(Rn[2]==0) printf("AB-");
            else printf("AB+,AB-");
        }
        else if(ans==2) {
            if(Rn[2]==0) printf("B-");
            else printf("B+,B-");
        }
        else {
            if(Rn[2]==0) printf("O-");
            else printf("O+,O-");
        }
        if(k<num-1) printf(",");
    }
    if(num>1||Rn[2]==1) printf("}");
    }
    else if(unknow==0){
    if(poss==0) printf("impossible ");
    else{
    if(num>1||Rn[0]==2)printf("{");
    for(int k=0;k<num;k++){
        int ans=possible[k];
        if(ans==0) {
            if(Rn[0]==1) printf("A+");
            else printf("A+,A-");
        }
        else if(ans==1) {
            if(Rn[0]==1) printf("AB+");
            else printf("AB+,AB-");
        }
        else if(ans==2) {
            if(Rn[0]==1) printf("B+");
            else printf("B+,B-");
        }
        else {
            if(Rn[0]==1) printf("O+");
            else printf("O+,O-");
        }
        if(k<num-1) printf(",");
    }
    if(num>1||Rn[0]==2) printf("} ");}
    for(int t=0;t<2;t++) {
        printf("%s",(p+t)->type);
        if(Rn[t+1]==1) printf("+ ");
        else printf("- ");
    }
    }
    else{
        printf("%s",p->type);
        if(Rn[0]==1) printf("+ ");
        else printf("- ");
        if(poss==0) printf("impossible ");
    else{
    if(num>1||Rn[1]==2) printf("{");
    for(int k=0;k<num;k++){
        int ans=possible[k];
        if(ans==0) {
            if(Rn[1]==1) printf("A+");
            else printf("A+,A-");
        }
        else if(ans==1) {
            if(Rn[1]==1) printf("AB+");
            else printf("AB+,AB-");
        }
        else if(ans==2) {
            if(Rn[1]==1) printf("B+");
            else printf("B+,B-");
        }
        else {
            if(Rn[1]==1) printf("O+");
            else printf("O+,O-");
        }
        if(k<num-1) printf(",");
    }
    if(num>1||Rn[1]==2) printf("} ");}
    printf("%s",(p+1)->type);
    if(Rn[2]==1) printf("+ ");
    else printf("- ");
    }printf("\n");
    free(p);
    }
    return 0;
}


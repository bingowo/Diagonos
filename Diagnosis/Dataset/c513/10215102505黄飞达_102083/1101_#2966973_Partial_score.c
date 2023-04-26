#include<stdio.h>
#include<string.h>

typedef struct person{
    char blood[30];
    int gene[5];//A B O + -
}person;
void bloodToGene(char blood[], int gene[]){
    for (int i=0; i<5; i++) gene[i]=0;
    int len=strlen(blood);
    if (blood[len-1]=='+') gene[3]=gene[4]=1;
    else if (blood[len-1]=='-') gene[4]=1;
    if (len==3) gene[0]=gene[1]=1;
    else {
        if (blood[0]=='A') gene[0]=gene[2]=1;
        else if (blood[0]=='B') gene[1]=gene[2]=1;
        else if (blood[0]=='O') gene[2]=1;
    }
    return;
}
void mycat(char blood[], const char c[2], int rh){
    if (rh==1){//+
        strcat(blood, c);
        strcat(blood, "+,");
    }
    else if (rh==2){//-
        strcat(blood, c);
        strcat(blood, "-,");
    }
    else if (rh==3){//+ -
        strcat(blood, c);
        strcat(blood, "+,");
        strcat(blood, c);
        strcat(blood, "-,");
    }
    return;
}
void geneToChild(int g1[], int g2[], char blood[]){
    int abo[5]={};
    int rh=0;
    for (int i=0; i<5; i++) abo[i]=g1[i]+g2[i];
    if (abo[3]>=2 || (abo[3]>=1&&abo[4]>=1)) rh+=1;
    if (abo[4]>=2) rh+=2;
    if (abo[0]>=2 || (abo[0]>=1&&abo[2]>=1)) mycat(blood, "A", rh);
    if (abo[0]>=1 && abo[1]>=1) mycat(blood, "AB", rh);
    if (abo[1]>=2 || (abo[1]>=1&&abo[2]>=1)) mycat(blood, "B", rh);
    if (abo[2]>=2) mycat(blood, "O", rh);
    return;
}
int mycmp(char temp[], char blood[]){
    if (strcmp(temp, blood)==0) return 0;
    else {
        char s[30]={};
        int len = strlen(temp);
        for (int i=0, j=0; i<len; i++, j++){
            if (temp[i]==',') {
                if (strcmp(s, blood)==0) return 0;
                memset(s, 0, 30);
                j=-1;
                continue;
            }
            s[j]=temp[i];
        }
    }
    return -1;
}
void geneToParent(int g1[], int g3[], char ch_blood[], char m_blood[]){
    int g2[5][4]={{1,0,1},{1,0,0},{0,1,1},{0,0,1},{0,1,0}};
    // {{1,0,1,1,1},{1,0,1,0,1},{1,1,0,1,1},{1,1,0,0,1},{0,1,1,1,1},{0,1,1,0,1},{0,0,1,1,1},{0,0,1,0,1}};
    //{{1,0,1},{1,1,0},{0,1,1},{0,0,1}};
    
    const char name[5][4]={"A","AB","B","O","AB"};
    int rh=0;
    if (g1[3]>=1) rh=3;
    else if (g3[3]>=1)  rh=1;
    else if (g3[4]>=1) rh=2;

    int flag=0, abspe=0;
    for (int i=0; i<5; i++){
        if (i==4 && abspe==1) break;
        char temp[30]={0};
        int abo[5]={0};
        for (int j=0; j<5; j++) abo[j]=g1[j]+g2[i][j];
        if (abo[0]>=2 || (abo[0]>=1&&abo[2]>=1)) mycat(temp, "A", rh);
        if (abo[0]>=1 && abo[1]>=1) {mycat(temp, "AB", rh);abspe=1;}
        if (abo[1]>=2 || (abo[1]>=1&&abo[2]>=1)) mycat(temp, "B", rh);
        if (abo[2]>=2) mycat(temp, "O", rh);
        if (mycmp(temp, ch_blood)==0) {
            mycat(m_blood, name[i], rh);
            flag=1;
        }
    }
    if (flag==0) strcat(m_blood, "impossible");
    return;    
}
int main(){
    int T=0;
    scanf("%d", &T);
    for (int t=0; t<T; t++){
        person dad,mom,child;
        scanf("%s %s %s", dad.blood, mom.blood, child.blood);
        if (strcmp(child.blood, "?")==0){
            child.blood[0]='\0';
            bloodToGene(dad.blood, dad.gene);
            bloodToGene(mom.blood, mom.gene);
            geneToChild(dad.gene, mom.gene, child.blood);
            int len=strlen(child.blood);
            for (int i=len-1; i>=0; i--) if (child.blood[i]==',') {child.blood[i]='\0'; break;}
            if (len>=6) printf("%s %s {%s}\n", dad.blood, mom.blood, child.blood);
            else printf("%s %s %s\n", dad.blood, mom.blood, child.blood);
        }
        else {
            int changed=0;
            if (strcmp(dad.blood, "?")==0){//mom置为待查询对象
                person temp = mom;
                mom = dad;
                dad = temp;
                changed=1;
            }
            mom.blood[0]='\0';
            // memset(child.blood, 0, 30);
            bloodToGene(dad.blood, dad.gene);
            bloodToGene(child.blood, child.gene);
            geneToParent(dad.gene, child.gene, child.blood, mom.blood);
            if (changed){//换回来
                person temp = mom;
                mom = dad;
                dad = temp;  
            }
            int len=strlen(dad.blood);
            for (int i=len-1; i>=0; i--) if (dad.blood[i]==',') {dad.blood[i]='\0'; break;}
            if (len>=6 && strcmp(dad.blood, "impossible")!=0) printf("{%s} ", dad.blood);
            else printf("%s ", dad.blood);
            len=strlen(mom.blood);
            for (int i=len-1; i>=0; i--) if (mom.blood[i]==',') {mom.blood[i]='\0'; break;}
            if (len>=6 && strcmp(mom.blood, "impossible")!=0) printf("{%s} ", mom.blood);
            else printf("%s ", mom.blood);
            printf("%s\n", child.blood);
        }
    }
    return 0;
}
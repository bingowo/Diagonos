#include<stdio.h>
#include<string.h>
#define ll long long

typedef struct{
    int cnt;
    ll data[50];
}Vector;

Vector var[30000];
char item[50][10];

void deal(int *l, int *r){
    while(1){
        if (strcmp(item[*l],"(")||strcmp(item[*r],")")) return;
        int t=0;
        for (int i=*l; i<=*r; i++){
            if (strcmp(item[i],"(")==0) t++;
            else if (strcmp(item[i], ")")==0) t--;
            else if (t==0) return;
        }
        ++(*l),--(*r);
    }
    return;
}
int isNum(char *s){
    for (int i=0; s[i]; i++){
        if ('0'>s[i] || s[i]>'9') return 0;
    }
    return 1;
}
int isAllNum(int l, int r){
    for (int i=l; i<=r; i++){
        if (!isNum(item[i])) return 0;
    }
    return 1;
}
ll strToNum(char* s){
    ll d=0;
    for (int i=0;s[i]; i++) d=d*10+s[i]-'0';
    return d;
}

Vector Add(Vector m1, Vector m2){
    if (m1.cnt==-1) m1=var[m1.data[0]];
    if (m2.cnt==-1) m2=var[m2.data[0]];
    Vector temp;
    if (m1.cnt==1){
        temp=m2;
        for (int i=0; i<m2.cnt; i++) temp.data[i]+=m1.data[0];
    }
    else if (m2.cnt==1){
        temp=m1;
        for (int i=0; i<m1.cnt; i++) temp.data[i]+=m2.data[0];
    }
    return temp;
}
Vector Sub(Vector m1, Vector m2){
    if (m1.cnt==-1) m1=var[m1.data[0]];
    if (m2.cnt==-1) m2=var[m2.data[0]];
    Vector temp;
    if (m1.cnt==1){
        temp=m2;
        for (int i=0; i<m2.cnt; i++) temp.data[i]=m1.data[0]-temp.data[i];
    }
    else if (m2.cnt==1){
        temp=m1;
        for (int i=0; i<m1.cnt; i++) temp.data[i]-=m2.data[0];
    }
    return temp;
}
Vector Mul(Vector m1, Vector m2){
    if (m1.cnt==-1) m1=var[m1.data[0]];
    if (m2.cnt==-1) m2=var[m2.data[0]];
    Vector temp;
    if (m1.cnt==1){
        temp=m2;
        for (int i=0; i<m2.cnt; i++) temp.data[i]*=m1.data[0];
    }
    else if (m2.cnt==1){
        temp=m1;
        for (int i=0; i<m1.cnt; i++) temp.data[i]*=m2.data[0];
    }
    return temp;
}
Vector compAdd(Vector m1){
    int ID;
    if (m1.cnt==-1){ID=m1.data[0];m1=var[m1.data[0]];}
    Vector temp=m1;
    temp.cnt=1;
    ll d=0;
    for (int i=0; i<m1.cnt; i++) d+=m1.data[i];
    temp.data[0]=d;
    var[ID]=temp;
    return temp;
}
Vector compSub(Vector m1){
    int ID;
    if (m1.cnt==-1){ID=m1.data[0];m1=var[m1.data[0]];}
    Vector temp=m1;
    temp.cnt=1;
    ll d=0;
    for (int i=m1.cnt-1; i>=0; i--) d=m1.data[i]-d;
    temp.data[0]=d;
    var[ID]=temp;
    return temp;
}
Vector compMul(Vector m1){
    int ID;
    if (m1.cnt==-1){ID=m1.data[0];m1=var[m1.data[0]];}
    Vector temp=m1;
    temp.cnt=1;
    ll d=1;
    for (int i=0; i<m1.cnt; i++) d*=m1.data[i];
    temp.data[0]=d;
    var[ID]=temp;
    return temp;
}
Vector calc(int l,int r){
    deal(&l, &r);
    Vector temp;
    if (isAllNum(l,r)){
        temp.cnt=0;
        for (int i=l; i<=r; i++) temp.data[temp.cnt++]=strToNum(item[i]);
        return temp;
    }
    if (l==r){
        temp.cnt=-1;
        ll d=0;
        for (int i=0; item[l][i]; i++) d=d*26+(item[l][i]-'a'+i);
        temp.data[0]=d;
        return temp;
    }
    int j=-1, t=0;
    for (int i=l; i<=r; i++){
        if (strcmp(item[i], ")")==0) t++;
        else if (strcmp(item[i], "(")==0) t--;
        else if (t==0&&i>l&&(!strcmp(item[i], "+")||!strcmp(item[i], "-")||!strcmp(item[i], "*")||!strcmp(item[i], "="))){
            j=i; break;
        }
    }
    Vector ope1, ope2;
    if (strcmp(item[j],"=")==0){
        ope2=calc(j+1, r);
        if (ope2.cnt==-1) ope2=var[ope2.data[0]];
        ope1=calc(l, j-1);
        var[ope1.data[0]]=ope2;
        return ope2;
    }
    else if(strcmp(item[j],"+")==0){
        ope2=calc(j+1, r);
        if (ope2.cnt==-1) ope2=var[ope2.data[0]];
        ope1=calc(l, j-1);
        if (ope1.cnt==-1) ope1=var[ope1.data[0]];
        return Add(ope1, ope2);
    }
    else if(strcmp(item[j],"-")==0){
        ope2=calc(j+1, r);
        if (ope2.cnt==-1) ope2=var[ope2.data[0]];
        ope1=calc(l, j-1);
        if (ope1.cnt==-1) ope1=var[ope1.data[0]];
        return Sub(ope1, ope2);
    }
    else if(strcmp(item[j],"*")==0){
        ope2=calc(j+1, r);
        if (ope2.cnt==-1) ope2=var[ope2.data[0]];
        ope1=calc(l, j-1);
        if (ope1.cnt==-1) ope1=var[ope1.data[0]];
        return Mul(ope1, ope2);
    }
    if (strcmp(item[l+1], "/")==0){
        ope1=calc(l+2, r);
        if (strcmp(item[l], "+")==0) return compAdd(ope1);
        else if (strcmp(item[l], "-")==0) return compSub(ope1);
        else if (strcmp(item[l], "*")==0) return compMul(ope1);
    }
    return temp;
}

int main(){
    int N;
    scanf("%d ", &N);
    for (int i=0; i<N; i++){
        char line[201]={};
        gets(line);
        int n=-1,t=0,flag=0;
        for(int k=0; line[k]; k++){
            if (line[k]!=' '){
                if (flag==0){n++;t=0;flag=1;}
                item[n][t++]=line[k];
            }
            else{
                if (flag==1) item[n][t]='\0';
                flag=0;
            }
        }
        item[n][t]='\0';
        Vector ans=calc(0,n);
        if (ans.cnt==-1) ans=var[ans.data[0]];
        for (int j=0; j<ans.cnt; j++) 
            printf("%lld%c",ans.data[j], j==ans.cnt-1?'\n':' ');
    }
    return 0;
}
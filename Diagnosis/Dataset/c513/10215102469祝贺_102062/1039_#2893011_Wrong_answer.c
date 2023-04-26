#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
//快排有风险，使用需谨慎
typedef struct ele{
    char name[5];
    long long num[150];
    int top;
    struct ele* selfp;
}element;
element* varia[150];
long long buf[150];
char cbuf[150];
int bufsp=0,variasp=0,cbufsp=0;
int mygets(char*s){
    fgets(s,155,stdin);
    int p=strlen(s)-1;
    s[p]=0;
    return p;
}
long long tonum(char*s, int begin, int end){
    char ans[150];strncpy(ans,s+begin,end-begin+1);
    return atoll(ans);
}
void readnum(element* rval,char* order,int* p){
    int lep=*p-1,rip=*p;
    while(rip>=0 && isdigit(order[rip])){
        while(lep>=0 && isdigit(order[lep]))lep--;
        buf[bufsp++]=tonum(order,lep+1,rip);
        rip=--lep;
    }
    rval->top=bufsp;
    for(int i=0;bufsp>0;i++,bufsp--) rval->num[i]=buf[bufsp-1];
    *p=lep;bufsp=0;
}
element* readvaria(char* order,int* p){//如果找到变量，返回其指针，否则将变量名存进buf中
    int rip=*p;
    for(;rip>=0 && order[rip]!=' ';rip--) cbuf[cbufsp++]=order[rip];
    cbuf[cbufsp++]=0;
    for(int i=0;i<variasp;i++){
        if(strcmp(cbuf,varia[i]->name)==0){
            cbufsp=0;*p=rip;return varia[i];
        }
    }
    element* TempPoint=(element*)malloc(sizeof(element));
    strncpy(TempPoint->name,cbuf,cbufsp);
    TempPoint->top=-1;
    TempPoint->selfp=TempPoint;
    varia[variasp++]=TempPoint;//在表中创立新变量
    cbufsp=0;*p=rip;return TempPoint;//清空缓存
}
void operate1(element *lval,char op,element *rval){
    long long single;element* ans;
    if(rval->top==1){single=rval->num[0];ans=lval;}
    else {single=lval->num[0],ans=rval;}
    switch(op){
        case('+'):{
            for(int i=0;i<ans->top;i++) ans->num[i]+=single;
            break;
        }
        case('-'):{
            for(int i=0;i<ans->top;i++) ans->num[i]-=single;
            break;
        }
        case('*'):{
            for(int i=0;i<ans->top;i++) ans->num[i]*=single;
            break;
        }
        case('='):{
            ans=lval->selfp;
            ans->top=rval->top;
            for(int i=0;i<rval->top;i++) ans->num[i]=rval->num[i];
            break;
        }
        default:break;
    }
    if(single==rval->num[0]){
        rval->top=ans->top;
        for(int i=0;i<ans->top;i++)rval->num[i]=ans->num[i];
        rval->selfp=ans->selfp;
    }
}

void operate2(element *lval,char op,element *rval){
    switch(op){
        case('+'):{
            long long ans=0;element* p=rval->selfp;
            for(int i=0;i<rval->top;i++) ans+=rval->num[i];
            rval->top=1;p->top=1;
            rval->num[0]=ans;p->num[0]=ans;
            break;
        }
        case('-'):{
            //long long ans=0;
            element* p=rval->selfp;
            for(int i=rval->top-2;i>=0;i--)
                rval->num[i]-=rval->num[i+1];
            rval->top=1;p->top=1;
            //rval->num[0]=ans;
            p->num[0]=rval->num[0];
            break;
        }
        case('*'):{
            long long ans=rval->num[0];element* p=rval->selfp;
            for(int i=0;i<rval->top;i++) ans*=rval->num[i];
            rval->top=1;p->top=1;
            rval->num[0]=ans;p->num[0]=ans;
            break;
        }
        default:break;
    }
}

element* solve(char* order,int right){
    element lval={0,0,-1}, rval={0,0,-1};
    element* ans=(element*)malloc(sizeof(element));
    char op;int p=right-1,flag=0,tag=0;
    //flag表示已赋值的元素个数，tag表示运算符的类型
    while(p>=0){
        while(flag+tag<3 && p>=0){
            if(order[p]==' ')p--;
            else if(isdigit(order[p])){
                if(flag==0)readnum(&rval,order,&p);
                else readnum(&lval,order,&p);
                flag++;
            }
            else if(isalpha(order[p])){
                element* addr=readvaria(order,&p);
                if (flag==1) lval=*addr;
                else if(flag==0) rval=*addr;
                flag++;
            }
            else if(order[p]==')'){
                int lep=p-1;char Temp[150];
                while(order[lep]!='(')lep--;
                strncpy(Temp,order+lep+1,p-lep-1);
                if(flag==1) lval=*(solve(Temp,strlen(Temp)));
                else if(flag==0) rval=*(solve(Temp,strlen(Temp)));
                flag++;
                p=lep-1;
            }
            else {//确定运算符，普通运算符tag=1,自增运算符:tag=2；
                if(order[p]=='/'){tag=2;op=order[p-=2];}
                else {tag=1;op=order[p];}
                while(order[p]!=' ')p--;
            }
        }
        if(flag+tag>=3){
            if(tag==1) operate1(&lval,op,&rval);
            else if(tag==2) operate2(&lval,op,&rval);
            flag=1;tag=0;
        }
        else break;//答案保存在右值中
    }
    ans->top=rval.top;
    ans->selfp=rval.selfp;
    for(int i=0;i<rval.top;i++){
        ans->num[i]=rval.num[i];
    }
    printf("%lld\n",ans->num[0]);
    return ans;
}
int main()
{
    long long T;scanf("%lld",&T);getchar();
    while(T--){
        char order[155];
        int right=mygets(order);
        element *ans=solve(order,right);
        for(int i=0;i<ans->top;i++)
            printf("%lld ",ans->num[i]);
        printf("\n");
    }
    return 0;
}

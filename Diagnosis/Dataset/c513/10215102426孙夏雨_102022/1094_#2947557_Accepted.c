#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[121];
    int len;
    int sig;
}DASHU;

int cmp(const void* p3,const void* p4)
{
    DASHU* p1=(DASHU* )p3;
    DASHU* p2=(DASHU* )p4;
    int sig1=p1->sig,sig2=p2->sig;
    int len1=p1->len,len2=p2->len;
    if(sig1<sig2) return -1;
    else if(sig1>sig2) return 1;
    else {
        if(sig1==-1){
            if(len1>len2) return -1;
            else if(len1<len2) return 1;
            else {
                for(int i=0;i<len1;i++){
                    if((p1->s[i])>(p2->s[i])) return -1;
                    else if((p1->s[i])<(p2->s[i])) return 1;
                }
                return -1;
            }
        }
        else{
            if(len1>len2) return 1;
            else if(len1<len2) return -1;
            else {
                for(int i=0;i<len1;i++){
                    if((p1->s[i])>(p2->s[i])) return 1;
                    else if((p1->s[i])<(p2->s[i])) return -1;
                }
                return -1;
            }
        }
    }
}

void add(char* ans,DASHU* p1,DASHU* p2)
{
    int jieguo=0,jinwei=0,num=0;
    int i=(p1->len)-1,j=(p2->len)-1;
    for(;i>=0&&j>=0;i--,j--){
        jieguo=(p1->s[i])-'0'+(p2->s[j])-'0'+jinwei;
        jinwei=jieguo/10;
        jieguo=jieguo%10;
        ans[num]=jieguo+'0';
        num++;
    }
    if(i<0&&j<0&&jinwei>0) ans[num++]=jinwei+'0';
    else if(j>=0){
        for(;j>=0;j--){
            jieguo=(p2->s[j])-'0'+jinwei;
            jinwei=jieguo/10;
            jieguo=jieguo%10;
            ans[num]=jieguo+'0';
            num++;
        }
        if(jinwei>0) ans[num++]=jinwei+'0';
    }
    else if(i>=0){
        for(;i>=0;i--){
            jieguo=(p1->s[i])-'0'+jinwei;
            jinwei=jieguo/10;
            jieguo=jieguo%10;
            ans[num]=jieguo+'0';
            num++;
        }
        if(jinwei>0) ans[num++]=jinwei+'0';
    }
    ans[num]=0;
}

void min(char* ans,DASHU* p1,DASHU* p2)//p2>p1
{
    int len1=p1->len,len2=p2->len,jieguo=0,num=0;
    for(int i=len1-1,j=len2-1;i>=0;i--,j--){
        if(((p2->s[j])-(p1->s[i]))>=0){
            jieguo=(p2->s[j])-(p1->s[i]);
            ans[num]=jieguo+'0';
            num++;
        }
        else {
            jieguo=10+(p2->s[j])-(p1->s[i]);
            ans[num]=jieguo+'0';
            num++;
            if((p2->s[j-1])=='0') {
                int k=j-2;
                p2->s[j-1]='9';
                while(p2->s[k]=='0'){
                    p2->s[k]='9';
                    k--;
                }
                p2->s[k]-=1;
            }
            else p2->s[j-1]-=1;
        }
    }
    for(int z=len2-len1-1;z>=0;z--) {
        ans[num]=p2->s[z];
        num++;
    }
    ans[num]=0;
}

int main()
{
    int n=0;
    scanf("%d",&n);
    DASHU* p=(DASHU* )malloc(n*sizeof(DASHU));
    int num=0,length=0;
    char s0[121];
    for(int i=0;i<n;i++){
        scanf("%s",s0);
        length=strlen(s0);
        if(s0[0]=='-') {
            (p+num)->sig=-1;
            for(int j=1;j<length;j++) (p+num)->s[j-1]=s0[j];
            (p+num)->s[length-1]=0;
            (p+num)->len=length-1;
            num++;
        }
        else {
            (p+num)->sig=1;
            strcpy((p+num)->s,s0);
            (p+num)->len=strlen(s0);
            num++;
        }
    }
    qsort(p,num,sizeof(DASHU),cmp);
    int sig1=p->sig,sig2=(p+num-1)->sig;
    char ans[125];
    if(sig1<sig2) add(ans,p,p+num-1);
    else {
        if(sig1>0) min(ans,p,p+num-1);
        else min(ans,p+num-1,p);
    }
    for(int k=strlen(ans)-1;k>=0;k--) printf("%c",ans[k]);
    printf("\n");
    return 0;
}

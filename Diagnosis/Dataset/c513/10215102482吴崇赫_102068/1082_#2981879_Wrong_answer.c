#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 505

int finddot(char* s)
{
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='.')return i;
    }
    return -1;
}

char* cut(char* s,int l,int r)
{
    char* ret=(char*)malloc(N);
    for(int i=0;i<N;++i)ret[i]=0;
    int p=0;
    for(int i=l;i<r;++i)ret[p++]=s[i];
    return ret;
}

typedef struct
{
    char z[N];
    char x[N];
}fo;

char* xadd(char* s1,char* s2,int* jin)
{
    int a[N],b[N],ret[N];
    for(int i=0;i<N;++i)a[i]=b[i]=ret[i]=0;
    int p1=1,p2=1;
    for(int i=0;i<strlen(s1);++i)a[p1++]=s1[i]-'0';
    for(int i=0;i<strlen(s2);++i)b[p2++]=s2[i]-'0';
    int max=p1>p2?p1:p2;
    for(int i=max-1;i>0;--i){
        if(a[i]+b[i]+ret[i]>9){
            ret[i]+=a[i]+b[i]-10;
            ret[i-1]++;
        }
        else ret[i]+=a[i]+b[i];
    }
    if(ret[0]!=0)*jin=1;
    char *s=(char*)malloc(N);int ps=0;
    while(ret[max]==0&&max>0)max--;
    for(int i=1;i<=max;++i)s[ps++]=ret[i]+'0';
    s[ps]=0;
    return s;
}

void reverse(char* s)
{
    for(int i=0,j=strlen(s)-1;i<j;++i,--j){
        char temp=s[i];s[i]=s[j];s[j]=temp;
    }
}

char* add(char* s1,char* s2)
{
    int a[N],b[N],ret[N];
    char *s=(char*)malloc(N);
    for(int i=0;i<N;++i)a[i]=b[i]=ret[i]=s[i]=0;
    int p1=0,p2=0;
    reverse(s1);reverse(s2);
    for(int i=0;i<strlen(s1);++i)a[p1++]=s1[i]-'0';
    for(int i=0;i<strlen(s2);++i)b[p2++]=s2[i]-'0';
    int max=p1>p2?p1:p2;
    for(int i=0;i<max;++i){
        if(a[i]+b[i]+ret[i]>9){
            ret[i]+=a[i]+b[i]-10;
            ret[i+1]++;
        }
        else ret[i]+=a[i]+b[i];
    }
    max++;
    while(ret[max]==0&&max>0)max--;
    int ps=0;
    for(int i=0;i<=max;++i)s[ps++]=ret[i]+'0';
    //printf("%s\n",s);
    reverse(s);return s;
}

int allnine(char* s)
{
    for(int i=0;i<strlen(s);++i){
        if(s[i]!='9')return 0;
    }
    return 1;
}

int main()
{
    char s1[N],s2[N],temp[N];int n;
    for(int i=0;i<N;++i)s1[i]=s2[i]=0;
    scanf("%s %s %d",s1,s2,&n);
    fo f1,f2,ret;
    for(int i=0;i<N;++i){
        f1.x[i]=f1.z[i]=f2.x[i]=f2.z[i]=0;
        ret.x[i]=ret.z[i]=temp[i]=0;
    }

    if(finddot(s1)==-1){
        strcpy(f1.x,"0");
        strcpy(f1.z,s1);
    }

    if(finddot(s1)==0){
        strcpy(f1.x,cut(s1,1,strlen(s1)));
        strcpy(f1.z,"0");
    }
    if(finddot(s1)==strlen(s1)-1){
        strcpy(f1.z,cut(s1,0,strlen(s1)-1));
        strcpy(f1.x,"0");
    }
    if(finddot(s2)==-1){
        strcpy(f2.x,"0");
        strcpy(f2.z,s2);
    }
    if(finddot(s2)==0){
        strcpy(f2.x,cut(s2,1,strlen(s2)));
        strcpy(f2.z,"0");
    }

    if(finddot(s2)==strlen(s2)-1){
        strcpy(f2.z,cut(s2,0,strlen(s2)-1));
        strcpy(f2.x,"0");
    }
    if(finddot(s1)!=0&&finddot(s1)!=strlen(s1)-1&&finddot(s1)!=-1){
        strcpy(f1.z,cut(s1,0,finddot(s1)));
        strcpy(f1.x,cut(s1,finddot(s1)+1,strlen(s1)));
    }
    if(finddot(s2)!=0&&finddot(s2)!=strlen(s2)-1&&finddot(s2)!=-1){
        strcpy(f2.z,cut(s2,0,finddot(s2)));
        strcpy(f2.x,cut(s2,finddot(s2)+1,strlen(s2)));
    }
    //printf("%s %s\n",f1.z,f1.x);
    //printf("%s %s\n",f2.z,f2.x);

    int jin=0;
    strcpy(ret.x,xadd(f1.x,f2.x,&jin));
    strcpy(temp,add(f1.z,f2.z));
    if(jin==1) strcpy(ret.z,add(temp,"1"));
    else strcpy(ret.z,temp);
    //printf("%s\n",add("234","89"));
    int c=strlen(ret.x);
    if(c<n){
        int cha=n-c;
        while(cha--)strcat(ret.x,"0");
    }
    else{
        //int flag=0;
        if(ret.x[n]<'5')ret.x[n]=0;
        else {
            if(!allnine(cut(ret.x,0,n)))strcpy(ret.x,add(cut(ret.x,0,n),"1"));
            else {
                int _n=n;
                strcpy(ret.z,add(ret.z,"1"));
                while(n--)ret.x[n]='0';
                ret.x[_n]=0;
            }
        }
    }

    printf("%s.%s",ret.z,ret.x);


    return 0;

}
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//#define LOCAL

#define NUMSIZE 60
int getlen(int arr[])
{
    int len=NUMSIZE;
    while(len>=0&&arr[len]==0)--len;
    return len+1;
}
int prime[27]={2,3,5,7,11,13,17,19};
void initialNUM()
{
    int num=20,pos=8;
    while(pos<26){
        int isprime=1;
        for(int k=2;k<=sqrt(num);++k){
            if(!(num%k)){
                isprime=0;
                break;
            }
        }
        if(isprime)prime[pos++]=num;
        ++num;
    }
}

char temnum[50];
int getarray(int iarr[])
{
    int pos=0,arrlen=0;
    char c;
    do{
        pos=0;
        while((c=getchar())=='\n');//remove possible blocks
        temnum[pos++]=c;
        while((c=getchar())!=','&&c!=' '&&c!='\n'&&c!=EOF)temnum[pos++]=c;
        temnum[pos]='\0';//end it
        iarr[arrlen++]=atoi(temnum);
    }while(c==',');
    reverseARR(iarr,arrlen);
    return arrlen;
}
void reverseARR(int arr[],int len)
{
    int tem;
    for(int i=0,j=len-1;i<j;++i,--j){
        tem=arr[i];
        arr[i]=arr[j];
        arr[j]=tem;
    }
}

int resarr[NUMSIZE];
int prinum[NUMSIZE];
int pronum[NUMSIZE];
void adduparr(int ansarr[],int addarr[])
{
    for(int i=0;i<NUMSIZE;++i){
        ansarr[i]+=addarr[i];
    }
}
int resofmult[NUMSIZE];
int* highmult(int arr1[],int arr2[])
{
    memset(resofmult,0,NUMSIZE*sizeof(int));
    int len1=getlen(arr1);
    int len2=getlen(arr2);
    if(len1!=0&&len2!=0){
        for(int i1=0;i1<len1;++i1){
            for(int i2=0;i2<len2;++i2){
                resofmult[i1+i2]=arr1[i1]*arr2[i2];
            }
        }
        for(int i=0;i<NUMSIZE-1;++i){
            if(resofmult[i]>=10){
                resofmult[i+1]+=resofmult[i]/10;
                resofmult[i]%=10;
            }
        }
    }
    return resofmult;
}

int temresofhigh[NUMSIZE];
int* highenACC(int x){//10 type
    memset(temresofhigh,0,NUMSIZE*sizeof(int));
    int pos=0;
    while(x!=0){
        temresofhigh[pos++]=x%10;
        x/=10;
    }
    //
    return temresofhigh;
}

void copyarr(int to[],int from[])
{
    for(int i=0;i<NUMSIZE;++i){
        to[i]=from[i];
    }
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    initialNUM();
    int T,relen=26,innum;
    T=1;//special
    for(int iT=0;iT<T;++iT){
        relen=26;
        memset(resarr,0,NUMSIZE*sizeof(int));
        memset(prinum,0,NUMSIZE*sizeof(int));
        memset(pronum,0,NUMSIZE*sizeof(int));
        //printf("case #%d:\n",iT);
        innum=getarray(prinum);//deal with the input
        pronum[0]=1;//initialize pronum
        for(int pos=0;pos<innum;++pos){
            copyarr(pronum,highmult(pronum,highenACC(prime[pos])));
            adduparr(resarr,highenACC(prinum[pos]));
        }

        //resarr½øÎ»
        relen=getlen(resarr);
        if(relen==0){
            printf("%d",0);
        }
        else{
            for(int k=relen-1;k>=0;--k){
                printf("%d ",resarr[k]);
            }
        }
    }
    return 0;
}

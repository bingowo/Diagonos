#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//#define LOCAL
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

int Barr[40],resarr[40];
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    initialNUM();
    int T,Blen,relen=26;
    scanf("%d",&T);
    for(int iT=0;iT<T;++iT){
        relen=26;
        memset(resarr,0,40*sizeof(int));
        memset(Barr,0,40*sizeof(int));
        printf("case #%d:\n",iT);
        getarray(resarr);//deal with the input
        Blen=getarray(Barr);

        for(int i=0;i<Blen;++i){resarr[i]+=Barr[i];}
        for(int i=0;i<relen;++i){
            if(resarr[i]>=prime[i]){
                resarr[i+1]+=resarr[i]/prime[i];
                resarr[i]%=prime[i];
            }
        }
        while(relen>=0&&resarr[relen]==0)--relen;
        ++relen;
        if(relen>=1){
            for(int k=relen-1;k>0;--k){
                printf("%d,",resarr[k]);
            }
        }
        printf("%d\n",resarr[0]);
    }
    return 0;
}

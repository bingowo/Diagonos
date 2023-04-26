#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int N;
void solveint(char *A,char *B)
{
    char c[1000],d[1000];
    int m=0;
    int len1=strlen(A),len2=strlen(B);
    for(int i=0;i<len1;i++)c[len1-i-1]=A[i];
    strcpy(A,c);
    for(int i=0;i<len2;i++)d[len2-i-1]=B[i];
    strcpy(B,d);
    for(int i=0;i<len2;i++){
        m=i;
        A[i]=A[i]+B[i]-48;
        while(A[m]>'9'){
            A[m]-=10;
            A[m+1]++;
            m++;
        }
    }
    for(int i=0;i<len1;i++)c[i]=A[len1-i-1];
    strcpy(A,c);
    int startp=len1-1;
    for(int i=0;i<len1;i++){
        if(A[i]!='0'){
            startp=i;
            break;
        }
    }
    for(int i=startp;i<len1;i++)printf("%c",A[i]);
}
int main()
{
    char a[1000],b[1000];
    int flaga=1,flagb=1;
    scanf("%s",a);scanf("%s",b);
    scanf("%d",&N);
    if(strchr(a,'.') == NULL){flaga=0;a[strlen(a)] = '.';a[strlen(a)] = '0';a[strlen(a)]=0;}
    if(strchr(b,'.') == NULL){flagb=0;b[strlen(b)] = '.';b[strlen(b)] = '0';b[strlen(b)]=0;}
    int dotpa=0,dotpb=0;
    for(int i=0;;i++)if(a[i]=='.'){dotpa=i;break;}
    for(int i=0;;i++)if(b[i]=='.'){dotpb=i;break;}
    char intA[1000],intB[1000],resA[1000],resB[1000];
    if(dotpa==0||(a[0]=='0'&&isdigit(a[1])==0)){intA[0]='0';intA[1]=0;}
    //a,b整数部分
    else for(int i=0;i<dotpa;i++){
        intA[i]=a[i];
        if(i==dotpa-1)intA[dotpa]=0;
    }
    if(dotpb==0||b[0]=='0'&&isdigit(b[1])==0){intB[0]='0';intB[1]=0;}
    else for(int i=0;i<dotpb;i++){
        intB[i]=b[i];
        if(i==dotpb-1)intB[dotpb]=0;
    }
    //a，b小数部分
    if(flaga==0){resA[0]='0';resA[1]=0;}
    else if(dotpa==strlen(a)-1){resA[0]='0';resA[1]=0;}
    else for(int i=dotpa+1;i<strlen(a);i++){
        resA[i-dotpa-1]=a[i];
        if(i==strlen(a)-1)resA[i-dotpa]=0;
    }
    if(flagb==0){resB[0]='0';resB[1]=0;}
    else if(dotpb==strlen(b)-1){resB[0]='0';resB[1]=0;}
    else for(int i=dotpb+1;i<strlen(b);i++){
        resB[i-dotpb-1]=b[i];
        if(i==strlen(b)-1)resB[i-dotpb]=0;
    }
    int rlen=strlen(resA)>strlen(resB)?strlen(resA):strlen(resB);

        if(rlen>N)for(int i=strlen(resA);i<rlen;i++)resA[i]=48;
        else for(int i=strlen(resA);i<N;i++)resA[i]=48;
        int k=0;
        for(int i=strlen(resB)-1;i>=0;i--){
            resA[i]=resA[i]+resB[i]-48;
            int k=i;
            while(resA[k]>'9'){
                resA[k]-=10;
                resA[k-1]++;
                k--;
            }
        }
        if(resA[N]>='5'){
            resA[N-1]++;
            for(int i=N-1;i>=0;i--)
                if(resA[i]>'9'){
                    if(resA[0]>'9'){
                        resA[0]=48;intA[strlen(intA)-1]++;
                    }
                    resA[i]='0';resA[i-1]++;}
                else break;
        }
        solveint(intA,intB);printf(".");
        for(int i=0;i<N;i++)printf("%c",resA[i]);
    return 0;
}

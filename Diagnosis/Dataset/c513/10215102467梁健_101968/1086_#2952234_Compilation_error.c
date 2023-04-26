#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int N;
void solveint(char *A,char *B)
{
    char c[1000],d[1000];
    int m;
    int len1=strlen(A),len2=strlen(B);
    for(int i=0;i<len1;i++)c[len1-i-1]=A[i];
    strcpy(A,c);
    for(int i=0;i<len2;i++)d[len2-i-1]=B[i];
    strcpy(B,d);
    for(int i=0;i<len2;i++){
        m=i;
        A[i]=A[i]-B[i]+48;
        while(A[m]<48){
            A[m]+=10;
            A[m+1]--;
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
int judgeres(char *A,char *B)
{
    if(strcmp(A,B)>=0)return 1;
    else return 0;
}
int main()
{
    char a[550],b[550];
    scanf("%s",a);scanf("%s",b);
    //scanf("%d",&N);
    if(strchr(a,'.') == NULL){a[strlen(a)] = '.';a[strlen(a)] = '0';}
    if(strchr(b,'.') == NULL){b[strlen(b)] = '.';b[strlen(b)] = '0';}
    int dotpa=0,dotpb=0;
    for(int i=0;;i++)if(a[i]=='.'){dotpa=i;break;}
    for(int i=0;;i++)if(b[i]=='.'){dotpb=i;break;}
    char intA[550],intB[550],resA[550],resB[550];
    if(dotpa==0||a[0]=='0'){intA[0]='0';intA[1]=0;}
    else for(int i=0;i<dotpa;i++)intA[i]=a[i];
    if(dotpb==0||b[0]=='0'){intB[0]='0';intB[1]=0;}
    else for(int i=0;i<dotpb;i++)intB[i]=b[i];
    for(int i=dotpa+1;i<strlen(a);i++)resA[i-dotpa-1]=a[i];
    for(int i=dotpb+1;i<strlen(b);i++)resB[i-dotpb-1]=b[i];
    //A>=B的情况
    //printf("lenA=%d,lenB=%d,intA=%s,intB=%s\n",strlen(intA),strlen(intB),intA,intB);
    if(strlen(intA)>strlen(intB)||(strlen(intA)==strlen(intB)&&(s))){
        if(judgeres(resA,resB)==1)solveint(intA,intB);
        else{
            intA[strlen(intA)-1]--;solveint(intA,intB);
        }
    }
    //A<B的情况
    else{
        printf("-");
        if(judgeres(resB,resA)==1)solveint(intB,intA);
        else{
            intB[strlen(intB)-1]--;solveint(intB,intA);
        }
    }
    return 0;
}

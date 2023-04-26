#include<math.h>
#include<string.h>
#include<stdio.h>
int main()
{
    int A,B;
    char *n,*p,*q;
    scanf("%d %s %d",&A,n,&B);
    int len=strlen(n);
    int r,j=len-1,i=0,m=0,x=0,t=0;
    if(A<11){
        for(j=len-1,i=0;j>=0,i<len;j--,i++){
            r+=((int)n[j])*pow(A,i);
        }
    while(r){
        q[m]=(r%B);
        r/=B;
        x++;
    }
    for(m=x-1,t=0;m>=0,t<x;m--,t++){
        p[t]=q[m];
    }
    }
    else{
        char c;
        for(i=0;;i++){
        if(c=getchar())=='A'||c=getchar())=='a') r+=10*pow(A,i);
        else if(c=getchar())=='B'||c=getchar())=='b')r+=11*pow(A,i);
        else if(c=getchar())=='C'||c=getchar())=='c')r+=12*pow(A,i);
        else if(c=getchar())=='D'||c=getchar())=='d')r+=13*pow(A,i);
        else if(c=getchar())=='E'||c=getchar())=='e')r+=14*pow(A,i);
        else if(c=getchar())=='F'||(c=getchar())=='f')r+=15*pow(A,i);
        else r+=(int)(c=getchar())*pow(A,i);
        
    }
    while(r){
        if((r%B)<10){
        q[m]=(r%B);}
        else{
            if((r%B)==10)q[m]='A';
            else if((r%B)==11)q[m]='B';
            else if((r%B)==12)q[m]='C';
            else if((r%B)==13)q[m]='D';
            else if((r%B)==14)q[m]='E';
            else q[m]='F';
        }
        r/=B;
        x++;
    }
    for(m=x-1,t=0;m>=0,t<x;m--,t++){
        p[t]=q[m];
    }
}
    printf("%s",p);
    return 0;
}
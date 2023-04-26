#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int cmp(int*a1,int*a2){
    for (int i=99;i>0;i--)
        if (a1[i]>a2[i]) return 1;
        else if (a1[i]<a2[i]) return -1;
    return 1;
}
void time(int*a1,int*a2,int b){
    if (b<0) {b=-b;a1[0]=-a2[0];}
    else a1[0]=a2[0];
    for (int i=1;i<100;i++)
        a1[i]=a2[i]*b;
    int carry=0;
    for (int i=1;i<100;i++){
        a1[i]=a1[i]+carry;
        carry=a1[i]/10;
        a1[i]=a1[i]%10;
    }
}
void plus(int*ans,int*a1,int*a2){
    if (a1[0]==a2[0]){
        ans[0]=a1[0];
        for (int i=1;i<100;i++)
            ans[i]=a1[i]+a2[i];
        int carry=0;
        for (int i=1;i<100;i++){
            ans[i]+=carry;
            carry=ans[i]/10;
            ans[i]=ans[i]%10;
        }
    }
    else if (cmp(a1,a2)){
        ans[0]=a1[0];
        int carry=0;
        for (int i=1;i<100;i++){
            ans[i]=a1[i]-a2[i]-carry;
            if (ans[i]<0) {ans[i]+=10;carry=1;}
            else carry=0;
        }
    }
    else {
        ans[0]=a2[0];
        int carry=0;
        for (int i=1;i<100;i++){
            ans[i]=a2[i]-a1[i]-carry;
            if (ans[i]<0) {ans[i]+=10;carry=1;}
            else carry=0;
        }
    }
}
int main()
{
    char c[20];
    int n;
    char *s1=c;
    scanf("%s%d",c,&n);
    int d,e;
    if (strchr(c,'i')==NULL){
        d=atoi(c);
        e=0;
    }
    else if ((strrchr(c,'-')!=s1 && strrchr(c,'-')!=NULL)||(strrchr(c,'+')!=s1 && strrchr(c,'+')!=NULL)){
            int i=0;
            int point=1;
            if (c[i]=='-') {point=-1;i++;}
            d=0;
            while (c[i]!='-'&&c[i]!='+') d=d*10+c[i++]-'0';
            d=d*point;
            point=1;
            e=0;
            if (c[i]=='-') point=-1;
            i++;
            if (c[i]=='i') e=point;
            else {
                while (c[i]!='i') e=e*10+c[i++]-'0';
                e=e*point;
            }

    }
    else {
        d=0;
        if (c[0]=='-') {
            if (c[1]=='i') e=-1;
            else {
                e=0;
                int i=1;
                while (c[i]!='i') e=e*10+c[i++]-'0';
                e=-e;
            }
        }
        else if (c[0]=='i') e=1;
        else {
            e=0;
            int i=0;
            while(c[i]!='i') e=e*10+c[i++]-'0';
        }

    }

    if (n==0) printf("1\n");
    else{

        int a1[100],a2[100],a3[100],a4[100];
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        memset(a3,0,sizeof(a3));
        memset(a4,0,sizeof(a4));
        int f1[100],f2[100];
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        f1[0]=1;
        f2[0]=1;
        f1[1]=1;
        f2[1]=0;


        for (int i=0;i<n;i++){
            memset(a1,0,sizeof(a1));
            memset(a2,0,sizeof(a2));
            memset(a3,0,sizeof(a3));
            memset(a4,0,sizeof(a4));
            time(a1,f1,d);
            time(a2,f2,-e);
            time(a3,f1,e);
            time(a4,f2,d);
            plus(f1,a1,a2);
            plus(f2,a3,a4);
            

        }



        if (f1[0]==-1) printf("-");
        int i=99;
        while(f1[i]==0)i--;
        for (;i>=1;i--) printf("%d",f1[i]);

        i=99;
        while (i>=1&&f2[i]==0) i--;
        if (i!=0){
        if (f2[0]==-1) printf("-");
        else printf("+");
        if (i!=1||f2[i]!=1)
        for(;i>=1;i--) printf("%d",f2[i]);
        printf("i\n");}
    }
    return 0;
}
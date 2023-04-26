#include<stdio.h>
#include<string.h>
#include<ctype.h>
void solve3(char*s1,char*s2){
    char a1,a2,b1,b2;
    char o1[40];
    if(strlen(s1)==2){a1=s1[0];b1=s1[1];}
    else {a1='C';b1=s1[2];}
    if(strlen(s2)==2){a2=s2[0];b2=s2[1];}
    else {a2='C';b2=s2[2];}

    if((a1=='A' && a2=='B' || a1=='B' && a2=='A') && (b1=='-' && b2=='-')) strcpy(o1,"{A-,AB-,B-,O-}");
    else if((a1=='A' && a2=='B' || a1=='B' && a2=='A') && !(b1=='-' && b2=='-')) strcpy(o1,"{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if((a1=='A' && a2=='C' || a1=='C' && a2=='A') && (b1=='-' && b2=='-')) strcpy(o1,"{A-,AB-,B-}");
    else if((a1=='A' && a2=='C' || a1=='C' && a2=='A') && !(b1=='-' && b2=='-')) strcpy(o1,"{A+,A-,AB+,AB-,B+,B-}");
    else if((a1=='A' && a2=='O' || a1=='O' && a2=='A') && (b1=='-' && b2=='-')) strcpy(o1,"{A-,O-}");
    else if((a1=='A' && a2=='O' || a1=='O' && a2=='A') && !(b1=='-' && b2=='-')) strcpy(o1,"{A+,A-,O+,O-}");
    else if((a1=='C' && a2=='B' || a1=='B' && a2=='C') && (b1=='-' && b2=='-')) strcpy(o1,"{A-,AB-,B-}");
    else if((a1=='C' && a2=='B' || a1=='B' && a2=='C') && !(b1=='-' && b2=='-')) strcpy(o1,"{A+,A-,AB+,AB-,B+,B-}");
    else if((a1=='O' && a2=='B' || a1=='B' && a2=='O') && (b1=='-' && b2=='-')) strcpy(o1,"{B-,O-}");
    else if((a1=='O' && a2=='B' || a1=='B' && a2=='O') && !(b1=='-' && b2=='-')) strcpy(o1,"{B+,B-,O+,O-}");
    else if((a1=='C' && a2=='O' || a1=='O' && a2=='C') && (b1=='-' && b2=='-')) strcpy(o1,"{A-,B-}");
    else if((a1=='C' && a2=='O' || a1=='O' && a2=='C') && !(b1=='-' && b2=='-')) strcpy(o1,"{A+,A-,B+,B-}");
    else if((a1=='A' && a2=='A') && (b1=='-' && b2=='-')) strcpy(o1,"A-");
    else if((a1=='A' && a2=='A') && !(b1=='-' && b2=='-')) strcpy(o1,"{A+,A-}");
    else if((a1=='B' && a2=='B') && (b1=='-' && b2=='-')) strcpy(o1,"B-");
    else if((a1=='B' && a2=='B') && !(b1=='-' && b2=='-')) strcpy(o1,"{B+,B-}");
    else if((a1=='C' && a2=='C') && (b1=='-' && b2=='-')) strcpy(o1,"{A-,B-,AB-}");
    else if((a1=='C' && a2=='C') && !(b1=='-' && b2=='-')) strcpy(o1,"{A+,A-,B+,B-,AB+,AB-}");
    else if((a1=='O' && a2=='O') && (b1=='-' && b2=='-')) strcpy(o1,"O-");
    else if((a1=='O' && a2=='O') && !(b1=='-' && b2=='-')) strcpy(o1,"{O+,O-}");

    printf("%s %s %s\n",s1,s2,o1);
}

void solve(int pos, char* s, char*s3){
    char a1,a2,b1,b2;
    char o1[40];
    if(strlen(s)==2){a1=s[0];b1=s[1];}
    else {a1='C';b1=s[2];}
    if(strlen(s3)==2){a2=s3[0];b2=s3[1];}
    else {a2='C';b2=s3[2];}

    if((a1==a2 && a1!='C' && a1!='O') && !(b1=='-' && b2=='+'))strcpy(o1,"A+,A-,AB+,AB-,B+,B-,O+,O-");
    else if((a1==a2 && a1!='C' && a1!='O') && (b1=='-' && b2=='+'))strcpy(o1,"A+,AB+,B+,O+");
    else if((a1==a2 && a1=='O') && !(b1=='-' && b2=='+'))strcpy(o1,"A+,A-,B+,B-,O+,O-");
    else if((a1==a2 && a1=='O') && (b1=='-' && b2=='+'))strcpy(o1,"A+,B+,O+");
    else if((a1==a2 && a1=='C') && !(b1=='-' && b2=='+'))strcpy(o1,"A+,A-,AB+,AB-,B+,B-");
    else if((a1==a2 && a1=='C') && (b1=='-' && b2=='+'))strcpy(o1,"A+,AB+,B+");
    else if((a1=='A' && (a2=='B' || a2=='C')) && !(b1=='-' && b2=='+'))strcpy(o1,"AB+,AB-,B+,B-");
    else if((a1=='A' && (a2=='B' || a2=='C')) && (b1=='-' && b2=='+'))strcpy(o1,"AB+,B+");
    else if((a1=='A' && a2=='O') && !(b1=='-' && b2=='+'))strcpy(o1,"A+,A-,B+,B-,O+,O-");
    else if((a1=='A' && a2=='O') && (b1=='-' && b2=='+'))strcpy(o1,"A+,B+,O+");
    else if((a1=='B' && (a2=='A' || a2=='C')) && !(b1=='-' && b2=='+'))strcpy(o1,"A+,A-,AB+,AB-");
    else if((a1=='B' && (a2=='A' || a2=='C')) && (b1=='-' && b2=='+'))strcpy(o1,"A+,AB+");
    else if((a1=='B' && a2=='O') && !(b1=='-' && b2=='+'))strcpy(o1,"A+,A-,B+,B-,O+,O-");
    else if((a1=='B' && a2=='O') && (b1=='-' && b2=='+'))strcpy(o1,"A+,B+,O+");
    else if((a1=='C' && (a2=='A' || a2=='B')) && !(b1=='-' && b2=='+'))strcpy(o1,"A+,A-,AB+,AB-,B+,B-,O+,O-");
    else if((a1=='C' && (a2=='A' || a2=='B')) && (b1=='-' && b2=='+'))strcpy(o1,"A+,AB+,B+,O+");
    else if((a1=='O' && a2=='A') && !(b1=='-' && b2=='+'))strcpy(o1,"A+,A-,AB+,AB-");
    else if((a1=='O' && a2=='A') && (b1=='-' && b2=='+'))strcpy(o1,"A+,AB+");
    else if((a1=='O' && a2=='B') && !(b1=='-' && b2=='+'))strcpy(o1,"AB+,AB-,B+,B-");
    else if((a1=='O' && a2=='B') && (b1=='-' && b2=='+'))strcpy(o1,"AB+,B+");
    else strcpy(o1,"impossible");

    if(pos==1)printf("{%s} %s %s\n",o1,s,s3);
    else printf("%s {%s} %s\n",s,o1,s3);
}
int main(){
    int pro;
    scanf("%d",&pro);
    for(int index=0;index<pro;index++){
        char s1[10],s2[10],s3[10];scanf("%s%s%s",s1,s2,s3);
        if(s3[0]=='?')solve3(s1,s2);
        else if(s1[0]=='?')solve(1,s2,s3);
        else solve(2,s1,s3);
    }
    return 0;
}

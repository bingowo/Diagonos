#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[50]={0};
    while(scanf("%s",s)!=EOF)
    {
        char tu[42][42]={0};
    int i=0,j=0;
    for(i=0;i<41;i++){for(j=0;j<41;j++)tu[i][j]='.';}
    for(i=0;i<41;i++){if(i==0)tu[i][20]='^';else tu[i][20]='|';}
    for(i=0;i<41;i++){if(i==41)tu[20][i]='>';else tu[20][i]='-';}
    tu[20][20]='+';
    int m=0,n=0,f=1,q=0,g=0;int p[4];memset(p,0,sizeof(int)*4);
    for(m=5;s[m];)
    {   f=1;q=0;
        if(s[m]=='-'){f=-1;m++;}if(s[m]=='+'){f=1;m++;}
        while(isdigit(s[m])){q=q*10+(s[m]-'0');m++;}if(q==0)q=1;q=q*f;
        if(s[m]=='x'){m++;if(s[m]=='^'){m++;p[s[m]-'0']=q;m++;}else p[1]=q;}
        else {p[0]=q;m++;}
    }
    for(m=0;m<=20;m++){g=0;g=p[0]+p[1]*m+p[2]*m*m+p[3]*m*m*m;if(abs(g)<=20){tu[20-g][20+m]='*';}}
    for(m=0;m>=-20;m--){g=0;g=p[0]+p[1]*m+p[2]*m*m+p[3]*m*m*m;if(abs(g)<=20){tu[20-g][20+m]='*';}}
    for(i=0;i<41;i++){for(j=0;j<41;j++)printf("%c",tu[i][j]);printf("\n");}
    memset(s,0,sizeof(char)*50);
    }
    return 0;
}

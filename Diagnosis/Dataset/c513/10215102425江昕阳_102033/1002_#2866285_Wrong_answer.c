#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{long long int T,y=0,sm=0,x,p,h;char s[100],s1[100];
scanf("%lld",&T);
for(int i=0;i<T;i++){
scanf("%s",s1);
s[0]=s1[0];s[1]='\0';
for(int k=0;k<strlen(s1);k++){
    for(int j=0;j<strlen(s);j++){if(s[j]==s1[k]){y=1;};}
    if(y==0){p=strlen(s);s[p]=s1[k];s[p+1]='\0';};
    y=0;
};
h=2;if(strlen(s)>2){h=strlen(s);};
for(int k=0;k<strlen(s1);k++){
    for(int j=0;j<strlen(s);j++){if(s[j]==s1[k]){x=j;if(j==0){x=1;};if(j==1){x=0;};};};
    for(int f=0;f<strlen(s1)-k-1;f++){x=x*h;};
    sm=sm+x;
}
printf("case #%d:\n",i);
printf("%lld\n",sm);
}
    return 0;
}

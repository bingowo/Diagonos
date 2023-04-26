#include <stdio.h>
#include <string.h>
#define N 100
char s[30]={0};
int find_1(char a[],int position){int hh=0;if(a[position]>='a'&&a[position]<='z') hh+='a'-'A';
    for(int i=0;i<30;i++) {if(a[position]-hh==s[i]) {return i;break;}}}
int main(){int num=0;char re[10000][30]={0};while(scanf("%s",&s)!=EOF){int ori=0;char a[N+1][30]={0};char c;c=getchar();c=getchar();while(c!='\n'){ungetc(c,stdin);scanf("%s",&a[ori++]);c=getchar();}
    int or[100]={0};int oo=0;if(ori){for(int o=0;o<ori;o++){ char b[40]={0};int min=o;
    for(int oo=o+1;oo<ori;oo++){for(int j=0;j<strlen(a[min])&&j<strlen(a[oo]);j++){
    if(find_1(a[min],j)<find_1(a[oo],j))break;if(find_1(a[min],j)>find_1(a[oo],j)){min=oo;break;}}}
    if(min!=o){strcpy(b,a[min]);strcpy(a[min],a[o]);strcpy(a[o],b);}}}
    for(int i=0;i<ori;i++)strcpy(re[num++],a[i]);strcpy(re[num++]," ");}
    for(int kk=0;kk<num;kk++) {if(re[num]==" "){printf("11");continue;}else printf("%s%c",re[kk],' ');}
    return 0;
}
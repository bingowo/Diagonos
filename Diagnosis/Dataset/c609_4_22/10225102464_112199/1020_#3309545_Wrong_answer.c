#include <stdio.h>
#include <string.h>
#define N 100
int main(){char a[N][40];char c[N][40];char s[40];int i,j=0;
    while(scanf("%s",s)!=EOF){int k,l;for(k=0,l=0;k<strlen(s);k++){if(isdigit(s[k])){strcpy(c[i++],s);l++;break;}}
        if(l==0)strcpy(a[j++],s);}
    if(j){for(int o=0;o<j;o++){ char b[40];int min=o;for(int oo=o+1;oo<j;oo++){if(strcmp(a[min],a[oo])>0) min=oo;}
                           if(min!=o){strcpy(b,a[min]);strcpy(a[min],a[o]);strcpy(a[o],b);}}
    for(int ii=0;ii<j;ii++) printf("%s%c",a[ii],ii==j-1?(i==0?'\n':' '):' ');}
    if(i){for(int o=0;o<i;o++){ char b[40];int min=o;for(int oo=o+1;oo<i;oo++){if(strcmp(c[min],c[oo])>0) min=oo;}
                           if(min!=o){strcpy(b,c[min]);strcpy(c[min],c[o]);strcpy(c[o],b);}}}
    if(i){for(int o=0;o<i;o++){ char b[40];int min=o;for(int oo=o+1;oo<i;oo++){char c_1[40];char c_2[40];int ll_1=0;int ll_2=0;
          for(int k=0;k<strlen(c[min]);k++){if(isdigit(c[min][k]))c_1[ll_1++]=c[min][k];}
          for(int k=0;k<strlen(c[oo]);k++){if(isdigit(c[oo][k]))c_2[ll_2++]=c[oo][k];}
          c_1[ll_1]='\0';c_2[ll_2]='\0';if(atoi(c_1)>atoi(c_2)) min=oo;}
          if(min!=o){strcpy(b,c[min]);strcpy(c[min],c[o]);strcpy(c[o],b);}}
    for(int ii=0;ii<i;ii++) printf("%s%c",c[ii],ii==i-1?'\n':' ');}
    return 0;
}


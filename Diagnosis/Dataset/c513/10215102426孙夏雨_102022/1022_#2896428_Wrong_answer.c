#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* p3,const void* p4)
{
    char* p1=(char* )p3;
    char* p2=(char* )p4;
    int len1=strlen(p1);
    int len2=strlen(p2);
    int x=0,y=0,i=0,j=0,q=0;
    while(i<len1||j<len2){
        if(((p1[i])<(p2[j]))&&q==0) q=-1;
        else if((p1[i])>(p2[j])&&q==0) q=1;
        if(p1[i]=='@') x=i+1;
        else {
            if(x==0) i++;
        }
        if(p2[j]=='@') y=j+1;
        else {
            if(y==0) j++;
        }
        if(x>0&&y>0) break;
    }
    while(x<len1&&y<len2){
        if(p1[i]<p2[j]) return -1;
        else if(p1[i]>p2[j]) return 1;
        x++;
        y++;
    }
    if(len1<len2) return -1;
    else if(len1>len2) return 1;
    else if(q<0) return 1;
    else return -1;
}

int main()
{
    int n=0;
    scanf("%d",&n);
    int w=1000000/n;
    char** p=(char**)malloc(n*sizeof(char*));
    for(int t=0;t<n;t++) {
        p[t]=(char* )malloc(w*sizeof(char));
        scanf("%s",*(p+t));
    }
    qsort(p,n,sizeof(char)*w,cmp);
    for(int jj=0;jj<n;jj++) printf("%s",*(p+jj));
    for(int rr=0;rr<n;rr++) free(p[rr]);
    free(p);
    return 0;
}

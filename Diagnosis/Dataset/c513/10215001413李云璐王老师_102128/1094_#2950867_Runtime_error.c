#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int cmp(const void*a1,const void*a2)
{
    char*a=*(char**)a1;
    char*b=*(char**)a2;
    int len1=strlen(a),len2=strlen(b);
    if(len1!=len2) return len1-len2;
    else if(a[0]!=b[0]) return a[0]-b[0];
    else if(a[1]!=b[1]) return a[1]-b[1];
    else if(a[2]!=b[2]) return a[2]-b[2];
    else if(a[3]!=b[3]) return a[3]-b[3];
    else if(a[4]!=b[4]) return a[4]-b[4];
    else if(a[5]!=b[5]) return a[5]-b[5];
    else if(a[6]!=b[6]) return a[6]-b[6];
    else if(a[7]!=b[7]) return a[7]-b[7];
    else if(a[8]!=b[8]) return a[8]-b[8];
    else if(a[9]!=b[9]) return a[9]-b[9];
    else return a[10]-b[10];
}
int main()
{
    int n;
    scanf("%d",&n);
    char s[51][130];
    for(int i=0;i<n;i++)
    scanf("%s",s[i]);
    qsort(s,n,sizeof(s[0]),cmp);
    for(int i=0;i<n;i++)
    scanf("%s",s[i]);
    return 0;
       
    
}
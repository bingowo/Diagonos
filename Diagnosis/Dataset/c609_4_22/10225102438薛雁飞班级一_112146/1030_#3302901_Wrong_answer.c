#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double a[26];
int cmp(const void *p1,const void *p2)
{
    char c1,c2;
    c1=*((char*)p1);c2=*((char*)p2);
    if((c1>='a')&&(c2<='Z')){
            if((c1-'a')==(c2-'A'))return -1;
            else {
                if(a[c2-'A']>=a[c1-'a'])return 1;
                else return -1;
            }
    }
    else if((c2>='a')&&(c1<='Z')){
            if((c2-'a')==(c1-'A'))return 1;
            else {
                if(a[c2-'a']>=a[c1-'A'])return 1;
                else return -1;
            }
    }
    else if((c1>='a')&&(c2>='a')){
            if(a[c2-'a']>a[c1-'a'])return 1;
            else if(a[c2-'a']<=a[c1-'a'])return -1;
            else return(c1-c2);
    }
    else if((c1<='Z')&&(c2<='Z')){
            if(a[c2-'A']>a[c1-'A'])return 1;
            else if(a[c2-'A']<=a[c1-'A'])return -1;
            else return(c1-c2);
    }

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int j=0;j<t;j++){
        for(int i=0;i<26;i++){
            double p;
            scanf("%lf",&p);
            a[i]=p;
        }
        char s[101];
        scanf("%s",s);
        int len=strlen(s);
        qsort(s,len,sizeof(s[0]),cmp);
        printf("case #%d:\n",j);
        printf("%s\n",s);
    }
    return 0;
}

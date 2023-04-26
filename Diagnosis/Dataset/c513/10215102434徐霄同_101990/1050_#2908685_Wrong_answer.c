#include <stdio.h>
#include <string.h>

int main()
{
    char s1[81],s2[81],s[81],ss[81];
    int l1,l2,l,t,i,j,k,p,x1,x2;
    scanf("%d",&t);
    getchar();
    for(i=0;i<t;i++){
        gets(s1);
        gets(s2);
        gets(s);
        l1=strlen(s1);
        l2=strlen(s2);
        l=strlen(s);
        x1=-1;
        x2=-1;
        for(j=0;j<l-l1+1;j++){
            p=0;
            for(k=j;k<j+l1;k++){
                ss[p]=s[k];
                p++;
            }
            ss[l1]='\0';
            if(strcmp(ss,s1)==0){
                x1=j+l1-1;
                break;
            }
        }
        for(j=l-1;j>=l2-1;j--){
            p=l2-1;
            for(k=j;k>j-l1;k--){
                ss[p]=s[k];
                p--;
            }
            ss[l2]='\0';
            if(strcmp(ss,s2)==0){
                x2=j-l2+1;
                break;
            }
        }
        printf("case #%d:\n",i);
        if(x1==-1 || x2==-1 || x2<=x1)
            printf("0\n");
        else
            printf("%d\n",x2-x1-1);
    }
    return 0;
}
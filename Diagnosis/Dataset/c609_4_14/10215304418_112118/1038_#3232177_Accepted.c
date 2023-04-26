#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char st[1234][1234];

int cmp(const void* x1,const void* x2){
    char *st1=(char **)x1;
    char *st2=(char **)x2;
    return strcmp(st1,st2);
}

int main(){
    int t;
    char s[1234];
    scanf("%d",&t);
    gets(s);
    for (int l=1;l<=t;l++){
        gets(s);
        int i=0,j=0;
        for (int pos=0;pos<=strlen(s);pos++){
            if (s[pos]==' '||s[pos]==',' || s[pos]=='.' || s[pos]=='!' || s[pos]=='?'){
                if (j!=0) {
                    st[i][j]='\0';
                    j=0;
                    i++;
                }
            }
            else{
                st[i][j]=s[pos];
                j++;
            }
        }
        st[i][j]='\0';
        if (j==0) i--;
        qsort(st,i+1,sizeof(st[0]),cmp);
        printf("case #%d:\n",l-1);
        for (int k=1;k<i;k++)
            if (strcmp(st[k],st[k+1])!=0) printf("%s ",st[k]);
        printf("%s\n",st[i]);
    }
    return 0;
}

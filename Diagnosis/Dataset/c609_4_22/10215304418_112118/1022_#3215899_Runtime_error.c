#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char **st;


int cmp(const void *xx,const void *yy){
    char *x=*(char**)xx;
    char *y=*(char**)yy;
    int i=0;
    int j=0;
    while (x[i]!='@') i++;
    while (y[j]!='@') j++;
    while (x[i]!='\0' || y[j]!='\0'){
        if (x[i]=='\0') return -1;
        if (y[j]=='\0') return 1;
        if (x[i]!=y[j]) return x[i]-y[j];
        else {
            i++;
            j++;
        }
    }
    i=0;j=0;
    while (x[i]!='@' || y[j]!='@'){
        if (x[i]=='@') return 1;
        if (y[i]=='@') return -1;
        if (x[i]!=y[j]) return y[j]-x[i];
        else {
            i++;
            j++;
        }
    }
    return 0;
}

int main(){
    int n;
    scanf("%d",&n);
    st=(char**) malloc(sizeof(char*)*n);
    for (int i=0;i<n;i++){
        char *str=(char *) malloc(sizeof(char)*(1000000/n+2));
        scanf("%s",str);
        st[i]=(char*)malloc((strlen(str)+1)*sizeof(char));
        strcpy(st[i],str);
    }
    qsort(st,n,sizeof(char *),cmp);
    for (int i=0;i<n;i++)
        printf("%s\n",st[i]);
    return 0;
}

#include<stdio.h>
#include<malloc.h>
#include<string.h>
int finddiff(char *s,int len){
    char *m;
    m=s;
    int a[128],num=0;
    for(int i=0;i<128;i++)a[i]=0;
    for(int i=0;i<len;i++){
        if(a[*(m+i)]==0)num++,a[*(m+i)]=1;
    }
    return num;
}
int main(){
    int T,cas=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n,diff[100];
        char *s[101],c;
        scanf("%d",&n);
        c=getchar();
        for(int i=0;i<n;i++){
            char s1[21],*s2;
            int len;
            gets(s1);
            len=strlen(s1);
            s2=(char *)malloc((len+1)*sizeof(char));
            strcpy(s2,s1);
            diff[i]=finddiff(s2,len);
            *(s+i)=s2;
        }
        for(int i=0;i<n;i++){
            for(int m=i+1;m<n;m++){
                if (diff[i]==diff[m]){
                    if(strcmp(*(s+i),*(s+m))>0){
                        int q;
                        q=diff[i];
                        diff[i]=diff[m];
                        diff[m]=q;
                        char *u;
                        u=*(s+i);
                        *(s+i)=*(s+m);
                        *(s+m)=u;
                    }
                }
                else if(diff[i]<diff[m]){
                    int q;
                    q=diff[i];
                    diff[i]=diff[m];
                    diff[m]=q;
                    char *u;
                    u=*(s+i);
                    *(s+i)=*(s+m);
                    *(s+m)=u;
                }
            }

        }
        printf("case #%d:\n",cas++);
        for(int i=0;i<n;i++)printf("%s\n",*(s+i));

    }
    return 0;





}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,cnt;
    scanf("%d",&n);
    char a[102],aa[102];
    char alpa[]="ABC";
    for(int i=0;i<n;i++){
        scanf("%s",a);
        int slen=strlen(a);
        strcpy(aa,a);
        int len=slen+1;
        for(int m=0;m<3;m++){
            for(int c=0;c<slen;c++){
                    strcpy(a,aa);
                for(int d=slen-1;d>=c;d--){
                    a[d+1]=a[d]; }
                    a[c]=alpa[m];
                    a[slen+1]='\0';
                    while(strstr(a,"AA")||strstr(a,"CC")||strstr(a,"BB")){
                        cnt=0;
                        int sslen=strlen(a);
                        if(a[0]==a[1]){cnt++;}
                        for(int i=1;i<sslen-1;i++){
                            if(a[i]!=a[i-1]&&a[i]!=a[i+1])a[cnt++]=a[i];
                        }
                        if(a[sslen-2]!=a[sslen-1])a[cnt++]=a[sslen-1];
                        a[cnt]='\0';
                    }
                    if(cnt<len)len=cnt;


                }

    }
    printf("case #%d:\n%d\n",i,slen+1-len);
    }
    return 0;
}

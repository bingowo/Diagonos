#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n,m1,max,cnt,m,k=1;
    scanf("%d",&n);
    char *a[n];
    int b[n];
    for(int i=0;i<n;i++){

        scanf("%d",&m);
        m1=m;
        do{cnt++;}while(m>>=1);
        char t[cnt];
        int count=0;
        a[i]=(char*)malloc(sizeof(char)*(cnt+1));
        for(int j=0;j<cnt;j++)a[i][j]=(m1>>=1);
        a[i][cnt]='\0';
        t[count++]=a[i][0];t[1]='\0';
    for(int x=1;a[i][x]!='\0';x++){
        for(int j=0;t[j]!='\0';j++){
            if(t[j]==a[i][x]){
                k=0;
                cnt-=(j+1);
            };
        }
        if(k)max++;
        t[count++]=a[i][x];t[count]='\0';

    }
    t[count]='\0';
    if((count-1)>max)b[i]=count-1;
    else b[i]=max;


    }
    for(int j=0;j<n;j++){
        printf("case #%d:\n%d\n",j,b[j]);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()

{   int t,d[26],e[26],n;
    int p[25]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    char a[100],b[100];
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%s%s",a,b);
        memset(d,0,sizeof(d));
        memset(e,0,sizeof(e));
        int m=strlen(a)-1,lena=0,lenb=0,q=1;
        while (m>=0)
        {
            if (a[m]!=',')
            {d[25-lena]=d[25-lena]+(a[m]-'0')*q;q*=10;}
            else {lena++;q=1;}
            m--;
        }
        m=strlen(b)-1;
        q=1;
        while (m>=0)
        {
            if (b[m]!=',')
            {e[25-lenb]=e[25-lenb]+(b[m]-'0')*q;q*=10;}
            else {lenb++;q=1;}
            m--;
        }

        n=26;
        for (int j=25;j>0;j--){
            d[j]=d[j]+e[j];
            if (d[j]>=p[25-j]){
                d[j]=d[j]%p[25-j];
                d[j-1]=d[j-1]+1;
            }
            if (d[j]>0) n=j;
        }
        printf("case #%d:\n",i);
        for (int j=n;j<25;j++) printf("%d,",d[j]);
        printf("%d\n",d[25]);

    }

    return 0;
}

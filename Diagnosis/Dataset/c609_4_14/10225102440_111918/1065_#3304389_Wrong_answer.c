#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int t,i,j,m,n;
    scanf("%d",&t);
    getchar();
    for(i=0;i<t;i++){
        double a[50];
        char b[50],s[101];
        m=n=0;
        gets(s);
        for(j=0;j<strlen(s);j++){
            if(s[j]==' ') continue;
            if(s[j]=='+'||s[j]=='-'||s[j]=='*'||s[j]=='/'){
                b[n++]=s[j];
            }
            else{
                char c[50]={0};
                int num=0;
                while(s[j]!=' '&&s[j]!=0){
                    c[num++]=s[j++];
                }
                c[num]=0;
                if(m==1&&n>0){
                    double temp=atof(c);
                    n--,m--;
                    switch(b[n]){
                case '+':
                    a[m]=a[m]+temp;
                    break;
                case '-':
                    a[m]=a[m]-temp;
                    break;
                case '*':
                    a[m]=a[m]*temp;
                    break;
                case '/':
                    a[m]=a[m]/temp;
                    break;
                    }
                    m++;
                }
                else a[m++]=atof(c);
            }
        }
        while(m>0&&n>0){
            double temp=a[--m];
            n--,m--;
            switch(b[n]){
        case '+':
            a[m]=a[m]+temp;
            break;
        case '-':
            a[m]=a[m]-temp;
            break;
        case '*':
            a[m]=a[m]*temp;
            break;
        case '/':
            a[m]=a[m]/temp;
            break;
            }
            m++;
        }
        printf("case #%d:\n%.6lf\n",i,a[0]);
    }
    return 0;
}

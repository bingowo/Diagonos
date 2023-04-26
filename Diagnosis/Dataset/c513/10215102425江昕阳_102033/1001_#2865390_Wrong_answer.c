#include <stdio.h>
#include <stdlib.h>

int main()
{int n,*p,*p1,a,b,x,j=0;char s[100];
scanf("%d",&n);
p1=p=(int*)malloc(2*n*sizeof(int));
for(int i=0;i<2*n;i++){
    scanf("%d",p+i);
}
for(int i=0;i<n;i++){
    j=0;
    x=a=*p1;
    b=*(p1+1);
    do{j++;x=x/b;}while(x);
    s[j]='\0';
    do{if(a%b<10){j--;s[j]='0'+a%b;}
    else{j--;s[j]='A'+a%b-10;};
    a=a/b;
}while(a);
printf("%s",s);
p1=p1+2;
printf("\n");
};
free(p);
    return 0;
}

int main()
{
    int r,x,i,n=0,y,t;
    scanf("%d",&t);
    for(y=0;y!=t;y++){
        scanf("%d",&x);
        int k=0,b[100];
        b[0]=1;
        char a[33];
        do{
            r=x%2;
            a[k++]=r+'0';
            x=x/2;
        }while(x);
        a[k]='\0';
        for(i=0;i<strlen(a)-1;i++){
            if(a[i]!=a[i+1]){
                b[n]++;
            }
            else{
                n++;
                b[n]=1;
            }
        }
        int max=b[0];
        for(i=1;i<=n;i++){
            if(max<=b[i])
                max=b[i];
            b[i]=1;
        }
        if(max==0)max=1;
        printf("case #%d:\n%d",y,max);
        printf("\n");
    };
    return 0;
}

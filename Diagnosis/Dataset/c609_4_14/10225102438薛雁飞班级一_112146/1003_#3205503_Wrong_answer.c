int main()
{
    int x,r,i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        int k=0,a[33];
        scanf("%d",&x);
        do{
            r=x%2333;
            a[k++]=r;
            x=x/2333;
        }while(x);
        for(k=k-1;k!=-1;k--){
            printf("%d",a[k]);
            printf(" ");
        };
        printf("\n");
    };
    return 0;


}
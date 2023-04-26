double pow(double x,int y)
{
    double z;
    z=1;
    int i;
    for(i=0;i<y;i++)
    {
        z=z*x;
    }
    return z;
}
int main()
{
    int T,j,i,k,num;
    char s[100],b[100]={0},c[100]={0};
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%s",s);
        k=0;
        double sum=0;
        for(j=2;j<strlen(s);j++)
        {
            c[k]=s[j];
            k++;
        }
        for(k=0;k<strlen(c);k++)
        {
            sum=sum+(c[k]-48)*pow(0.125,k+1);
        }
        printf("%.30f\n",sum);
        printf("0.");
        for(j=0;j<3*strlen(c);j++)
        {
            sum=10*sum;
        }
        printf("%.0f\n",sum,sum);
    }
    return 0;
}

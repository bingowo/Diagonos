public class problem5 {
    public static void main(String []args){
        for(int i=0;i<12;i++)
        {
            double m=Math.pow(2,i);
            System.out.println(Math.log(m));
            System.out.println(m);
            System.out.println(m/Math.log(m));
            System.out.println(Math.pow(m,2));
            System.out.println(Math.pow(m,3));
        }
    }
}

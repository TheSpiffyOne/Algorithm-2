public class PowerCalculator {
    public static double power(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) return 1 / power(x, -n);
        return x * power(x, n - 1);
    }
    
    public static void main(String[] args) {
        System.out.println("2^5 = " + power(2, 5));
        System.out.println("3^-2 = " + power(3, -2));
    }
}

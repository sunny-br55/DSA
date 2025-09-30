import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        int[] p1 = new int[100];
        int[] p2 = new int[100];
        int maxdegree;

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the maximum degree of the polynomials: ");
        maxdegree = sc.nextInt();

        System.out.println("Enter coefficients for p1:");
        for (int i = 0; i <= maxdegree; i++) {
            p1[i] = sc.nextInt();
        }

        System.out.println("Enter coefficients for p2:");
        for (int i = 0; i <= maxdegree; i++) {
            p2[i] = sc.nextInt();
        }

        int[] result = add(p1, p2, maxdegree);

        System.out.println("Sum of polynomials:");
        display(result, maxdegree);
    }

    public static int[] add(int[] p1, int[] p2, int maxdegree) {
        int[] result = new int[100];
        for (int i = 0; i <= maxdegree; i++) {
            result[i] = p1[i] + p2[i];
        }
        return result;
    }

    static void display(int[] arr, int degree) {
        for (int i = degree; i >= 0; i--) {
            if (arr[i] != 0) {
                System.out.print(arr[i] + "x^" + i);
                if (i != 0) {
                    System.out.print(" + ");
                }
            }
        }
        System.out.println(); // Final newline
    }
}

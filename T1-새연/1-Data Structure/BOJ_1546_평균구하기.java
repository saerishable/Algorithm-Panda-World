import java.util.Scanner;

public class BOJ_1546_평균구하기 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int count = scanner.nextInt();
        int sum = 0;
        for (int i = 0; i < count; i++) {
            sum += scanner.nextInt();
        }
        System.out.println(sum / count);
    }
}

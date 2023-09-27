import java.util.Scanner;

public class Review {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 출력문 : 3가지 (println, printf, print)
        System.out.println("연휴 전날입니다ㅏㅏㅏ"); // "출력" + "\n"
        System.out.printf("이번해 추석은 %d월 %d일\n", 9, 29);
        System.out.print("연휴가ㅏ길다아ㅏㅏ"); // "출력"

        // 입력문 : Scanner 사용
        int i = scanner.nextInt();
        long l = scanner.nextLong();
        float f = scanner.nextFloat();
        double d = scanner.nextDouble();
        char c = scanner.next().charAt(0); // scan.next()로 입력받은 것 중, 0번째 문자만 뽑아와서 c에 저장한다
        String s1 = scanner.nextLine(); // "\n"(엔터 줄바꿈) 을 만나면 실행 종료
        String s2 = scanner.next();     // " "(공백) 을 만나면 실행 종료

        // 아스키 코드 : 컴퓨터가 문자 정보를 이해할 수 있도록
        //              특정 숫자와 문자를 1:1 대응 시킨 약속
        // A : 65       a : 97      '0' : 48    세개는 외워 둬라

        // String 관련 함수
        // 1. equals() : 2개의 문자열을 비교하는 함수
        //               (같으면 참 반환 다를시 거짓 반환)
        // 2. length() : 문자열 길이 반환
        //          " coffee " => length() 값: 6 , 인덱스 : 0~5번
        // 3. charAt(i) : String형에 대해서, 특정 위치 문자 접근할 때 사용
        //          " coffee " => "coffee".charAt(1); = o로 접근됌
        // 4. toCharArray() : String형 -> char[]형 변환 하는 함수
        //          String str = "SmartPhone";
        //          char ch[] = str.toCharArray(); 값이 전달만 되는 것이고 형이 변환 되지는 않는다

        // 배열 : 동일한 타입에 대해 여러 공간을 갖는 변수
        // 배열 선언 방법
        // 1. 초기화 하면서 선언
        // (자료형) (배열명)[] = (초기화해줄 값);
        int number[] = {11, 22, 33, 44, 55}; // 자동으로 크기가 5로 지정된다
        String st[] = {"Hello", "Java"};
        // 2차원 배열
        double dnum[][] = {{11.1, 12.2}, {21.1, 22.2, 32.2}};

        // 2. 크기만 할당 하며 선언
        // (자료형) (배열명)[] = new (자료형) [배열 크기];
        int n[] = new int[5];
        // 2차원 배열
        double dn[][] = new double [2][3]; // 2*3=6개의 원소 최대한 넣을수 있다

    }
}
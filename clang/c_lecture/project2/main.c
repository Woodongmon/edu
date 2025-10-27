#include <stdio.h>

int print_hello(void); // 내가 만든 함수의 이름을 가져오기
void print_hello(); // 함수의 원형 선언
/*원형 선언을 하지 않을시, 컴파일 오류
*
*
*
*
*/ 

int main()
{
    print_hello();
    print_hello() //void를 제외한, 데이터형을 가진 함수는 반환값을 요구 
    {
        printf("함수 호출\n");
        return 0;
    }

}
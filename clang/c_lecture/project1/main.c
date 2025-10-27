#include <stdio.h>

// /**
//  * @brief 연산자 연습
//  * 
//  * @return int 
//  */

// int main() 
// {
//     int a = 30; // 정수 a를 선언하고 초기값 입력
//     int b = 17; // 정수 b를 선언하고 초기값 입력
//     int result; // result를 선언.

//     result = a+b;
//     printf("a+b=%d입니다\n",result);
//     result = a-b;
//     printf("a-b=%d입니다\n",result);
//     result = a*b;
//     printf("a*b=%d입니다\n",result);
//     result = a/b;
//     printf("a/b=%d입니다\n",result);
//     result = a%b;
//     printf("a%%b=%d입니다\n",result);

// }

// /**
//  * @brief 대입, 복합연산자 연습
//  * @return int 
//  */
// int main()
// {
//     int a = 34;
//     int c;

//     c=a;
//     printf("c=a=%d \n",c); // c=a

//     c+=a;
//     printf("c+=a=%d \n",c); // c=c+a

//     c-=a;
//     printf("c-=a=%d \n",c);

//     c*=a;
//     printf("c*=a=%d \n",c);

//     c/=a;
//     printf("c/=a=%d \n",c);
// }


// /**
//  * @brief 관계연산자
//  * 
//  * @return int 
//  */
// int main()
// {
//     int a=0,b=0;
//     printf("두개의 정수를 입력하시오\n");
//     scanf("%d %d", &a, &b);
//     printf("%d > %d : %d \n",a,b,a>b); //a>b라는 명제가 참일시 1 반환
//     printf("%d < %d : %d \n",a,b,a<b);
//     printf("%d >= %d : %d \n",a,b,a>=b);
//     printf("%d <= %d : %d \n",a,b,a<=b);
//     printf("%d == %d : %d \n",a,b,a==b);
//     printf("%d != %d : %d \n",a,b,a!=b);



// }

// int main()
// {
//     int month;
//     printf("몇월??\n");
//     scanf("%d", &month);

//     if(month >= 6 && month <= 8)
//     {
//         printf("성수기 요금 적용\n");
//     }

//     if(month < 6 || month > 8)
//     {
//         printf("일반 요금 적용\n");
//     }
// }


/**
 * @brief bit연산자
 * 
 */

// int main()
// {
//     int n1=1; // 0000_0000 0000_0000 0000_0000 0000_1111
//     int n2=20; // 0000_0000 0000_0000 0000_0000 0001_0100
//     int result = n1 & n2; (n1 ^ n2)
//     printf("n1=%d\n",n1);
//     printf("n2=%d\n",n2);
//     printf("result=%d\n",result);



// }

/**
 * @brief shift 연산
 * 
 */
// int main()
// {
//     int n1=1;
//     int s1=n1<<1;''
//     int s2=n1<<1;

//     printf("s1=%d\n",s1)
//     printf("1=%d\n",s2)
// }
// int main()

// int main()
// {
//     int num=0;

//     printf("숫자를 입력하세요 \n");
//     scanf("%d", &num);
//     // if(num<5)
//     // {
//     //     printf("입력한 숫자가 5보다 작습니다 \n");        
//     // }
//     // if(num==5)
//     // {
//     //     printf("5를 입력 \n");
//     // }
//     // if(num>5)
//     // {
//     //     printf("입렵한 숫자가 5보다 큽니다 \n");
//     // }

    
//     if(num<5)
//     {
//         printf("5보다 작음");    
//     }
//     else if(num==5)
//     {
//         printf("5를 입력함");
//     }
//     else 
//     {
//         printf("5보다 큼");
//     }        
        
        
// }

// int main()
// {
//     int pm;
//     printf("미세먼지 농도 입력");
//     scanf("%d, &pm");
//     //중첩 if문 사용
//     if(pm>0)
//     {
//         if(pm<=30)
//         {
//             printf("미세먼지 농도 낮음\n");
//         }
//         else if(pm<=80)
//         {
//             printf("미세먼지 농도 보통\n");
//         }
//         else if(pm>80)
//         {
//             printf("미세먼지 농도 높음\n");
//         }
//     }
//     else
//     {
//         printf("0보다 높은 숫자를 입력해주세요");
//     }




// }

// int main()
// {
//     int num;
//     switch(num)
//     {
//         case 1:
//             printf("미세먼지 농도 낮음");
//             break;
//         case 2:
//             printf("미세먼지 농도 보통");
//             break;
//         case 3:
//             printf("미세먼지 농도 높음");
//             break;
//         case 4:
//             printf("미세먼지 농도 심각");
//             break;
//     }
// }

// /**
//  * @brief while을 사용한 조건문
//  * 
//  * @return int 
//  */
// int main()
// {
//     int weight=80;
//     int count=0;

//     while(weight>70)
//     {
//         printf("다이어트%d일차\n",count);
//         weight--;
//         count++;
//     }

//     printf("다이어트%d일차\n",count);
//     printf("다이어트 성공\n");
//     printf("%d일 소모됨\n",count);
// }

// int main()
// {
//     int weight = 80;
//     int count = 0;
//     int select;

//     do 
//     {
//         printf("다이어트%d일차, Continue? \n",count);
//         printf("Yes:1 , No:2 숫자를 입력하시오\n");    
//         scanf("%dm &select");

//         if(select==1)
//         printf("다이어트%d일차\n",count);
//         count++;    

//         else if(select==2)
//         printf("다이어트%d일차\n",count);
//         printf("다이어트 종료\n");
//         printf("돼지의 삶 시작\n");
//     }
//     while(weight>70);

//     printf("다이어트%d일차\n",count);
//     printf("다이어트 종료\n");
        


// }

// int main()
// {
//     int weight;
//     int count=0;

//     for (weight = 80; weight > 70; weight--)
//     {
//         count++;
//         printf("내부for문%d번째실행중\n",count);
//         printf("현재 weight값은 %d\n",weight);
        
//     }
//     printf("\n탈출조건인 weight값이 %d에 도달함\n",weight);
//     printf("그동안 %d번의 for문 반복 완료\n",count);
    

// }

// /**
//  * @brief 중첩 for문
//  * @return int 
//  */

// int main()
// {
//     int i,j;

//     for(i = 0; i < 5; i++)
//     {
//         for(j = 0; j <= i; j++)
//         {
//             printf("*");
//         }
//         printf("\n");
//     }

//     for(i = 5; i > 1; i--)
//     {
//         for(j = 1; j < i; j++)
//         {
//             printf("*");
//         }
//         printf("\n");
//     }

    

// }

/**
 * @brief 중첩 for문
 * @return int 
 */

int main()
{
    int i,j;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j <= i; j++)
        {
            printf("(i=%d ",i);
            printf("j=%d) ",j);
        }
        printf("\n");
    }

    for(i = 4; i >= 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            printf("(i=%d ",i);
            printf("j=%d) ",j);
        }
        printf("\n");
    }

    

}
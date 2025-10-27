/**
 * @brief 별그리기 함수
 * 
 * @return int 
 */

int main()
{
    int i,j;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for(i = 4; i >= 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    

}

/**
 * @brief i&j값 확인용 함수
 * 
 */
// int main()
// {
//     int i,j;

//     for(i = 0; i < 5; i++)
//     {
//         for(j = 0; j <= i; j++)
//         {
//             printf("(i=%d ",i);
//             printf("j=%d) ",j);
//         }
//         printf("\n");
//     }

//     for(i = 4; i >= 0; i--)
//     {
//         for(j = 0; j < i; j++)
//         {
//             printf("(i=%d ",i);
//             printf("j=%d) ",j);
//         }
//         printf("\n");
//     }

    

// }
#include <stdio.h>

int main(void)
{
    int i;
    int max_sum = 0;
    int current_sum = 0;
    int array[] = {-1, 2, 5, -6, 9};
    for(i=0;i < (sizeof(array) / sizeof(int)) ; ++i )
    {
        current_sum = current_sum + array[i];
        if(current_sum < 0)
            current_sum = 0;

        if(current_sum > max_sum)
            max_sum = current_sum;
    }

    printf("MAX CONT. SUM OF SUBARRAY :%d\n", max_sum);

    return 0;
}

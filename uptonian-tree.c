#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int
main()
{

    int test_cases,a;
    float cycles;
    scanf("%d",&test_cases);
    while(test_cases --){
        scanf("%g",&cycles);
        a = pow(2, ceil(cycles / 2) + 1);
        if((int)cycles % 2)
        {// if cycles are odd
            printf("%d\n", a - 2);
        }
        else
        {
            printf("%d\n",a - 1);
        }
    }
    return 0;
}

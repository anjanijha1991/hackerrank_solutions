#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main(void)
{
    int len, i = 0, test, mid;
    char* string = (char *) malloc(sizeof(char));
    int count;

    scanf("%d",&test);

    while(test --)
    {
        count = 0;
        scanf("%s", string);
        len = strlen(string);
        if(len % 2)
        {
            mid = (int) (len / 2) + 1;
            for(i = 0;i < mid; ++i )
            {
                count = count + abs(string[i] - string[len - i - 1]);
            }

        }
        else
        {
            mid = len / 2;
            for(i = 0;i < mid; ++i)
            {
                count = count + abs(string[i] - string[len - i - 1]);
            }
        }

        printf("%d\n",count);
    }

}

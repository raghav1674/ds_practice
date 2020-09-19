// Online C compiler to run C online.

#include <stdio.h>
void print(int n)
{

    if (n == 1)
        printf("%d ", 1);
    else
    {
        printf("%d ", 2 * n - 1);
        print(n - 1);
    }
}

int main()
{

    print(5);

    return 0;
}
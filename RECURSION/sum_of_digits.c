// Online C compiler to run C online.

#include <stdio.h>
int sum_digits(int n)
{

    if (n == 0)
        return 0;
    return (n % 10) + sum_digits(n / 10);
}

int main()
{

    printf("%d", sum_digits(12444444));

    return 0;
}
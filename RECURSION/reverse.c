#include <stdio.h>

void reverse(int n)
{

    if (n == 0)
    {
        return;
    }
    else
    {
        printf("%d", n % 10);
        return reverse(n / 10);
    }
}

int main()
{

    reverse(110099892);

    return 0;
}
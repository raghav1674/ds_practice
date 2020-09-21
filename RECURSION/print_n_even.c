#include <stdio.h>
void print(int n)
{

    if (n == 1)
    {
        printf("%d ", 2);
        return;
    }
    else
    {
        print(n - 1);
        printf("%d ", 2 * n);
    }
}

int main()
{

    print(5);

    return 0;
}

#include <stdio.h>
void toBinary(int n)
{

    if (n < 2)
    {

        printf("%d", n);

        return;
    }

    else
    {

        toBinary(n / 2);
        printf("%d", n % 2);
    }
}

int main()
{

    toBinary(4);

    return 0;
}

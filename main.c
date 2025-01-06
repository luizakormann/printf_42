#include "ft_printf.h"
#include <limits.h>

int main(void)
{
    int result;

    // Teste básico
    result = ft_printf("Hello, %s!\n", "world");
    ft_printf("Printed characters: %d\n", result);

    // Testando o caractere
    result = ft_printf("Character: %c\n", 'A');
    ft_printf("Printed characters: %d\n", result);

    // Testando números inteiros
    result = ft_printf("Integer: %d, Negative: %i\n", 42, -42);
    ft_printf("Printed characters: %d\n", result);

    // Testando números sem sinal
    result = ft_printf("Unsigned: %u\n", 1234567890u);
    ft_printf("Printed characters: %d\n", result);

    // Testando ponteiros
    void *ptr = &result;
    result = ft_printf("Pointer: %p\n", ptr);
    ft_printf("Printed characters: %d\n", result);

    // Testando hexadecimal (minúsculo e maiúsculo)
    result = ft_printf("Hexadecimal (lowercase): %x\n", 255);
    ft_printf("Printed characters: %d\n", result);
    result = ft_printf("Hexadecimal (uppercase): %X\n", 255);
    ft_printf("Printed characters: %d\n", result);

    // Testando casos de borda
    ft_printf("Edge cases:\n");
    ft_printf("Null pointer: %p\n", NULL);
    ft_printf("INT_MIN: %d\n", INT_MIN);
    ft_printf("INT_MAX: %d\n", INT_MAX);
    ft_printf("UINT_MAX: %u\n", UINT_MAX);
    ft_printf("LONG_MIN: %p\n", (void *)LONG_MIN);
    ft_printf("LONG_MAX: %p\n", (void *)LONG_MAX);

    // Testando %% (porcentagem)
    result = ft_printf("Print percentage: %%\n");
    ft_printf("Printed characters: %d\n", result);

    return 0;
}

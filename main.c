#include "include/ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ret1, ret2;

    printf("\n===== TESTE DE FT_PRINTF =====\n\n");

    // Teste de caracteres
    ret1 = ft_printf("Meu printf: Char -> %c\n", 'A');
    ret2 = printf("Printf real: Char -> %c\n", 'A');
    printf("Retorno: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Teste de strings
    ret1 = ft_printf("Meu printf: String -> %s\n", "Hello, 42!");
    ret2 = printf("Printf real: String -> %s\n", "Hello, 42!");
    printf("Retorno: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Teste de inteiros
    ret1 = ft_printf("Meu printf: Int -> %d\n", 42);
    ret2 = printf("Printf real: Int -> %d\n", 42);
    printf("Retorno: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Teste de unsigned int
	unsigned int num = 4294967295;
    ret1 = ft_printf("Meu printf: Unsigned Int -> %u\n", num);
    ret2 = printf("Printf real: Unsigned Int -> %u\n", num);
    printf("Retorno: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Teste de hexadecimal (minúsculo)
    ret1 = ft_printf("Meu printf: Hex (lower) -> %x\n", 255);
    ret2 = printf("Printf real: Hex (lower) -> %x\n", 255);
    printf("Retorno: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Teste de hexadecimal (maiúsculo)
    ret1 = ft_printf("Meu printf: Hex (upper) -> %X\n", 255);
    ret2 = printf("Printf real: Hex (upper) -> %X\n", 255);
    printf("Retorno: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Teste de ponteiro
    void *ptr = (void *)0x12345678;
    ret1 = ft_printf("Meu printf: Ponteiro -> %p\n", ptr);
    ret2 = printf("Printf real: Ponteiro -> %p\n", ptr);
    printf("Retorno: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Teste de porcentagem
    ret1 = ft_printf("Meu printf: Porcentagem -> %%\n");
    ret2 = printf("Printf real: Porcentagem -> %%\n");
    printf("Retorno: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    return 0;
}

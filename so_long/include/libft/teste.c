#include <unistd.h>

void ft_putchar (char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	long	nb_long;
	
	nb_long = nb;
	if (nb_long < 0)
	{
		ft_putchar('-');
		nb_long = -nb_long;
	}
	if (nb_long >= 10)
	{
		ft_putnbr(nb_long / 10);
	}
	ft_putchar(nb_long % 10 + '0');
	result = result  * 10 + str[i] - 48
}

int     main ()
{
        ft_putnbr(-123450236);
        return(0);
}
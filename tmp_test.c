#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "libft/libft.h"

int ft_printf(const char *format, ...);

void   test_all()
{
  ft_printf("%s\n", "Hello Printf");
  ft_printf("We need 100%% of %s\n", "use case");
  ft_printf("It's %s's %s (%s)\n", "iGor", "phone", "TEXT");
  ft_printf("[%10s] [%4s] [%8s] [%12s]\n", "THIS", "IS", "PADDED", "TEXT");
  ft_printf("%d\n", 42);
  ft_printf("%d %s\n", 42, "is the answer");
  ft_printf("%010d %s\n", 42, "was padded on 10");
  ft_printf("%10d %s\n", 42, "was also padded using spaces");
}

void  test_verif()
{
  printf("%s\n", "Hello Printf");
  printf("We need 100%% of %s\n", "use case");
  printf("It's %s's %s (%s)\n", "iGor", "phone", "TEXT");
  printf("[%10s] [%4s] [%8s] [%12s]\n", "THIS", "IS", "PADDED", "TEXT");
  printf("%d\n", 42);
  printf("%d %s\n", 42, "is the answer");
  printf("%010d %s\n", 42, "was padded on 10");
  printf("%10d %s\n", 42, "was also padded using spaces");
}

void  test_bonus()
{
  printf("Padding of %s: [%05d]\n", "five", -42);
  printf("Padding of %s: [%5d]\n", "five", -42);
  printf("Padding of %s: [%-5d]\n", "five", -42);
  
 ft_printf("Padding of %s: [%05d]\n", "five", -42);
 ft_printf("Padding of %s: [%5d]\n", "five", -42);
 ft_printf("Padding of %s: [%-5d]\n", "five", -42);
}

int  main(int argc, char *argv[])
{
  test_all();
  test_verif();
  test_bonus();
  return(0);
}

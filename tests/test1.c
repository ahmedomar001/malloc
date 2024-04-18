#include <stdlib.h>
#include <stdio.h>
#include "../src/helper.h"

int main()
{
  sprintf(buffer, "Running test 1 to test a simple malloc and free\n");
  write(STDOUT_FILENO, buffer, strlen(buffer));

  char * ptr = ( char * ) malloc ( 65535 );
  free( ptr ); 

  return 0;
}

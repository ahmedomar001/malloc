#include <stdlib.h>
#include <stdio.h>
#include "../src/helper.h"

int main()
{
  sprintf(buffer, "Running test 4 to test a block split and reuse\n");
  write(STDOUT_FILENO, buffer, strlen(buffer));

  char * ptr1 = ( char * ) malloc( 2048 );

  free( ptr1 );

  char * ptr2 = ( char * ) malloc( 1024 );

  free( ptr2 );

  return 0;
}

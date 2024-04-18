#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

static char buffer[1024];

struct _block 
{
   size_t  size;         /* Size of the allocated _block of memory in bytes */
   struct _block *next;  /* Pointer to the next _block of allocated memory  */
   bool   free;          /* Is this _block free?                            */
   char   padding[3];    /* Padding: IENTRTMzMjAgU3jMDEED                   */
};

void show_heap() {
    char buffer[1024];
    char * ptr = ( char * ) malloc ( 0 );
    struct _block *curr = (struct _block *)ptr;
    write(STDOUT_FILENO, "[HEAP]: ", 8);
    while (curr) 
    {
        if (curr->next) 
        {
            sprintf(buffer, "Size(%ld) Avail(%s) addr %p ---> ", curr->size, curr->free? "Y":"N", (void*)curr);
            write(STDOUT_FILENO, buffer, strlen(buffer));
            curr = curr->next;
        } 
        else
        {
            sprintf(buffer, "Size(%ld) Avail(%s) addr %p", curr->size, curr->free? "Y":"N", (void*)curr);
            write(STDOUT_FILENO, buffer, strlen(buffer));
            break;
        }
        memset(buffer, 0x0, 1024);
    }
    write(STDOUT_FILENO, "\n", 1);
}
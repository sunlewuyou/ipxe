#ifndef STDLIB_H
#define STDLIB_H

#include <stdint.h>
#include <assert.h>

/*****************************************************************************
 *
 * Numeric parsing
 *
 ****************************************************************************
 */

extern unsigned long strtoul ( const char *p, char **endp, int base );

/*****************************************************************************
 *
 * Memory allocation
 *
 ****************************************************************************
 */

extern void * malloc ( size_t size );
extern void * realloc ( void *old_ptr, size_t new_size );
extern void free ( void *ptr );
extern void * _calloc ( size_t len );

/**
 * Allocate cleared memory
 *
 * @v nmemb		Number of members
 * @v size		Size of each member
 * @ret ptr		Allocated memory
 *
 * Allocate memory as per malloc(), and zero it.
 *
 * This is implemented as a static inline, with the body of the
 * function in _calloc(), since in most cases @c nmemb will be 1 and
 * doing the multiply is just wasteful.
 */
static inline void * calloc ( size_t nmemb, size_t size ) {
	return _calloc ( nmemb * size );
}

/*****************************************************************************
 *
 * Random number generation
 *
 ****************************************************************************
 */

extern long int random ( void );
extern void srandom ( unsigned int seed );

static inline int rand ( void ) {
	return random();
}

static inline void srand ( unsigned int seed ) {
	srandom ( seed );
}

/*****************************************************************************
 *
 * Miscellaneous
 *
 ****************************************************************************
 */

extern int system ( const char *command );

#endif /* STDLIB_H */

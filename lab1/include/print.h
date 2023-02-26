#ifndef _print_h_
#define _print_h_

#include <stdarg.h>
#include <types.h>

typedef void (*fmt_callback_t)(void *, const char *, size_t);

/* -*-
 * output function takes:
 * The first argument in output function is a pointer to char buffer.
 * The second argument specifies the number of chars to outputed.
 *
 * output function cannot assume the buffer is null-terminated after
 * l number of chars.
 */
void vprintfmt(fmt_callback_t out, void *data, const char *fmt, va_list ap);

#endif

#include "darray.h"
#include <stdlib.h>
#include <string.h>

static int increase_mem(struct darray *d) {
  unsigned char *tmp;
  unsigned long old_cap;

  old_cap = d->cap;
  d->cap = d->cap * 13 / 10;
  tmp = realloc(d->ptr, d->cap);
  if (!tmp) {
    d->cap = old_cap;
    return -1;
  }
  d->ptr = tmp;
  return 0;
}

/* **************************************** */
/* Public */
/* **************************************** */

int danew(struct darray *d, unsigned long cap) {
  if (!d) return -1;
  d->len = 0;
  d->cap = cap;
  d->ptr = malloc(cap);
  if (!d->ptr) return -1;
  return 0;
}

void dafree(struct darray *d) {
  if (!d) return;
  free(d->ptr);
}

int dapush(struct darray *d, unsigned char byte) {
  if (!d) return -1;
  if (d->len == d->cap) {
    if (increase_mem(d)) return -1;
  }
  d->ptr[d->len++] = byte;
  return 0;
}

int dapushn(struct darray *d, unsigned long len, unsigned char *bytes) {
  if (!d) return -1;
  if (!bytes) return -1;
  if (d->len == d->cap) {
    if (increase_mem(d)) return -1;
  }
  memcpy(d->ptr, bytes, len);
  d->len += len;
  return 0;
}

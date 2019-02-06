#ifndef DARRAY_H
#define DARRAY_H

struct darray {
  unsigned long len;
  unsigned long cap;
  unsigned char *ptr;
};

int danew(struct darray *d, unsigned long cap);
void dafree(struct darray *d);
int dapush(struct darray *d, unsigned char byte);
int dapushn(struct darray *d, unsigned long len, unsigned char *byte);

#endif

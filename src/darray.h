#ifndef DARRAY_H
#define DARRAY_H

struct darray;

struct darray *danew(unsigned long cap);
void dafree(struct darray *d);
unsigned char *dapeel(struct darray *d);
int dapush(struct darray *d, unsigned char byte);
int dapushn(struct darray *d, unsigned long len, unsigned char *byte);
unsigned long dalen(struct darray *d);
unsigned char *daptr(struct darray *d);

#endif

#ifndef DYNVEC_H
#define DYNVEC_H

typedef struct dynvec DynVec;

DynVec* dv_create();

void dv_append(DynVec* dv, int valor);

int dv_size(const DynVec* dv);

int dv_get(const DynVec* dv, int indice);

int dv_is_in(const DynVec* dv, int valor);

DynVec* dv_concatenate(const DynVec* dv1, const DynVec* dv2);

DynVec* dv_union(const DynVec* dv1, const DynVec* dv2);

DynVec* dv_intersection(const DynVec* dv1, const DynVec* dv2);

void dv_free(DynVec* dv);

void dv_print(const DynVec* dv);

#endif

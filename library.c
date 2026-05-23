#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//functions for matrix manipulation
matrix mat_create(int rows, int cols) {
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = malloc(rows * cols * sizeof(float));
    return m;
}

void mat_free(matrix *m) {
    free(m->data);
    m->data = NULL;
    m->rows = 0;
    m->cols = 0;
}

void mat_fill(matrix *m, float value) {
    for (int i = 0; i < m->rows * m->cols; i++) {
        m->data[i] = value;
    }
}

void mat_copy(const matrix *src, matrix *dst) {
    for (int i = 0; i < src->rows * src->cols; i++) {
        dst->data[i] = src->data[i];
    }
}

void mat_randn(matrix *m) {
    
}

void mat_print(const matrix *m) {

}

//core operation functions
void mat_mul(const matrix *a, const matrix *b, matrix *out) {

}

void mat_add(const matrix *a, const matrix *b, matrix *out) {

}

void mat_scale(const matrix *a, float s, matrix *out) {

}

void mat_transpose(const matrix *a, matrix *out) {

}

matrix mat_softmax(const matrix *a) {

}

void mat_relu(const matrix *a, matrix *out) {

}
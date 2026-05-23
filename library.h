#ifndef MATRIXLIB_LIBRARY_H
#define MATRIXLIB_LIBRARY_H

typedef struct _matrix {
    int rows;
    int cols;
    float *data;
} matrix;

//functions for matrix manipulation
matrix mat_create(int rows, int cols);
void mat_free(matrix *m);
void mat_fill(matrix *m, float value);
void mat_copy(const matrix *src, matrix *dst);
void mat_randn(matrix *m);
void mat_print(const matrix *m);

//core operation functions
void mat_mul(const matrix *a, const matrix *b, matrix *out);
void mat_add(const matrix *a, const matrix *b, matrix *out);
void mat_scale(const matrix *a, float s, matrix *out);
void mat_transpose(const matrix *a, matrix *out);
matrix mat_softmax(const matrix *a);
void mat_relu(const matrix *a, matrix *out);

#endif // MATRIXLIB_LIBRARY_H

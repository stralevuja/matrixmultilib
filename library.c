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

void mat_randn(matrix *m, float std) {
    //box-muller
    for (int i = 0; i < m->rows * m->cols; i++) {
        float u1 = ((float)rand() + 1.0f) / ((float)RAND_MAX + 2.0f);  // strictly (0, 1]
        float u2 = (float)rand() / RAND_MAX;
        m->data[i] = sqrt(-2.0f * log(u1)) * cos(2.0f * M_PI * u2);
    }
}

void mat_print(const matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%.2f ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}

//core operation functions
void mat_mul(const matrix *a, const matrix *b, matrix *out) {
    if (a->cols != b->rows) {
        fprintf(stderr, "Error: Incompatible matrix dimensions for multiplication\n");
        return;
    }
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            float sum = 0.0f;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            out->data[i * out->cols + j] = sum;
        }
    }
}

void mat_add(const matrix *a, const matrix *b, matrix *out) {
    if (a->rows != b->rows || a->cols != b->cols) {
        fprintf(stderr, "Error: Incompatible matrix dimensions for addition\n");
        return;
    }
    for (int i = 0; i < a->rows * a->cols; i++) {
        out->data[i] = a->data[i] + b->data[i];
    }
}

void mat_scale(const matrix *a, float s, matrix *out) {
    for (int i = 0; i < a->rows * a->cols; i++) {
        out->data[i] = a->data[i] * s;
    }
}

void mat_transpose(const matrix *a, matrix *out) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            out->data[j * out->cols + i] = a->data[i * a->cols + j];
        }
    }
}

void mat_softmax(matrix *a) {
    for (int i = 0; i < a->rows; i++) {
        float max_val = a->data[i * a->cols];
        for (int j = 1; j < a->cols; j++) {
            if (a->data[i * a->cols + j] > max_val)
                max_val = a->data[i * a->cols + j];
        }
        float sum_exp = 0.0f;
        for (int j = 0; j < a->cols; j++) {
            a->data[i * a->cols + j] = expf(a->data[i * a->cols + j] - max_val);
            sum_exp += a->data[i * a->cols + j];
        }
        for (int j = 0; j < a->cols; j++) {
            a->data[i * a->cols + j] /= sum_exp;
        }
    }
}

void mat_relu(const matrix *a, matrix *out) {
    for (int i = 0; i < a->rows * a->cols; i++) {
        out->data[i] = fmax(0.0f, a->data[i]);
    }
}
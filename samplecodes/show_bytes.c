#include <stdio.h>
// 无法打开源文件 stdio.h 

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) 
        printf("%.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}


/* 
2.5 思考下面对 show_bytes 的三次调用：

int val = 0x87654321;
byte_pointer valp = (byte_pointer) &val;

show_bytes(valp, 1); // A: 小端法-最低有效字节 21，大端法-最高有效字节 87
show_bytes(valp, 2); // B: 4321， 8765
show_bytes(valp, 3); // C: 654321, 876543

2.6 整数 3510593 的十六进制表示为 0x00359141，而浮点数 3510593.0 的十六进制表示为 0x4A564504

A. 两个十六进制的二进制表示。
(0x00359141 - 0000 0000 0011 0101 1001 0001 0010 0001)
(0x4A564504 - 0100 1010 0101 0110 0100 0101 0000 0100)
 */
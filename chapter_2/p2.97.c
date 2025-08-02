#include <stdio.h>
#include "util.h"

/*
 * Converts a 32-bit signed integer to its IEEE 754 single-precision float representation.
 */
float_bits float_i2f(int i) {
    // 特殊情况：0
    if (i == 0) {
        return 0;
    }

    // 步骤 1: 提取符号位并计算绝对值
    unsigned sign = (i >> 31) & 1;
    unsigned abs_i;
    if (i == 0x80000000) { // INT_MIN 的特殊情况
        abs_i = 0x80000000;
    } else {
        abs_i = (i < 0) ? -i : i;
    }

    // 步骤 2: 找到最高有效位 (MSB) 的位置
    // 这将帮助我们确定指数 E
    int msb_pos = 0;
    unsigned temp = abs_i;
    while (temp >>= 1) {
        msb_pos++;
    }

    // 步骤 3: 计算指数 (exp)
    // E = msb_pos, exp = E + bias = msb_pos + 127
    unsigned exp = msb_pos + 127;

    // 步骤 4: 计算尾数 (frac)
    // 我们需要将 abs_i 规范化，使其形式为 1.xxxxx...
    // 首先，移除隐含的最高位 '1'
    unsigned frac = abs_i & ~(1 << msb_pos);

    // 然后，根据 msb_pos 的位置对齐尾数
    if (msb_pos > 23) {
        // 如果整数的位数超过23位，我们需要右移并进行舍入
        int shift = msb_pos - 23;
        unsigned round_part = frac & ((1 << shift) - 1); // 被移掉的部分
        unsigned half = 1 << (shift - 1); // 舍入的中点

        frac >>= shift;

        // 舍入决策：向最近偶数舍入 (Round-to-nearest-even)
        if (round_part > half) {
            frac++;
        } else if (round_part == half) {
            // 如果恰好在中间，当且仅当 frac 的最低位是1时才进位
            if ((frac & 1) == 1) {
                frac++;
            }
        }
    } else {
        // 如果整数的位数小于等于23位，我们左移来填充尾数
        frac <<= (23 - msb_pos);
    }

    // 检查舍入后是否导致尾数溢出 (例如 0.111... 舍入后变成 1.000...)
    if (frac >= 0x800000) {
        frac = 0; // 尾数归零
        exp++;    // 指数加一
    }

    // 步骤 5: 组合最终结果
    return (sign << 31) | (exp << 23) | (frac & 0x7FFFFF);
}

int main() {
    int tests[] = {0, 1, -1, 10, -10, 12345, -12345, 0x7FFFFFFF, 0x80000000};
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; ++i) {
        int input = tests[i];
        float_bits fb = float_i2f(input);
        float f = fb2float(fb);
        printf("Input: %d (0x%X) -> Float: %f (Bits: 0x%X)\n", input, (unsigned)input, f, fb);
    }

    // 测试舍入
    int round_test = 0x01FFFFFE; // 一个需要向偶数舍入的例子
    printf("\nRounding test:\n");
    printf("Input: %d (0x%X) -> Float: %f (Bits: 0x%X)\n", round_test, (unsigned)round_test, fb2float(float_i2f(round_test)), float_i2f(round_test));

    return 0;
}
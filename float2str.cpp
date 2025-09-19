/*#include <iostream>
#include <string.h>
using namespace std;
// 把 double 类型数值转换为字符串
void double_to_string(double num, char* str) {
    // 使用 snprintf 函数把 double 转换为字符串
    snprintf(str, 256, "%f", num);
    // 去掉字符串末尾多余的零
    int len = strlen(str);
    while (len > 0 && str[len - 1] == '0') {
        str[len - 1] = '\0';
        len--;
    }
    // 如果小数点后没有数字，去掉小数点
    if (str[len - 1] == '.') {
        str[len - 1] = '\0';
    }
}

#include <stdio.h>

int main() {
    double num = 3.14;
    cin >> num;
    char str[256];
    double_to_string(num, str);
    printf("转换后的字符串: %s\n", str);
    return 0;
}
*/
#include <stdio.h>

// 方法一：使用 union
union FloatConverter {
    unsigned char bytes[4];
    float f;
};

float bytesToFloatUsingUnion(unsigned char bytes[4]) {
    union FloatConverter converter;
    converter.bytes[0] = bytes[3];
    converter.bytes[1] = bytes[2];
    converter.bytes[2] = bytes[1];
    converter.bytes[3] = bytes[0];
    return converter.f;
}

// 方法二：使用指针强制类型转换
float bytesToFloatUsingPointer(unsigned char bytes[4]) {
    unsigned char swapped[4];
    swapped[0] = bytes[3];
    swapped[1] = bytes[2];
    swapped[2] = bytes[1];
    swapped[3] = bytes[0];
    float* fPtr = (float*)swapped;
    return *fPtr;
}

int main() {
    unsigned char bytes[4] = { 0x40, 0x48, 0xF5, 0xC3 };
    float result1 = bytesToFloatUsingUnion(bytes);
    float result2 = bytesToFloatUsingPointer(bytes);
    printf("使用 union 转换后的浮点数: %f\n", result1);
    printf("使用指针强制类型转换后的浮点数: %f\n", result2);
    return 0;
}
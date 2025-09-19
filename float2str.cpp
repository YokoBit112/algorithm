/*#include <iostream>
#include <string.h>
using namespace std;
// �� double ������ֵת��Ϊ�ַ���
void double_to_string(double num, char* str) {
    // ʹ�� snprintf ������ double ת��Ϊ�ַ���
    snprintf(str, 256, "%f", num);
    // ȥ���ַ���ĩβ�������
    int len = strlen(str);
    while (len > 0 && str[len - 1] == '0') {
        str[len - 1] = '\0';
        len--;
    }
    // ���С�����û�����֣�ȥ��С����
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
    printf("ת������ַ���: %s\n", str);
    return 0;
}
*/
#include <stdio.h>

// ����һ��ʹ�� union
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

// ��������ʹ��ָ��ǿ������ת��
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
    printf("ʹ�� union ת����ĸ�����: %f\n", result1);
    printf("ʹ��ָ��ǿ������ת����ĸ�����: %f\n", result2);
    return 0;
}
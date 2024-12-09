#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user.h"

// ������ ������ ���� �� �Լ�
int compare(const void* a, const void* b) {
    user* user1 = (user*)a;
    user* user2 = (user*)b;

    // �г����� �������� ��
    int name_cmp = strcmp(user1->name, user2->name);
    if (name_cmp != 0) {
        return name_cmp;
    }

    // �г����� ������ ������ �������� ��
    return user1->level - user2->level;
}

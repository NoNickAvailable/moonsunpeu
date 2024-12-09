#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user.h"

// 사전순 정렬을 위한 비교 함수
int compare(const void* a, const void* b) {
    user* user1 = (user*)a;
    user* user2 = (user*)b;

    // 닉네임을 기준으로 비교
    int name_cmp = strcmp(user1->name, user2->name);
    if (name_cmp != 0) {
        return name_cmp;
    }

    // 닉네임이 같으면 레벨을 기준으로 비교
    return user1->level - user2->level;
}

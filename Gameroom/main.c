#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user.h"

int main() {
    int p, m;
    scanf("%d %d", &p, &m);

    // 사용자 정보 저장
    user* list = (user*)malloc(p * sizeof(user));
    int room[301][301] = { 0 };
    int idx[301] = { 0 };

    // 사용자 정보 입력
    for (int i = 0; i < p; i++) {
        scanf("%d %s", &list[i].level, list[i].name);
    }

    // 사용자 정보 정렬
    qsort(list, p, sizeof(user), compare);

    // 방에 사용자 배정
    int roomnum = assign_to_room(list, p, room, idx, m);

    // 방 출력
    print_rooms(room, idx, list, roomnum, p);

    free(list); // 동적 메모리 해제
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user.h"

int main() {
    int p, m;
    scanf("%d %d", &p, &m);

    // ����� ���� ����
    user* list = (user*)malloc(p * sizeof(user));
    int room[301][301] = { 0 };
    int idx[301] = { 0 };

    // ����� ���� �Է�
    for (int i = 0; i < p; i++) {
        scanf("%d %s", &list[i].level, list[i].name);
    }

    // ����� ���� ����
    qsort(list, p, sizeof(user), compare);

    // �濡 ����� ����
    int roomnum = assign_to_room(list, p, room, idx, m);

    // �� ���
    print_rooms(room, idx, list, roomnum, p);

    free(list); // ���� �޸� ����
    return 0;
}

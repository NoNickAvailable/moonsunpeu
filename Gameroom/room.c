#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user.h"

// �濡 �÷��̾ �����ϴ� �Լ�
int assign_to_room(user* list, int p, int room[301][301], int idx[301], int m) {
    int roomnum = 0;

    for (int i = 0; i < p; i++) {
        int chk = 0;

        // ���� �濡 ������ �� �ִ��� Ȯ��
        for (int j = 0; j < roomnum; j++) {
            if (idx[j] < m && room[j][0] >= list[i].level - 10 && room[j][0] <= list[i].level + 10) {
                room[j][idx[j]++] = list[i].level;
                chk = 1;
                break;
            }
        }

        // ������ �� ������ ���ο� �� ����
        if (!chk) {
            room[roomnum][0] = list[i].level;
            idx[roomnum] = 1;
            roomnum++;
        }
    }

    return roomnum;
}

// ���� ���¿� �÷��̾���� ����ϴ� �Լ�
void print_rooms(int room[301][301], int idx[301], user* list, int roomnum, int p) {
    for (int i = 0; i < roomnum; i++) {
        if (idx[i] == 2) {
            printf("Started!\n");
        }
        else {
            printf("Waiting!\n");
        }

        // �濡 ���� �÷��̾�� ��� (���������� ����)
        int room_size = idx[i];

        // �������� room_players �迭�� �Ҵ�
        user* room_players = (user*)malloc(room_size * sizeof(user));

        // �濡 ���� �÷��̾���� �����ͼ� ����
        for (int j = 0; j < room_size; j++) {
            room_players[j].level = room[i][j];
            for (int k = 0; k < p; k++) {
                if (list[k].level == room_players[j].level) {
                    strcpy(room_players[j].name, list[k].name);
                    list[k].level = -1;  // ���߿� �ߺ��� ���ϱ� ���� ����� ������ ����
                    break;
                }
            }
        }

        // ���������� ����
        qsort(room_players, room_size, sizeof(user), compare);

        // �÷��̾� ���
        for (int j = 0; j < room_size; j++) {
            printf("%d %s\n", room_players[j].level, room_players[j].name);
        }

        // ���� �޸� ����
        free(room_players);
    }
}

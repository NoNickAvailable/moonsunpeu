#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user.h"

// 방에 플레이어를 배정하는 함수
int assign_to_room(user* list, int p, int room[301][301], int idx[301], int m) {
    int roomnum = 0;

    for (int i = 0; i < p; i++) {
        int chk = 0;

        // 기존 방에 배정할 수 있는지 확인
        for (int j = 0; j < roomnum; j++) {
            if (idx[j] < m && room[j][0] >= list[i].level - 10 && room[j][0] <= list[i].level + 10) {
                room[j][idx[j]++] = list[i].level;
                chk = 1;
                break;
            }
        }

        // 배정할 수 없으면 새로운 방 생성
        if (!chk) {
            room[roomnum][0] = list[i].level;
            idx[roomnum] = 1;
            roomnum++;
        }
    }

    return roomnum;
}

// 방의 상태와 플레이어들을 출력하는 함수
void print_rooms(int room[301][301], int idx[301], user* list, int roomnum, int p) {
    for (int i = 0; i < roomnum; i++) {
        if (idx[i] == 2) {
            printf("Started!\n");
        }
        else {
            printf("Waiting!\n");
        }

        // 방에 속한 플레이어들 출력 (사전순으로 정렬)
        int room_size = idx[i];

        // 동적으로 room_players 배열을 할당
        user* room_players = (user*)malloc(room_size * sizeof(user));

        // 방에 속한 플레이어들을 가져와서 정렬
        for (int j = 0; j < room_size; j++) {
            room_players[j].level = room[i][j];
            for (int k = 0; k < p; k++) {
                if (list[k].level == room_players[j].level) {
                    strcpy(room_players[j].name, list[k].name);
                    list[k].level = -1;  // 나중에 중복을 피하기 위해 사용한 레벨을 제거
                    break;
                }
            }
        }

        // 사전순으로 정렬
        qsort(room_players, room_size, sizeof(user), compare);

        // 플레이어 출력
        for (int j = 0; j < room_size; j++) {
            printf("%d %s\n", room_players[j].level, room_players[j].name);
        }

        // 동적 메모리 해제
        free(room_players);
    }
}

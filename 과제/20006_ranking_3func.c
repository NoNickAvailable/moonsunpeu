#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct user {
    int level;
    char name[16];
} user;
int compare(const void *a, const void *b) {
    user *user1 = (user *)a;
    user *user2 = (user *)b;
    int name_cmp = strcmp(user1->name, user2->name);
    if (name_cmp != 0) {
        return name_cmp;
    }
    
    return user1->level - user2->level;
}
int assign_to_room(user* list, int p, int room[301][301], int idx[301], int m) {
    int roomnum = 0;

    for (int i = 0; i < p; i++) {
        int chk = 0;
        for (int j = 0; j < roomnum; j++) {
            if (idx[j] < m && room[j][0] >= list[i].level - 10 && room[j][0] <= list[i].level + 10) {
                room[j][idx[j]++] = list[i].level;
                chk = 1;
                break;
            }
        }
        if (!chk) {
            room[roomnum][0] = list[i].level;
            idx[roomnum] = 1;
            roomnum++;
        }
    }

    return roomnum;
}
void print_rooms(int room[301][301], int idx[301], user* list, int roomnum, int p) {
    for (int i = 0; i < roomnum; i++) {
        if (idx[i] == 2) {
            printf("Started!\n");
        } else {
            printf("Waiting!\n");
        }
        int room_size = idx[i];
        user room_players[room_size];
        for (int j = 0; j < room_size; j++) {
            room_players[j].level = room[i][j];
            for (int k = 0; k < p; k++) {
                if (list[k].level == room_players[j].level) {
                    strcpy(room_players[j].name, list[k].name);
                    list[k].level = -1;
                    break;
                }
            }
        }
        qsort(room_players, room_size, sizeof(user), compare);
        for (int j = 0; j < room_size; j++) {
            printf("%d %s\n", room_players[j].level, room_players[j].name);
        }
    }
}
int main() {
    int p, m;
    scanf("%d %d", &p, &m);
    user *list = (user *)malloc(sizeof(user) * p);
    for (int i = 0; i < p; i++) {
        scanf("%d %s", &list[i].level, list[i].name);
    }
    qsort(list, p, sizeof(user), compare);
    int room[301][301] = {0};
    int idx[301] = {0};
    int roomnum = assign_to_room(list, p, room, idx, m);
    print_rooms(room, idx, list, roomnum, p);

    free(list);
    return 0;
}


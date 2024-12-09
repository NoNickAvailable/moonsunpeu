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

int main() {
    int p, m;
    scanf("%d %d", &p, &m);

    user *list = (user *)malloc(sizeof(user) * p);
    for (int i = 0; i < p; i++) {
        scanf("%d %s", &list[i].level, list[i].name);
    }
    int roomnum = 0;
    int room[301][301];
    int idx[301] = {0}; 
    for (int i = 0; i < p; i++) {
        int chk = 0;
        for (int j = 0; j < roomnum; j++) {
            if (idx[j] < m && 
                room[j][0] >= list[i].level - 10 && room[j][0] <= list[i].level + 10) {
                room[j][idx[j]++] = list[i].level;
                chk = 1;
                break;
            }
        }
        if (!chk) {
            room[roomnum][0] = list[i].level;
            roomnum++;
            idx[roomnum - 1] = 1;
        }
    }
    for (int i = 0; i < roomnum; i++) {
        if (idx[i] == m) {
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
    free(list);
    return 0;
}

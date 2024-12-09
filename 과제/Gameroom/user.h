#ifndef USER_H
#define USER_H

typedef struct user {
    int level;
    char name[16];
} user;

int compare(const void* a, const void* b);
int assign_to_room(user* list, int p, int room[301][301], int idx[301], int m);
void print_rooms(int room[301][301], int idx[301], user* list, int roomnum, int p);

#endif

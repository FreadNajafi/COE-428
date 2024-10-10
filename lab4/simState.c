#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    int i, b=0;
    char com[4];

    typedef struct state_machine {
        char name;
        struct state_machine *next_0;
        struct state_machine *next_1;
        bool deleted;
    } state_machine;

    state_machine state[8];
    state_machine *begin = (&state[1]);

    state[0].name = 'A';
    state[0].next_0 = &state[2];
    state[0].next_1 = &state[1];
    state[0].deleted = false;

    state[1].name = 'B';
    state[1].next_0 = &state[7];
    state[1].next_1 = &state[6];
    state[1].deleted = false;

    state[2].name = 'C';
    state[2].next_0 = &state[5];
    state[2].next_1 = &state[4];
    state[2].deleted = false;

    state[3].name = 'D';
    state[3].next_0 = &state[0];
    state[3].next_1 = &state[1];
    state[3].deleted = false;

    state[4].name = 'E';
    state[4].next_0 = &state[6];
    state[4].next_1 = &state[2];
    state[4].deleted = false;

    state[5].name = 'F';
    state[5].next_0 = &state[3];
    state[5].next_1 = &state[5];
    state[5].deleted = false;

    state[6].name = 'G';
    state[6].next_0 = &state[7];
    state[6].next_1 = &state[5];
    state[6].deleted = false;

    state[7].name = 'H';
    state[7].next_0 = &state[4];
    state[7].next_1 = &state[0];
    state[7].deleted = false;

    state_machine *current = &state[1];
    fprintf(stdout, "start:%c\n", begin->name);
    printf("Insert command; the change command should be typed as c0A, not c 0 A\n");

    void printStates() {
        for (i = 0; i < 8; i++) {
            if (!state[i].deleted) {
                fprintf(stdout, "%c %c %c \n", state[i].name, state[i].next_0->name, state[i].next_1->name);
            }
        }
    }

    void garbageCollecting() {
        int reachable[8] = {0};
        void markReachableStates(state_machine *currentState) {
            if (reachable[currentState->name - 'A'] == 0) {
                reachable[currentState->name - 'A'] = 1;
                markReachableStates(currentState->next_0);
                markReachableStates(currentState->next_1);
            }
        }
        markReachableStates(current);

        bool allReachable = true;
        for (i = 0; i < 8; i++) {
            if (reachable[i] == 0 && !state[i].deleted) {
allReachable = false;
}
}
if (allReachable) {
        printf("No garbage\n");
    } else {
        printf("Garbage: ");
        for (i = 0; i < 8; i++) {
            if (reachable[i] == 0 && !state[i].deleted) {
                printf("%c ", state[i].name);
            }
        }
        printf("\n");
    }
}

void deleteStates(char stateName) {
    int reachable[8] = {0};
    void markReachableStates(state_machine *currentState) {
        if (reachable[currentState->name - 'A'] == 0) {
            reachable[currentState->name - 'A'] = 1;
            markReachableStates(currentState->next_0);
            markReachableStates(currentState->next_1);
        }
    }
    markReachableStates(current);

    if (stateName == '\0') {
        bool anyDeleted = false;
        for (i = 0; i < 8; i++) {
            if (reachable[i] == 0 && !state[i].deleted) {
                state[i].deleted = true;
                anyDeleted = true;
                printf("%c ", state[i].name);
            }
        }
        if (anyDeleted) {
            printf("Deleted: ");
            for (i = 0; i < 8; i++) {
                if (state[i].deleted) {
                    printf("%c ", state[i].name);
                }
            }
            printf("\n");
        } else {
            printf("No states deleted.\n");
        }
    } else {
        int idx = stateName - 'A';
        if (reachable[idx] == 0 && !state[idx].deleted) {
            state[idx].deleted = true;
            printf("Deleted.\n");
        } else {
            printf("Not deleted.\n");
        }
    }
}

while (b != 1) {
    //input
    for (i = 0; i < 3; i++) {
        scanf("%c", &com[i]);
        if (com[i] == '\n') {
            break;
        }
    }
    //exit
    if (com[0] == 'x' || com[0] == 'X') {
        b = 1;
    }

    if (com[0] == 'p') {
        printStates();
    }

    if (com[0] == 'g') {
        garbageCollecting();
    }

    if (com[0] == 'd') {
        if (com[1] == '\n') {
            deleteStates('\0');
        } else {
            deleteStates(com[1]);
        }
    }

    if (com[0] == '0') {
        fprintf(stdout, "%c \n", current->next_0->name);
        current = (current->next_0);
    }

    if (com[0] == '1') {
        fprintf(stdout, "%c \n", current->next_1->name);
        current = (current->next_1);
    }

    // implement the change command for next_0 and next_1
    if (com[0] == 'c' && com[1] == '0') {
    if (com[2] == 'A') {
        (current->next_0) = &state[0];
    } else if (com[2] == 'B') {
        (current->next_0) = &state[1];
    } else if (com[2] == 'C') {
        (current->next_0) = &state[2];
    } else if (com[2] == 'D') {
        (current->next_0) = &state[3];
    } else if (com[2] == 'E') {
        (current->next_0) = &state[4];
    } else if (com[2] == 'F') {
        (current->next_0) = &state[5];
    } else if (com[2] == 'G') {
        (current->next_0) = &state[6];
    } else if (com[2] == 'H') {
        (current->next_0) = &state[7];
    }
}
if (com[0] == 'c' && com[1] == '1') {
    if (com[2] == 'A') {
        (current->next_1) = &state[0];
    } else if (com[2] == 'B') {
        (current->next_1) = &state[1];
    } else if (com[2] == 'C') {
        (current->next_1) = &state[2];
    } else if (com[2] == 'D') {
        (current->next_1) = &state[3];
    } else if (com[2] == 'E') {
        (current->next_1) = &state[4];
    } else if (com[2] == 'F') {
        (current->next_1) = &state[5];
    } else if (com[2] == 'G') {
        (current->next_1) = &state[6];
    } else if (com[2] == 'H') {
        (current->next_1) = &state[7];
    }
}
}
exit(0);
} 

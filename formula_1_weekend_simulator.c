#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
struct Driver {
    char name[50];
    int position;
    int points;
};

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int numDrivers,S;
    char grandprix[100];
    printf("\n=== FORMULA 1 WEEKEND SIMULATOR ===\n");
    printf("Enter the number of Weekends(Race):");
    scanf("%d",&S);
    while(S--) {
    printf("Enter the Grand Prix name: ");
    fgets(grandprix, sizeof(grandprix), stdin);
    grandprix[strcspn(grandprix, "\n")] = '\0'; 

    printf("\nEnter number of drivers: ");
    scanf("%d", &numDrivers);
    clear_input_buffer();

    struct Driver *drivers = (struct Driver *)malloc(numDrivers * sizeof(struct Driver));
    if (drivers == NULL) {
        printf("\n!!!!!ERROR: Memory allocation failed!!!!!\n");
        return 1;
    }

    for (int i = 0; i < numDrivers; i++) {
        printf("\nEnter name of driver: ", i + 1);
        fgets(drivers[i].name, sizeof(drivers[i].name), stdin);
        drivers[i].name[strcspn(drivers[i].name, "\n")] = '\0';

        printf("Enter the position of driver: ", i + 1);
        scanf("%d", &drivers[i].position);
        clear_input_buffer(); 

        drivers[i].position = rand() % numDrivers + 1;

        switch (drivers[i].position) {
            case 1:  drivers[i].points = 25; break;
            case 2:  drivers[i].points = 18; break;
            case 3:  drivers[i].points = 15; break;
            case 4:  drivers[i].points = 12; break;
            case 5:  drivers[i].points = 10; break;
            case 6:  drivers[i].points = 8;  break;
            case 7:  drivers[i].points = 6;  break;
            case 8:  drivers[i].points = 4;  break;
            case 9:  drivers[i].points = 2;  break;
            case 10: drivers[i].points = 1;  break;
            default: drivers[i].points = 0;
        }
    }
    printf("\n=== Qualifying Results ===\n");
    for (int i = 0; i < numDrivers; i++) {
        printf("Driver %s: Position %d\n", drivers[i].name, drivers[i].position);
    }

    printf("\n=== Final Standings ===\n");
    for (int i = 0; i < numDrivers; i++) {
        printf("Driver %s: Position %d, Points %d\n",
               drivers[i].name, drivers[i].position, drivers[i].points);
    }
    printf("\n=== Race Podium ===\n");
    for (int i = 0; i < numDrivers; i++) {
        if (drivers[i].position == 1)
            printf("---Winner: %s---\n", drivers[i].name);
    }
    for(int i = 0;i < numDrivers; i++) {
        if(drivers[i].position == 2)
            printf("---Second Place: %s---\n", drivers[i].name);
    }
    for(int i =0; i< numDrivers; i++) {
        if(drivers[i].position == 3)
            printf("---Third Place: %s---\n", drivers[i].name);
    }
    free(drivers);
    return 0;
}
}
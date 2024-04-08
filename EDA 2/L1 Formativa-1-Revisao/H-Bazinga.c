#include <stdio.h>
#include <string.h>


void determineReaction(char *sheldon_choice, char *raj_choice) {
    
    if ((strcmp(sheldon_choice, "pedra") == 0 && strcmp(raj_choice, "tesoura") == 0) ||
        (strcmp(sheldon_choice, "pedra") == 0 && strcmp(raj_choice, "lagarto") == 0) ||
        (strcmp(sheldon_choice, "papel") == 0 && strcmp(raj_choice, "pedra") == 0) ||
        (strcmp(sheldon_choice, "papel") == 0 && strcmp(raj_choice, "Spock") == 0) ||
        (strcmp(sheldon_choice, "tesoura") == 0 && strcmp(raj_choice, "papel") == 0) ||
        (strcmp(sheldon_choice, "tesoura") == 0 && strcmp(raj_choice, "lagarto") == 0) ||
        (strcmp(sheldon_choice, "lagarto") == 0 && strcmp(raj_choice, "papel") == 0) ||
        (strcmp(sheldon_choice, "lagarto") == 0 && strcmp(raj_choice, "Spock") == 0) ||
        (strcmp(sheldon_choice, "Spock") == 0 && strcmp(raj_choice, "pedra") == 0) ||
        (strcmp(sheldon_choice, "Spock") == 0 && strcmp(raj_choice, "tesoura") == 0)) {
        printf("Bazinga!\n");
    }
    
    else if ((strcmp(raj_choice, "pedra") == 0 && strcmp(sheldon_choice, "tesoura") == 0) ||
             (strcmp(raj_choice, "pedra") == 0 && strcmp(sheldon_choice, "lagarto") == 0) ||
             (strcmp(raj_choice, "papel") == 0 && strcmp(sheldon_choice, "pedra") == 0) ||
             (strcmp(raj_choice, "papel") == 0 && strcmp(sheldon_choice, "Spock") == 0) ||
             (strcmp(raj_choice, "tesoura") == 0 && strcmp(sheldon_choice, "papel") == 0) ||
             (strcmp(raj_choice, "tesoura") == 0 && strcmp(sheldon_choice, "lagarto") == 0) ||
             (strcmp(raj_choice, "lagarto") == 0 && strcmp(sheldon_choice, "papel") == 0) ||
             (strcmp(raj_choice, "lagarto") == 0 && strcmp(sheldon_choice, "Spock") == 0) ||
             (strcmp(raj_choice, "Spock") == 0 && strcmp(sheldon_choice, "pedra") == 0) ||
             (strcmp(raj_choice, "Spock") == 0 && strcmp(sheldon_choice, "tesoura") == 0)) {
        printf("Raj trapaceou!\n");
    }
    
    else {
        printf("De novo!\n");
    }
}

int main() {
    
    char sheldon_choice[20], raj_choice[20];

    scanf("%s %s", sheldon_choice, raj_choice);

    determineReaction(sheldon_choice, raj_choice);

    return 0;
}
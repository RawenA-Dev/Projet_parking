#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  /*Dans le code fourni, la fonction "is_valid_vehicle_type" utilise la fonction "isalpha" de la biblioth�que ctype.h 
pour v�rifier si chaque caract�re dans le type de v�hicule fourni est une lettre alphab�tique ou non.*/

#define MAX_SPOTS 100 /* le nombre maximal de places de stationnement disponibles.*/

struct Vehicle {
    char type[10];
    char plate[10];
};
/*v�rifie si le type de v�hicule donn� est valide */
int is_valid_vehicle_type(char* type) {
    for (int i = 0; type[i] != '\0'; i++) {
        if (!isalpha(type[i])) {
            return 0;
        } 
    }
    if (strcmp(type, "voiture") == 0 || strcmp(type, "scooter") == 0) {
        return 1;
    }
    return 0;
}
/*La fonction commence par boucler � travers chaque caract�re de la cha�ne "type". Si le caract�re n'est pas une lettre alphab�tique, 
la fonction renvoie imm�diatement 0 (ce qui signifie que la cha�ne n'est pas valide).
Si la boucle se termine sans renvoyer 0, cela signifie que tous les caract�res de la cha�ne "type" sont alphab�tiques. 
Ensuite, la fonction compare la cha�ne "type" avec les cha�nes "voiture" et "scooter" � l'aide de la fonction "strcmp". 
Si la comparaison indique que la cha�ne "type" est �gale � l'une des deux cha�nes, la fonction renvoie 1 pour indiquer que la cha�ne est valide. 
Sinon, la fonction renvoie 0 pour indiquer que la cha�ne est invalide.*/
int main() {
    int num_spots = MAX_SPOTS;
    struct Vehicle parking_spots[MAX_SPOTS];
    int num_vehicles = 0;

    while (1) {
        printf("\n\nApplication de syst�me de stationnement\n");
        printf("1. Arriv�e d'un v�hicule\n");
        printf("2. Nombre total de v�hicules stationn�s\n");
        printf("3. Afficher l'ordre dans lequel les v�hicules sont stationn�s\n");
        printf("4. Supprimer un v�hicule\n");
        printf("5. Quitter\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (num_vehicles < num_spots) {  
                    struct Vehicle vehicle;
                    char type[10];
                    do {
                        printf("Entrez le type de v�hicule (voiture/scooter): ");
                        scanf("%s", type);
                        if (!is_valid_vehicle_type(type)) {
                            printf("Type de v�hicule invalide. Veuillez r�essayer.\n");
                        }
                    } while (!is_valid_vehicle_type(type));
                    strcpy(vehicle.type, type);
                    printf("Entrez le num�ro de plaque: ");
                    scanf("%s", vehicle.plate);
                    parking_spots[num_vehicles] = vehicle;
                    num_vehicles++;  
                    printf("V�hicule stationn� sur la place num�ro %d.\n", num_vehicles);  /*Si une place de stationnement est disponible, le v�hicule est ajout� au tableau parking_spots et num_vehicles est incr�ment� */
                } else {
                    printf("D�sol�, aucune place de stationnement disponible.\n");
                }
                break;
            }
            case 2: {
                printf("Nombre total de v�hicules stationn�s: %d\n", num_vehicles);
                break;
            }
            case 3: {
                printf("Ordre dans lequel les v�hicules sont stationn�s:\n");
                for (int i = 0; i < num_vehicles; i++) {
                    printf("Place num�ro %d: %s avec plaque %s\n", i+1, parking_spots[i].type, parking_spots[i].plate);
                }
                break;  /* en affichant pour chaque v�hicule sa place dans le tableau parking_spots, son type et son num�ro de plaque.*/
            }
            case 4: {
                printf("Entrez le num�ro de place du v�hicule � supprimer: ");
                int spot_num;
                scanf("%d", &spot_num);
                if (spot_num < 1 || spot_num > num_vehicles) {
                    printf("Place invalide. Veuillez r�essayer.\n"); 
                } else {
                    for (int i = spot_num-1; i < num_vehicles-1; i++) {
                        parking_spots[i] = parking_spots[i+1];
                    }
                    num_vehicles--;
                    printf("V�hicule supprim� de la place num�ro %d.\n", spot_num); /*la place est valide, le v�hicule est supprim� du tableau parking_spots et num_vehicles est d�cr�ment�.*/
                }
                break;
            }
            case 5: {
                printf("Au revoir!\n");
                exit(0);
            }
            default: {
                printf("Choix invalide. Veuillez r�essayer.\n");
                break;
            }
        }
    }

    return 0;
}



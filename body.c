#include <stdio.h>
#include <string.h>

int open_File(){

    FILE *file;

    file = fopen("details.txt", "a");

    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }

    printf("What did you find? \n");
    char found[100];
    fgets(found, sizeof(found), stdin);
    fprintf(file, "Found: %s", found);

    printf("Where did you find it: \n");
    char location[100];
    fgets(location, sizeof(location), stdin);
    fprintf(file, "Location: %s", location);

    printf("When did you find it: \n");
    char time[100];
    fgets(time, sizeof(time), stdin);
    fprintf(file, "Time: %s", time);

    printf("Description: \n");
    char description[100];
    fgets(description, sizeof(description), stdin);
    fprintf(file, "Description: %s", description);

    printf("Contact information: \n");
    char contact[100];
    fgets(contact, sizeof(contact), stdin);
    fprintf(file, "Contact: %s\n", contact);

    fclose(file);
    return 0;
}

int read_File(){

   FILE *file = fopen("details.txt", "r");
    if (file == NULL) {
        printf("No records found yet.\n");
        return 1;
    }

    printf("What did you lose? \n");
    char lost[100];
    fgets(lost, sizeof(lost), stdin);

    // Remove the trailing newline character from fgets for accurate matching
    lost[strcspn(lost, "\n")] = 0;

    char buffer[256];
    int found_match = 0;

    // Search line by line for the item
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strstr(buffer, lost) != NULL) {
            found_match = 1;
            break;
        }
    }

    if (found_match) {
        printf("\nYes, it's there! Match found:\n");
        
        // Rewind to the beginning of the file to print all details of the records
        rewind(file);
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
        }
    } else {
        printf("\nNo, it's not there.\n");
    }

    fclose(file);
    return 0;
}

int situation(){

    char choice[100];
    printf("Did you: \n1. Found something \n2. Lost something \nEnter your choice: ");
    fgets(choice, sizeof(choice), stdin);
    if (strcmp(choice, "1\n") == 0 || strcmp(choice, "Found\n") == 0 || strcmp(choice, "found\n") == 0 || strcmp(choice, "Found something\n") == 0 || strcmp(choice, "found something\n") == 0){
        open_File();
    } else if (strcmp(choice, "2\n") == 0 || strcmp(choice, "Lost\n") == 0 || strcmp(choice, "lost\n") == 0 || strcmp(choice, "Lost something\n") == 0 || strcmp(choice, "lost something\n") == 0){
        read_File();
    } else {
        printf("Invalid choice");
    }
    return 0;
}

int main(){
    situation();

    return 0;
}
#include<stdio.h>
#include<ncurses.h>

int main()
{
    char filename[20];
    char string;
    FILE *original_file, *encrypted_file;
    int choice;
    char string2;
    char filename2[20];
    FILE *original_file2, *decrypted_file;
    
    printf("Creator: Ceyhun Kivanc Demir\nData encrytion and decryption");
    printf("\n\n1.Encryption\n2.Decryption\n\nWhich process you would like to do: ");
    scanf("%3d", &choice);
    
    if(choice==1){
        printf("\n\nEnter file name to be encrypted: ");
        scanf("%21s", filename);
        original_file=fopen(filename, "r");
        if (original_file==NULL){
            printf("Couldn't find the file, quiting...\n\n");
            return 0;
        }
        encrypted_file = fopen("encrypted_file.txt", "w");
        if(encrypted_file == NULL){
            printf("Couldn't create the encrypted_file file, quiting...\n\n");
            return 0;
        }
        string = fgetc(original_file);
        while(string != EOF){
            string = string+100;
            fputc(string, encrypted_file);
            string = fgetc(original_file);
        }
        printf("\nEncrypted Successfully.\n\n");
    }
    
    
    if(choice==2){
        printf("\n\nEnter Filename: ");
        scanf("%21s", filename2);
        original_file2 = fopen(filename2, "r");
        if(original_file2 == NULL){
            printf("Couldn't find the file, quiting...\n\n");
            return 0;
        }
        decrypted_file = fopen("decrypted_file.txt", "w");
        if(decrypted_file == NULL){
            printf("Couldn't create the encrypted_file file, quiting...\n\n");
            return 0;
        }
        string2 = fgetc(original_file2);
        while(string2 != EOF)
        {
            string2 = string2-100;
            fputc(string2, decrypted_file);
            string2 = fgetc(original_file2);
        }
        fclose(original_file2);
        fclose(decrypted_file);
        printf("\nFile %s Decrypted Successfully!\n\n", filename2);
        }
    
    
    return 0;
}
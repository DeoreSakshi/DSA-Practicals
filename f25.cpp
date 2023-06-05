#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 200
struct emp
{
    int id;
    char name[size];
};
void display();
void create();
void update();
char *arrr = "E:\\dsal prac\\file.txt";
FILE *fp, *fp1;
int count = 0;
int main()
{
    int ch;
    printf("1] Create a Record\n");
    printf("2] Display Records\n");
    printf("3] Update Records\n");
    printf("4] Exit\n");
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                fp = fopen(arrr, "ab");
                create();
                fclose(fp);
                break;
            case 2:
                fp1 = fopen(arrr, "rb");
                display();
                fclose(fp1);
                break;
            case 3:
                fp1 = fopen(arrr, "r+b");
                update();
                fclose(fp1);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}
/* To create an employee record */
void create()
{
    struct emp emp1;
    printf("Enter name of employee: ");
    scanf(" %[^\n]s", emp1.name);
    printf("Enter emp id: ");
    scanf("%d", &emp1.id);
    fwrite(&emp1, sizeof(emp1), 1, fp);
    count++;   // count the number of entries of records
}

/* Display the records in the file */
void display()
{
    struct emp emp3;
    printf("\nEmployee Records:\n");
    while (fread(&emp3, sizeof(emp3), 1, fp1) == 1)
    {
        printf("%d %s\n", emp3.id, emp3.name);
    }}
void update()
{
    int id, flag = 0;
    char s[size];
    struct emp emp3;
    printf("Enter employee id to update: ");
    scanf("%d", &id);
    while (fread(&emp3, sizeof(emp3), 1, fp1) == 1)
    {
        if (id == emp3.id)
        {
            printf("Enter new name of employee to update: ");
            scanf(" %[^\n]s", s);
            fseek(fp1, -sizeof(emp3), SEEK_CUR);
            strcpy(emp3.name, s);
            fwrite(&emp3, sizeof(emp3), 1, fp1);
            flag = 1;
            break;
        }
    }
    if (flag != 1)
    {
        printf("No employee record found\n");
    }}

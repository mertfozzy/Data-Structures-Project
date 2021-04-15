/*
Beykoz University - Computer Enginerring
Name: Mert Altuntas
ID : 1804010005
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MALLOC(x)((x * ) malloc(sizeof(x)))

/*============================================ NODE AND HEAD =============================================*/

struct head 
{
    struct node* identification_first;
    struct node* identification_last;
    struct node* surname_first;
    struct node* surname_last;
    struct node* score_first;
    struct node* score_last;
    int quantity;
};
typedef struct head headType;


struct headStack 
{
    struct node* first;
};
typedef struct head headType;


typedef struct stackHead stackHeadType;

struct node 
{
    char name[40], harf_score[3], surname[40];
    int identification;
    int birthday;
    double midterm_Score;
    double final_Score;
    double homework_Score;
    double project_Score;
    double total_score;
    struct node* identification_next;
    struct node* surname_next;
    struct node* score_next;
};
typedef struct node nodeType;

double highest = 0;
double  average;
double lowest = 9999999;
int compare(char string1[40], char string2[40])
{
    int i = 0;
    while (1)
    {
        if (string1[i] == string2[i])
        {
            i++;
        }
        else
        {
            break;
        }
    }
    if (string1[i] < string2[i])
    {
        return 1;
    }
    else {
        return 0;
    }
}

double totalScore(double midterm_Score, double homework_Score, double project_Score, double final_Score)
{
    double result_Score = (0.2 * midterm_Score) + (0.2 * homework_Score) + (0.3 * project_Score) + (0.3 * final_Score);
    return result_Score;
}

/*============================================= ALLOC_NODE ==============================================*/

nodeType* allocNode(int newIdentification, int newBirthDay, double newmidterm_Score, double newfinal_Score, double newhomework_Score, double newproject_Score, char newName[40], char newSurname[40]) 
{
    nodeType* new_node;
    if (new_node = MALLOC(nodeType)) 
    {
        strcpy(new_node->name, newName);
        strcpy(new_node->harf_score, "-");
        strcpy(new_node->surname, newSurname);
        new_node->identification = newIdentification;
        new_node->birthday = newBirthDay;
        new_node->midterm_Score = newmidterm_Score;
        new_node->final_Score = newfinal_Score;
        new_node->homework_Score = newhomework_Score;
        new_node->project_Score = newproject_Score;
        new_node->total_score = totalScore(newmidterm_Score, newhomework_Score, newproject_Score, newfinal_Score);

    }
    return (new_node);
}

/*============================================== HEAD_TYPE ===============================================*/

headType* create() 
{
    headType* new_node;
    if (new_node = MALLOC(headType)) 
    {
        new_node->quantity = 0;
        new_node->identification_first = NULL;
        new_node->identification_last = NULL;
        new_node->surname_first = NULL;
        new_node->surname_last = NULL;
        new_node->score_first = NULL;
        new_node->score_last = NULL;
    }
    return (new_node);
}


/*============================================== INSERT_NODE ==============================================*/

int insertNode(int newIdentification, int newBirthDay, double newmidterm_Score, double newfinal_Score, double newhomework_Score, double newproject_Score, char newName[40], char newSurname[40], headType* list) 
{
    nodeType* new_node;
    nodeType* current_node;
    if (new_node = allocNode(newIdentification, newBirthDay, newmidterm_Score, newfinal_Score, newhomework_Score, newproject_Score, newName, newSurname)) 
    {
        if (list->identification_first == NULL || list->identification_first->identification >= new_node->identification) 
        {
            new_node->identification_next = list->identification_first;
            list->identification_first = new_node;
        }
        else 
        {
            current_node = list->identification_first;
            while (current_node->identification_next != NULL && current_node->identification_next->identification < new_node->identification) 
            {
                current_node = current_node->identification_next;
            }
            new_node->identification_next = current_node->identification_next;
            current_node->identification_next = new_node;
        }
        if (list->surname_first == NULL || compare(new_node->surname, list->surname_first->surname)) 
        {
            new_node->surname_next = list->surname_first;
            list->surname_first = new_node;
        }
        else 
        {
            current_node = list->surname_first;
            while (current_node->surname_next != NULL && compare(current_node->surname_next->surname, new_node->surname)) 
            {
                current_node = current_node->surname_next;
            }
            new_node->surname_next = current_node->surname_next;
            current_node->surname_next = new_node;
        }

        if (list->score_first == NULL || compare(new_node->harf_score, list->score_first->harf_score)) 
        {
            new_node->score_next = list->score_first;
            list->score_first = new_node;
        }
        else 
        {
            current_node = list->score_first;
            while (current_node->score_next != NULL && compare(current_node->score_next->harf_score, new_node->harf_score)) 
            {
                current_node = current_node->score_next;
            }
            new_node->score_next = current_node->score_next;
            current_node->score_next = new_node;
        }

        if (list->quantity == 0)
            list->identification_last = new_node;
        list->quantity++;
        return 1;
    }
    else return 0;
}

/*============================================== DISPLAY FUNCTION =========================================*/

void display(nodeType* current_node) {
    printf("-----------------------------------------\n");
    printf("           Student Information :         \n\n");
    printf("Student Name: %s                  \n", current_node->name);
    printf("Student Surname: %s               \n\n", current_node->surname);
    printf("Student Letter Grade: %s          \n", current_node->harf_score);
    printf("Student Identification Number: %d \n", current_node->identification);
    printf("Student Birthday: %d              \n", current_node->birthday);
    printf("Student Midterm Grade: %.2f       \n", current_node->midterm_Score);
    printf("Student Final Grade: %.2f         \n", current_node->final_Score);
    printf("Student Homework Grade: %.2f      \n", current_node->homework_Score);
    printf("Student Project Grade: %.2f       \n\n", current_node->project_Score);
    printf("Student Total Grade: %.2f         \n", current_node->total_score);
    printf("-----------------------------------------\n\n");
}

void score_update(headType* list) {
    char harf[3];
    nodeType* new_node;
    new_node = list->identification_first;
    double sum = 0;
    while (new_node != NULL) {
        sum += new_node->total_score;
        if (new_node->total_score > highest) {
            highest = new_node->total_score;
        }
        if (new_node->total_score < lowest) {
            lowest = new_node->total_score;
        }
        new_node = new_node->identification_next;
    }

    if (new_node == NULL) {
        new_node = list->identification_last;
        sum += new_node->total_score;
        if (new_node->total_score > highest) {
            highest = new_node->total_score;
        }
        if (new_node->total_score < lowest) {
            lowest = new_node->total_score;
        }
    }


    average = sum / list->quantity;

    int puan_x = (highest - lowest) / 3;
    int puan_y = (average - lowest) / 2;

    new_node = list->identification_first;

    while (new_node != NULL) {

        if (new_node->total_score > (100 - puan_x) && new_node->total_score <= 100) {
            strcpy(new_node->harf_score, "AA");
        }
        else if (new_node->total_score > (100 - 2 * puan_x) && new_node->total_score <= (100 - puan_x)) {
            strcpy(new_node->harf_score, "BB");
        }
        else if (new_node->total_score > 2 * puan_y + lowest && new_node->total_score <= (100 - 2 * puan_x)) {
            strcpy(new_node->harf_score, "CC");
        }
        else if (new_node->total_score > puan_y + lowest && new_node->total_score <= 2 * puan_y + lowest) {
            strcpy(new_node->harf_score, "DD");
        }
        else if (new_node->total_score < puan_y + lowest) {
            strcpy(new_node->harf_score, "F");
        }
        else {
            strcpy(new_node->harf_score, "DZ");
        }
        new_node = new_node->identification_next;
    }

    if (new_node == NULL) {
        new_node = list->identification_last;
        if (new_node->total_score > (100 - puan_x) && new_node->total_score <= 100) {
            strcpy(new_node->harf_score, "AA");
        }
        else if (new_node->total_score > (100 - 2 * puan_x) && new_node->total_score <= (100 - puan_x)) {
            strcpy(new_node->harf_score, "BB");
        }
        else if (new_node->total_score > 2 * puan_y + lowest && new_node->total_score <= (100 - 2 * puan_x)) {
            strcpy(new_node->harf_score, "CC");
        }
        else if (new_node->total_score > puan_y + lowest && new_node->total_score <= 2 * puan_y + lowest) {
            strcpy(new_node->harf_score, "DD");
        }
        else if (new_node->total_score < puan_y + lowest) {
            strcpy(new_node->harf_score, "F");
        }
        else {
            strcpy(new_node->harf_score, "FF");
        }
    }

}

/*============================================ SOME FUNCTIONS ==========================================*/

void add_student(headType* list)
{
    score_update(list);
    int identification = 0;
    int birthday = 0;
    int midterm_Score = 0;
    int final_Score = 0;
    int homework_Score = 0;
    int project_Score = 0;
    char name[40];
    char surname[40];

    printf("Identification : ");
    scanf("%d", &identification);

    printf("\nBirthyear : ");
    scanf("%d", &birthday);

    printf("\nMidterm Grade : ");
    scanf("%d", &midterm_Score);

    printf("\nFinal Grade : ");
    scanf("%d", &final_Score);

    printf("\nHomework Grade : ");
    scanf("%d", &homework_Score);

    printf("\nProject Grade : ");
    scanf("%d", &project_Score);

    printf("\nName : ");
    scanf("%s", &name);

    printf("\nSurname : ");
    scanf("%s", &surname);

    insertNode(identification, birthday, midterm_Score, final_Score, homework_Score, project_Score, name, surname, list);
    
    printf("Student is added to system.\n");
    printf("Press any key to return to the main menu.\n");

    getch();
    system("cls");
    main();
}

void delete_student(headType* list, int searchedID)
{
    score_update(list);
    nodeType* current_node;
    current_node = list->identification_first;
    while (current_node->identification_next != NULL)
    {
        if (searchedID == list->identification_first->identification)
        {
            nodeType* temporary;
            temporary = list->identification_first;
            list->identification_first = list->identification_first->identification_next;
            free(temporary);
        }
        else if (searchedID == current_node->identification_next->identification)
        {
            nodeType* temporary;
            temporary = current_node->identification_next;
            current_node->identification_next = current_node->identification_next->identification_next;
            free(temporary);
        }
        current_node = current_node->identification_next;
    }

    printf("Press any key to return to the main menu.\n");

    getch();
    system("cls");
    main();
}

void reverse_identification(nodeType* new_node)
{
    if (new_node == NULL)
        return;
    reverse_identification(new_node->identification_next);
    display(new_node);

    printf("Press any key to return to the main menu.\n");

    getch();
    system("cls");
    main();
}


void reverse_surname(nodeType* new_node)
{

    if (new_node == NULL)
        return;
    reverse_surname(new_node->surname_next);
    display(new_node);

    printf("Press any key to return to the main menu.\n");

    getch();
    system("cls");
    main();
}

void reverse_score(nodeType* new_node)
{
    if (new_node == NULL)
        return;
    reverse_score(new_node->score_next);
    display(new_node);

    printf("Press any key to return to the main menu.\n");

    getch();
    system("cls");
    main();
}

void list_identification(headType* list)
{
    score_update(list);

    nodeType* current_node;
    current_node = list->identification_first;
    while (current_node)
    {
        display(current_node);
        current_node = current_node->identification_next;
    }

    printf("Press any key to return to the main menu.\n");

    getch();
    system("cls");
    main();
}

void list_surname(headType* list)
{
    score_update(list);
    nodeType* current_node;
    current_node = list->surname_first;
    while (current_node) {
        strcpy(current_node->harf_score, "AA");
        display(current_node);
        current_node = current_node->surname_next;
    }

    printf("Press any key to return to the main menu.\n");

    getch();
    system("cls");
    main();
}

void list_score(headType* list)
{
    score_update(list);
    nodeType* current_node;

    current_node = list->score_first;
    while (current_node)
    {
        strcpy(current_node->harf_score, "AA");
        display(current_node);
        current_node = current_node->score_next;
    }

    printf("Press any key to return to the main menu.\n");

    getch();
    system("cls");
    main();
}

void search_ID(int idNumber, headType* list) {
    nodeType* current_node;
    int student_counter = 0;
    current_node = list->identification_first;
    while (current_node) {
        if (current_node->identification == idNumber) {
            display(current_node);
            student_counter++;
        }
        current_node = current_node->identification_next;
    }
    if (student_counter == 0) {
        printf("No match.");

    }

    printf("Press any key to return to the main menu.\n");

    getch();
    system("cls");
    main();
}

void search_surname(char surnameSearch[40], headType* list) 
{
    nodeType* current_node;
    int student_counter = 0;
    current_node = list->surname_first;
    while (current_node) 
    {
        if (strcmp(current_node->surname, surnameSearch) == 0) 
        {
            display(current_node);
            student_counter++;
        }
        current_node = current_node->surname_next;
    }
    if (student_counter == 0) 
    {
        printf("No match.");
    }

    printf("Press any key to return to the main menu.\n");

    getch();
    system("cls");
    main();
}

/*================================================= MAIN ===============================================*/

int main(void) {
    system("COLOR 1F");

    headType* list;
    list = create();

    insertNode(1804010005, 2000, 90, 85, 78, 95, "Mert", "Altuntas", list);
    insertNode(1004010228, 1930, 96, 93, 90, 100, "Steve", "Rogers", list);
    insertNode(1804010568, 1999, 90, 100, 97, 98, "John", "Walker", list);
    insertNode(1604010238, 1932, 94, 96, 92, 74, "Bucky", "Barnes", list);
    insertNode(1904010238, 1998, 40, 50, 87, 93, "Sam", "Wilson", list);
    insertNode(1704010238, 1992, 45, 78, 36, 10, "Brock", "Rumlow", list);
    insertNode(1804010278, 2000, 60, 70, 80, 30, "Baron", "Zemo", list);
    
    
    int secim;
    printf("\n=============================================================\n");
    printf("WELCOME TO THE DATA STRUCTURE PROJECT\n\n");
    printf("1- List Identification\n");
    printf("2- List Surname\n");
    printf("3- List Lettered Score\n");
    printf("4- Reverse List Identification\n");
    printf("5- Reverse List Surname\n");
    printf("6- Reverse List Lettered Score\n");
    printf("7- Search Identification\n");
    printf("8- Search Surname\n");
    printf("9- Delete Student\n");
    printf("10- Add A Student\n");
    printf("\n=============================================================\n");

        printf("Enter your choice : \n");
        scanf("%d", &secim);

        switch (secim) 
        {
        
        case 1:
            system("cls");
            list_identification(list);
            break;

        case 2:
            system("cls");
            list_surname(list);
            exit(1);

        case 3:
            system("cls");
            list_score(list);
            exit(1);
        
        case 4:
            system("cls");
            score_update(list);
            reverse_identification(list->identification_first);
            exit(1);
        
        case 5:
            system("cls");
            score_update(list);
            reverse_surname(list->surname_first);
            exit(1);
        
        case 6:
            system("cls");
            score_update(list);
            reverse_score(list->score_first);
            exit(1);

        case 7: 
        {
            system("cls");
            score_update(list);
            int identification;
            printf("Enter Identification\n");
            scanf("%d", &identification);
            search_ID(identification, list);
        }

        case 8: 
        {
            system("cls");
            score_update(list);
            char surname[40];
            printf("Enter Surname : \n");
            scanf("%s", &surname);
            search_surname(surname, list);
            break;
        }


        case 9: 
        {
            system("cls");
            int s_ID;
            printf("Identification: \n");
            scanf("%d", &s_ID);
            delete_student(list, s_ID);
            break;
        }

        case 10: 
        {
            system("cls");
            add_student(list);
            break;
        }

     }
}

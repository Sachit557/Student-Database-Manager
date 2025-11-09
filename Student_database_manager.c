#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct database
{
    char name[50];      // Student's name
    float cgpa;         // CGPA
    char branch[10];    // Branch
    char password[200]; // Account password
    char srn[15];       // Student Registration Number
    int id;             // id
} db;

char Admin_acess[20] = "orangecake007"; // Admin acess password
char *Possible_Branches[10] = {"CSE", "ECE", "MECH", "EEE"};
db students[100];
int student_count = 4;
int id;

int srn_checker();
void delete_account(int id);
void password(int id);
void branch_choose(int id);
void srn_generator(int id);
void account_create();
void account_editor();
void account_view();
void account_deletor();
void program_runner();
void admin_mode();

int main()
{
    program_runner();

    return 0;
}

void program_runner() // the actual program which will be called by the main function
{

    for (int i = 0; i < student_count; i++)
    {
        students[i].id = i; // assign id
    }

    strcpy(students[0].name, "Sid"); // Hardcoded Accounts
    students[0].cgpa = 9.0;
    strcpy(students[0].password, "chocolate");
    strcpy(students[0].branch, "ECE");
    // SRN : 25ECE101

    strcpy(students[1].name, "aman");
    students[1].cgpa = 8.5;
    strcpy(students[1].password, "body_builder983");
    strcpy(students[1].branch, "MECH");
    // SRN : 25MECH102

    strcpy(students[2].name, "suman");
    students[2].cgpa = 8.0;
    strcpy(students[2].password, "Minecraft_player091");
    strcpy(students[2].branch, "ECE");
    // SRN : 25ECE103

    strcpy(students[3].name, "Sachit");
    students[3].cgpa = 9.0;
    strcpy(students[3].password, "no_password");
    strcpy(students[3].branch, "CSE");
    // SRN : 25CSE104

    for (int i = 0; i < student_count; i++)
    {
        srn_generator(i);
    }

    while (1)
    {
        printf("---------------------------------------\n");
        printf("Welcome to the student database manager\n");
        printf("---------------------------------------\n");
        printf("Choose from the following options\n");
        printf("Create - Create a new account\n");
        printf("Edit   - Edit an existing account\n");
        printf("View   - View data from an existing account\n");
        printf("Delete - Delete an existing account\n");
        printf("Exit   - Exit the running program\n");
        printf("---------------------------------------\n");
        char user_input[10];
        scanf("%9s", user_input);

        int a = strlen(user_input);

        for (int i = 0; i < a; i++) // converting to lowercase
        {
            user_input[i] = tolower(user_input[i]);
        }

        if (strcmp(user_input, "create") == 0)
        {
            account_create();
        }

        else if (strcmp(user_input, "edit") == 0)
        {
            account_editor();
        }

        else if (strcmp(user_input, "view") == 0)
        {
            account_view();
        }

        else if (strcmp(user_input, "delete") == 0)
        {
            account_deletor();
        }

        else if (strcmp(user_input, "exit") == 0)
        {
            break;
        }

        else
        {
            printf("Wrong operation type\n");
        }
    }
}

void srn_generator(int id)
{
    int num = 101 + id;
    int year = 25;
    sprintf(students[id].srn, "%d%s%d", year, students[id].branch, num);
}

void branch_choose(int id)
{
    int count = 0;
    while (1)
    {
        count++;
        if (count > 5)
        {
            printf("too many tries\n");
            break;
        }

        char user_input[10];
        printf("Enter your branch\n");
        scanf("%9s", user_input);

        int a = strlen(user_input);

        for (int i = 0; i < a; i++) // converting to lowercase
        {
            user_input[i] = tolower(user_input[i]);
        }

        if (strcmp(user_input, "cse") == 0)
        {
            strcpy(students[id].branch, "CSE");
            break;
        }

        else if (strcmp(user_input, "ece") == 0)
        {
            strcpy(students[id].branch, "ECE");
            break;
        }

        else if (strcmp(user_input, "mech") == 0)
        {
            strcpy(students[id].branch, "MECH");
            break;
        }

        else if (strcmp(user_input, "eee") == 0)
        {
            strcpy(students[id].branch, "EEE");
            break;
        }

        else
        {
            printf("Wrong Branch. Branch can only be CSE , ECE , MECH , EEE\n");
            continue;
        }
    }
}

void password(int id)
{

    int count = 0;
    char test1[15];
    char test2[15];
    int alphabets = 0;
    int numbers = 0;
    int validity = 0;

    printf("Enter the password for this account\n");
    printf("Password must be alphabets with numbers( size limit is 10)\n");
    scanf("%10s", test1);

    for (int i = 0; test1[i] != '\0'; i++)
    {
        count = count + 1;

        if (isalpha(test1[i]))
        {
            alphabets = 1;
        }

        if (isdigit(test1[i]))
        {
            numbers = 1;
        }
    }

    if (count > 10)
    {
        printf("Password too long . size limit is 10\n");
        return;
    }

    printf("Enter the password again to confirm\n");
    validity = 1;
    scanf("%10s", test2);

    if (strcmp(test1, test2) == 0)
    {
        strcpy(students[id].password, test1);
        printf("Password saved\n");
    }

    else
    {
        printf("Wrong password enter again\n");
        password(id);
    }

    // add password attempt loop here!?!?!??!
}

void account_create()
{

    printf("Enter the details to create a new acount\n"); // usimg the student_count index for saving the new data

    printf("Enter the name of the new account\n");
    scanf("%40s", students[student_count].name);

    branch_choose(student_count);

    printf("Enter your cgpa\n");
    float test_cgpa;
    scanf("%f", &test_cgpa);
    if (test_cgpa > 10.0)
    {
        printf("CGPA cant be greater than 10\n");
        return;
    }

    students[student_count].cgpa = test_cgpa;

    students[student_count].id = student_count;
    srn_generator(students[student_count].id);

    password(student_count);

    printf("your srn is %s\n", students[student_count].srn);

    student_count++;
}

int srn_checker()
{
    char input_srn[15];
    int attempts = 0;

    while (attempts < 5)
    {
        printf("Enter the srn of the account\n");
        scanf("%14s", input_srn);

        for (int i = 0; i < student_count; i++)
        {
            if (strcmp(input_srn, students[i].srn) == 0)
            {
                printf("srn found proceeding.......\n");
                return i;
            }

            if (strcmp(input_srn, Admin_acess) == 0)
            {
                printf("Secret admin acess mode\n");
                return -2;
            }
        }

        printf("SRN not found!!\n");
        attempts++;
    }

    printf("Too many invalid attempts. Acess denied.\n");
    return -1;
}

void account_editor()
{
    int index = srn_checker();

    if (index != -1 && index != -2)
    {

        char input_password[20];
        printf("Enter your password to continue:\n");
        scanf("%19s", input_password);

        if (strcmp(input_password, students[index].password) != 0)
        {
            printf("Incorrect password. Access denied.\n");
            return;
        }

        while (1)
        {

            printf("Welcome back %s\n", students[index].srn);
            printf("What would you like to edit?\n");
            printf("Name\n");
            printf("CGPA\n");
            printf("Branch\n");
            printf("Password\n");
            printf("exit\n");

            char input[20];
            scanf("%19s", input);

            for (int i = 0; input[i] != '\0'; i++)
            {
                input[i] = tolower(input[i]);
            }

            if (strcmp(input, "name") == 0)
            {
                char test[40];
                printf("Enter new name\n");
                scanf("%39s", test);
                strcpy(students[index].name, test);
                printf("The new name for the account %s is %s", students[index].srn, students[index].name);
            }

            else if (strcmp(input, "cgpa") == 0)
            {
                float test;
                printf("Enter new cgpa\n");
                scanf("%f", &test);
                if (test > 10)
                {
                    printf("CGPA cant be greater than 10\n");
                    return;
                }
                students[index].cgpa = test;
                printf("The new cgpa for the account %s is %f", students[index].srn, test);
            }

            else if (strcmp(input, "branch") == 0)
            {
                branch_choose(index);
                srn_generator(index);
                printf("The new Branch for the account %s is %s", students[index].srn, students[index].branch);
            }

            else if (strcmp(input, "password") == 0)
            {
                password(index);
            }

            else if (strcmp(input, "exit") == 0)
            {
                break;
            }

            else
            {
                printf("Invalid operation type");
                continue;
            }
        }
    }

    else if (index == -2)
    {
        admin_mode();
    }
}

void account_view()
{
    int index = srn_checker();

    if (index != -1 && index != -2)
    {
        printf("Enter the password for the account %s\n", students[index].srn);
        char input_password[20];
        scanf("%19s", input_password);

        if (strcmp(input_password, students[index].password) != 0)
        {
            printf("Incorrect password. Access denied.\n");
            return;
        }

        printf("Correct Password\n");
        printf("--------------------------------------------  \n");
        printf("Account Stats!!\n");
        printf("SRN - %s\n", students[index].srn);
        printf("Name - %s\n", students[index].name);
        printf("Branch - %s\n", students[index].branch);
        printf("CGPA - %f\n", students[index].cgpa);
        printf("-------------------------------------------- \n");
    }
}

void account_deletor()
{
    int index = srn_checker();
    if (index != -1 && index != -2)
    {
        int count = 0;
        printf("Enter the password for the account %s\n", students[index].srn);
        char input_password[20];
        scanf("%19s", input_password);

        if (strcmp(input_password, students[index].password) != 0)
        {
            printf("Incorrect password. Access denied.\n");
            return;
        }

        printf("Correct Password\n");
        printf("Are you sure you want to delete this account YES/NO\n");
        char bool[10];
        scanf("%9s", bool);

        for (int i = 0; bool[i] != '\0'; i++)
        {
            count++;
        }

        for (int i = 0; i < count; i++)
        {
            bool[i] = tolower(bool[i]);
        }

        if (strcmp(bool, "yes") == 0)
        {
            printf("Deletion of an account is permanent and it cannot be restored again\n");
            printf("Are you sure you wanna do this\n");
            printf("if you wanna delete enter the format <SRN>delete\n");
            char srn_delete[20];
            sprintf(srn_delete, "%s%s", students[index].srn, "delete");
            char input[20];
            scanf("%19s", input);

            if (strcmp(input, srn_delete) == 0)
            {
                delete_account(index);
                printf("Account deleted , %s\n", students[index].srn);
            }

            else
            {
                printf("Wrong format. Account not deleted\n");
            }
        }

        else if (strcmp(bool, "no") == 0)
        {
            printf("Account not deleted\n");
        }

        else
        {
            printf("Wrong choice\n");
        }
    }
}

void delete_account(int id)
{
    strcpy(students[id].name, "NULL");
    strcpy(students[id].branch, "NULL");
    students[id].cgpa = 0;
    char invalid_account[20];
    strcpy(students[id].password, "INVALIDACCOUNT");
}

void admin_mode()
{
    while (1)
    {

        printf("Welcome to the admin mode\n");
        printf("what settings would you like to change\n");
        printf("View-\n");
        printf("edit-\n");
        printf("delete-\n");

        char user_input[10];
        scanf("%s", user_input);

        for (int i = 0; user_input[i] != '\0'; i++)
        {
            user_input[i] = tolower(user_input[i]); // converted to lowercase
        }

        if (strcmp(user_input, "view") == 0)
        {
        }

        else if (strcmp(user_input, "edit") == 0)
        {
        }

        else if (strcmp(user_input, "delete") == 0)
        {
        }

        else if (strcmp(user_input, "exit") == 0)
        {
            printf("exit");
        }

        else
        {
            printf("Wrong input choice\n");
            continue;
        }
    }
}
#include <stdio.h>
#include <string.h>

// Define the structure for a student
typedef struct {
    char id[20];
    char password[10];
    char name[50];
    char phone[15];
    char email[50];
    char present_address[100];
    char past_address[100];
    char father_mobile[15];
    char mother_mobile[15];
    char courses[3][50];
    int num_courses;
    char application[500];
} Student;

// Initialize the student structure
Student student = {"0242310005341310", "R12345$", "", "", "", "", "", "", "", "", ""};

// Function to others step
void display_menu() {
    printf("***DIU STUDENT PROTAL****\n\n");
    printf("1. Update Profile\n");
    printf("2. View Portal\n");
    printf("3. Registration Course\n");
    printf("4. Drop Course\n");
    printf("5. Student Application\n");
    printf("6. Exit\n");
}


// Function to handle profile update
void update_profile() {
    getchar();
    printf("\n");
    printf("=Update your Profile=\n");
    printf("\n");
    printf("Enter name: ");
    gets(student.name);
    printf("Enter phone number: ");
    gets(student.phone);
    printf("Enter email: ");
    gets(student.email);
    printf("Enter present address: ");
    gets(student.present_address);
    printf("Enter past address: ");
    gets(student.past_address);
    printf("Enter father's mobile number: ");
    gets(student.father_mobile);
    printf("Enter mother's mobile number: ");
    gets(student.mother_mobile);
    printf("Profile Update successful.\n");
    printf("\n");
}

// Function to handle view portal
void view_portal() {
    printf("\n");
    printf("=View Profile=\n");

    //printf("View Portal\n");
    printf("\nName: %s\n", student.name);
    printf("ID: %s\n", student.id);
    printf("Phone: %s\n", student.phone);
    printf("Email: %s\n", student.email);
    printf("Present Address: %s\n", student.present_address);
    printf("Past Address: %s\n", student.past_address);
    printf("Father's Mobile Number: %s\n", student.father_mobile);
    printf("Mother's Mobile Number: %s\n", student.mother_mobile);
    printf("Courses: ");
    printf("\n");
    for (int i = 0; i < student.num_courses; i++) {
        printf("%s\n", student.courses[0]);

    }printf("\n");
}

// Function to handle registration course
void registration_course() {
    getchar();
    printf("\n");
    printf("=Registration course=\n");
    printf("\n");
    if (student.num_courses < 3) {
        printf("Enter course name: ");
        gets(student.courses[student.num_courses]);
        student.num_courses++;
        printf("Course registration successful.\n");
        printf("\n");
    } else {
        printf("Maximum number of courses reached.\n");
        printf("\n");
    }
}

// Function to handle student application
void student_application() {
    getchar();
    printf("Enter application: ");
    gets(student.application);

    printf("Application pending.\n");
    printf("\n");
}

// Function to handle drop course
void drop_course() {
    getchar();
    printf("\n");
    printf("=Drop Course=");
    printf("\n");
    char course[50];
    printf("Enter course name to drop: ");
    gets(course);

    for (int i = 0; i < student.num_courses; i++) {
       if (strcmp(student.courses[i], course) == 0) {
            for (int j = i; j < student.num_courses - 1; j++) {
                strcpy(student.courses[j], student.courses[j+1]);
            }
            student.num_courses--;
            printf("Course dropped successfully.\n");
            printf("\n");
            return;
        }
    }
    printf("Course not found.\n");
}

int main() {
    int choice;

    char id[20], password[10];
    printf("    ******DIU STUDENT PORTAL*******\n\n");
    printf("             =LOG IN=\n\n");
    printf("[Please Login with your ID & Provided Password]\n");
    printf("\n");
    printf("Enter ID: ");
    scanf("%s", id);
    printf("Enter Password: ");
    scanf("%s", password);
    if (strcmp(id, student.id) == 0 && strcmp(password, student.password) == 0) {
        printf("Login successful.\n");
        printf("\n");
        while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {

            case 1:
                update_profile();
                break;
            case 2:
                view_portal();
                break;
            case 3:
                registration_course();
                break;
            case 4:
                drop_course();
                break;
            case 5:
                student_application();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    }
     else {
        printf("\nInvalid ID or password.\nTry Again\n");
    }

  return 0;
}

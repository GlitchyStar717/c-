#include<stdio.h>

struct students{
    int roll;
    char name[20],address[20],phone[10];
};

int main(){
    int i, noStudents;

    printf("Enter the no. of students in class : ");
    scanf("%d",&noStudents);

    struct students s[noStudents], t[noStudents];
    FILE *file;


    file = fopen("data.bin", "wb");

    for (i=0; i<noStudents; i++){
        printf("Student's Name : ");
        scanf("%s", s[i].name);
        printf("Student's roll no : ");
        scanf("%d", &s[i].roll);
        printf("Student's address : ");
        scanf("%s", s[i].address);
        printf("Student's phone number : ");
        scanf("%s", s[i].phone);
        
        fwrite(&s[i], sizeof(s[i]), 1, file);

    }

    fclose(file);


    file = fopen("data.bin", "rb");

    for (i=0; i<noStudents; i++){
        
        fread(&t[i], sizeof(s[i]), 1, file);

        printf("Student's Name : %s.\n", t[i].name);
        printf("Student's roll no : %d.\n", t[i].roll);
        printf("Student's address : %s.\n", t[i].address);
        printf("Student's phone number : %s.\n", t[i].phone);

    }

    fclose(file);
    
}
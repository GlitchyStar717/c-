#include<stdio.h>
#include<string.h>

struct students{
    char name[20];
    int marks;
};


int main(){
    int i=0,j;
    struct students *s;
    char loop = 'y', stdName[20];


    while (loop=='y' || loop =='Y'){

        printf("Enter Student's name : ");
        scanf("%s",s[i].name);
        
        printf("Enter marks : ");
        scanf("%d",&s[i++].marks);


        printf("Another Record? (y/n)");
        scanf(" %c",&loop);

    }

    loop = 'Y';
    
    while (loop=='y' || loop =='Y'){


        printf("Student's name : ");
        scanf("%s",stdName);
        
        for (j=0;j<i;j++){
            if(!strcmp(stdName,s[j].name)){
                printf("The marks obtained by %s is %d. \n",s[j].name,s[j].marks);
                break;
            }
        }
        
        if(j==i){
            printf("No records were found for this student.\n");  
        }


        printf("Another record? (y/n)");
        scanf(" %c",&loop);

    }
}
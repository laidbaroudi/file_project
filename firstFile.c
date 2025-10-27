#include <stdio.h>
#include <string.h>
#include<stdbool.h>
typedef struct student
{
    int age;
    char name[40];
    char grade[40];
} st;
bool isopen=false;
void load_data(st *students, int *count)
{  
    FILE *fp = fopen("student.txt", "r");
    if (!fp)
    {
        fprintf(stderr, "cant open this file!");
        return;
    }
    while (fscanf(fp, "%s %s %d", students[*count].name, students[*count].grade, &students[*count].age) == 3)
    {
        (*count)++;
    }
    fclose(fp);
}
void save_data(st *students, int *count)
{
    FILE *fp = fopen("student.txt", "w");
    
    if (!fp)
    {
        fprintf(stderr, "cant open this file !");
        return;
    }
    
    for (int i = 0; i < *count; i++)
    {
        fprintf(fp, "%s %s %d\n", students[i].name, students[i].grade, students[i].age);
    }
    fclose(fp);

}
 
void update_student(st *students, int *count)
{
    char name[40];
    st up_student;
    printf("enter name:");
    fgets(name, 40, stdin);
    name[strcspn(name, "\n")] = 0;
    for (int i = 0; i < *count; i++)
    {
        if (!strcmp(name, students[i].name))
        {
            printf("enter new name:");
            scanf("%[^\n]", up_student.name);
             
            printf("enter new grade:");
            scanf("%s",up_student.grade);
            printf("enter new age:");
            scanf("%d",&up_student.age);
            students[i]=up_student;
            printf("student updated successfuly");
            return ;
        }
        

    }
    printf("student not found");
}
void add_student(st *students,int *c){
    printf("Add new student:");
    printf(" -Name:");
    scanf("%[^\n]",students[*c].name);
    printf(" -Grde:");
    scanf("%s",students[*c].grade);
    printf(" -Age:");
    scanf("%d",&students[*c].age);
    getchar();
    (*c)++;
    
    printf("student add successfuly\n");
}
void show_all(st *student,int *c){
    if(!(*c)){
        printf("not student exist !\n");
        return;
    }
    printf("==All student:==\n");
    for(int i=0;i<*c;i++){
        printf("student %d: Name:%s |Age:%d | Grade: %s\n",i+1,student[i].name,student[i].age,student[i].grade);
    }

}
void show_student(st *student,int *c){
    if(!(*c))
    {
        printf("not student exist\n");
        return ;
    }
    char name[40];
    printf("enter name:");
    scanf("%[^\n]",name);
    for(int i=0;i<*c;i++){
        if(!strcmp(name,student[i].name)){
            printf("Name:%s | age:%d | Grade:%s \n",student[i].name,student[i].age,student[i].grade);
            return;
        }
    }
    //it is one of the most powerful idea like
    
    printf("student %s not found !",name);
}
void del_student(st *students,int *c){
    if(!(*c)){
        printf("not student exist to delete !");
        return ;
    }
    char name[40];
    printf("enter name:");
    scanf("%[^\n]",name);
    getchar();
    for(int i=0;i<*c;){
    
        if(strcmp(name,students[i].name)==0){
            for(int j=i;j<(*c)-1;j++){
         students[j]=students[j+1];}
         (*c)--;
        
        }
        else{
            i++;
        }
    }
    printf("Student deleted successfully\n");
}
void menu(){
    printf("Select you choice:\n");
    printf("1-add student:\n");
    printf("2-update information:\n");
    printf("3-delete student:\n");
    printf("4-show all Students information:\n");
    printf("5-show student inoforamtion:\n");
    printf("6-exit:\n");
    printf("==>");

}
int main()
{
int ch;
st students[10];
int count=0;
load_data(students,&count);
while(true){
menu();
scanf("%d",&ch);
getchar();
switch(ch){
    case 1:
    add_student(students,&count);
    save_data(students,&count);
    break;
    case 2:
    update_student(students,&count);
    save_data(students,&count);
    break;
    case 3:
    del_student(students,&count);
    save_data(students,&count);
    break;
    case 4:
    show_all(students,&count);
    break;
    case 5:
    show_student(students,&count);
    break;
    case 6:
    printf("quit ...\n");
     return 0;
    default:
    
    printf("Invalid choice try again !\n");
    break;
}}
return 0;
}
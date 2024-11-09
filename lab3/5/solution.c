#include "functions.h"

int main(int argc, char* argv[]) {
    char absolute_path_1[PATH_MAX];
    char absolute_path_2[PATH_MAX];
    FILE* input_file, *output_file, *dialog;
    int size = 0;
    Student* students = NULL;
    char* parameters[] = {"id", "name", "lname", "group"};
    Student finded_student;

    if (argc != 3) {
        printf("Invalid amount of arguments\n");
        return INVALID_INPUT;
    }

    if (!realpath(argv[1], absolute_path_1) || !realpath(argv[2], absolute_path_2)) {
        return INVALID_INPUT;
    }

    if (strcmp(absolute_path_1, absolute_path_2) == 0) {
        printf ("The same paths\n");
        return INVALID_INPUT;
    }

    if (!(input_file = fopen(absolute_path_1, "r"))) {
        printf("Couldn't open file");
        return FILE_OPENNING_ERROR;
    }

    if (!(output_file = fopen(absolute_path_2, "w"))) {
        printf("Couldn't open file");
        return FILE_OPENNING_ERROR;
    }


    if (!(dialog = fopen("dialog.txt", "r"))) {
        printf("Couldn't open dialog file\n");
        fclose(input_file);
        fclose(output_file);
        return FILE_OPENNING_ERROR;
    }

    upload_info(&students, &size, input_file);

    // // test search 
    // get_student_info_by_parameter(&finded_student, "id", "54", students, size);
    // printf("%s\n", finded_student.last_name);

    // // test sort
    // sort("id", students, size);

    interactive_dialog(students, size, output_file);

    fclose(input_file);
    fclose(output_file);
    if (dialog) {
        fclose(dialog);
    }
    for (int i = 0; i < size; ++i) {
        free(students[i].marks);
    }
    free(students);
}
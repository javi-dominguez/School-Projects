// Javier Dominguez

#include <stdio.h>

int main() {

    int b, b1, b1_total=0, b2, j = 100, low=100, i, n1, n2, n3, n5, tests, quiz, homework, activities, final_exam, total =0;

    printf("Enter Homework amount & grades:\n");
    scanf("%d", &n1);
    for(i=0;i<n1;i++){
        scanf("%d", &homework);
        total += homework;
        if(tests <= low){
            low = homework;
        }
    }
        homework = (((total-low) / (n1-1))*.07);
        total = 0;
        low = 100;

    printf("Enter Quiz amount & grades:\n");
    scanf("%d", &n2);
    for(i=0;i<n2;i++){
        scanf("%d", &quiz);
        total += quiz;
        if(tests <= low){
            low = quiz;
        }
    }

        quiz = (((total-low)/(n2-1))*.08);
        total = 0;
        low = 100;

    printf("Enter Activities & grades:\n");
    scanf("%d", &n3);
    for(i=0;i<n3;i++){
        scanf("%d", &activities);
        total += activities;
        if(tests <= low){
            low = activities;
        }
    }

        activities = (((total-(2*low))/(n3-2))*.10);
        total = 0;
        low = 100;

    printf("Enter Tests grades:\n");
    for(i=0;i<3;i++){
        scanf("%d", &tests);
        if(tests <= j){
            j = tests;
        }
        total += (tests*.15);
        b1_total += tests;
    }
    b1 = (((b1_total - j)/2)*.30);
    printf("Lowest test score is: %d. Grade average of two tests is: %d.\n", j, b1);

        tests = total;
        total = 0;
    printf("Enter Final Exam grade:\n");
    scanf("%d", &final_exam);
        final_exam = (final_exam * .30);
        b2 = (final_exam * .45);

        total = (tests + activities + final_exam + homework + quiz);
        b = (b1 + activities + b2 + homework + quiz);

    if(total >= b){
        printf("Your grade for option A is: %d\n", total);
    }
    if(b > total){
        printf("Your grade for option B is:%d\n", b);
    }

    return 0;
}


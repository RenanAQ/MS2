#include <stdio.h>
#define MAX_STD 2

/* // ====== QUIZ CHECK START ======
//void increment(int *ptr);
int increment(int ptr);

int main()
{
    int x = 5;
    increment(x);
    printf("%d",x);
}

//void increment(int *ptr)
//{
//    (*ptr)++;
//}

int increment(int ptr)
{
    return ++(ptr);
}
*/ // ====== QUIZ CHECK END ======

struct OverallPerformance
{
    double quizzes;
    double workshops;
    double milestones;
    double exams;
};

/*
void printOverall(const struct OverallPerformance oc) //Receiving by value
{
    printf("%.2lf\n", oc.quizzes);
    printf("%.2lf\n", oc.workshops);
    printf("%.2lf\n", oc.milestones);
    printf("%.2lf\n", oc.exams);
}
*/

void printOverall(struct OverallPerformance* ptr_oc) //Receiving by address
{
    printf("Q: %.2lf\n", ptr_oc->quizzes);
    printf("W: %.2lf\n", ptr_oc->workshops);
    printf("M: %.2lf\n", ptr_oc->milestones);
    printf("E: %.2lf\n", ptr_oc->exams);
}

struct OverallPerformance getOverall()
{
    struct OverallPerformance std;
    printf("Quizzes: ");
    scanf("%lf", &std.quizzes);
    printf("workshops: ");
    scanf("%lf", &std.workshops);
    printf("Milestones: ");
    scanf("%lf", &std.milestones);
    printf("Exams: ");
    scanf("%lf", &std.exams);

    return std; //return by values
}

int main(void)
{
    //Option 01
    //struct OverallPerformance std1 = {88.5, 0, 60.7, 48.9}; //static values
    //printOverall(std1); //Passing by value
    //printOverall(&std1); //Passing by address

    //Option 02
    int i = 0;
    struct OverallPerformance std[MAX_STD];
    for (i = 0; i < MAX_STD; i++)
    {
        
        std[i] = getOverall();
        printf("Student #%d\n", i+1);
        printOverall(&std[i]);
    }

    return 0;
}
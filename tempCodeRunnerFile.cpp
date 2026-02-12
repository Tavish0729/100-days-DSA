#include <stdio.h>
struct student {
    char Name[20];
    int SapId;
    float CGPA;
    char Maths[10];
    char Python[10];
    char DSA[10];
    char DE[10];
    char Physics[10];
};
int main(){
    struct student A = {
        "Tavish Mahajan";
        590024129,
        7.5,
        "Maths",
        "Python",
        "DSA",
        "DE",
        "Python"
    };

    printf("Name: %s/n", A.Name);
    printf("SapId: %lld/n", A.SapId);
    printf("CGPA: %.2f/n", A.CGPA);
    printf("Subjects: %s, %s, %s, %s, %s/n", A.Naths, A.Python, A.DSA, A.DE, A.Physics);
}

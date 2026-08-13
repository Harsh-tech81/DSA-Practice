#include <iostream>
using namespace std;

class Student // user defined data type
{             // Try to write the name of the class in first letter in capital letter
public:       // Acccess Modifier
    string name;
    int rno;
    float perc;
    Student(string name, int rno, float perc) // parameterised constructor
    {
        (*this).name = name; // this is nothing but a pointer which stores the address of the variable or attribute
        this->rno = rno;
        this->perc = perc;
    }
};

// void change(Student &S){   // by passing it  by pass by reference it can be changed easily
//     S.name="Rohan";
// }

void change(Student *S)
{ // by using pointer method it can be done easily passing it  by pass by reference it can be changed easily
    // (*S).name="Rohan";
    S->name = "Rohan";
}

int main()
{
    Student *S = new Student("Harsh", 5, 98.9);
    // cout << "Name : " << S.name << "\n"
    //      << S.rno << "\n"
    //      << S.perc;
    cout << S->name << endl;
    // S.name="ansh";
    change(S);
    cout << S->name;

    return 0;
}
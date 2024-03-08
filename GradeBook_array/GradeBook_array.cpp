#include <iostream>
#include<array>
#include"gradeBook.h";

int main()
{
     array<array<size_t, 3>, 10>grade{ 
        87,96,70,
        {68,87,90},
        {94,100,90},
        {100,81,82},
        {83,65,85},
        {78,87,65},
        {85,75,83},
        {91,94,100},
        {76,72,84},
        {87,93,73}};
    string courseName{ "CS101 Introduction to C++ Programming" };
    GradeBook<10,3> myGradeBook(courseName, grade);
    myGradeBook.displayMessage();
    myGradeBook.processGrades();
 

}



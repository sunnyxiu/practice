#pragma once
#include <iostream>
#include<array>
#include<iomanip>
#include<string>
using std::cout;
using std::array;
using std::setw;
using std::endl;
using std::string;
using std::setprecision;
using std::fixed;
template<size_t studentNum,size_t testNum>
class GradeBook {
public:

	//static const size_t studentNum{ 10 };
    //static const size_t testNum{ 3 };

	GradeBook(const string& name, const array<array<size_t, testNum>, studentNum>& grade) : courseName(name), courseGrade(grade){};

	void setCourseName(const string& name) { courseName=name; }

	const string getCourseName()const { return courseName; }

	void displayMessage()const {
		cout << "Welcome to the grade book for\n" <<getCourseName()<<"!"<<endl;
	}
	//processGrades-output grades,call function getAverage, getMinimum and getMaximum, display grade distribution chart
    void processGrades() const{
        outputGrades();
        cout << endl;
        cout << "\nLowest grade is " << getMinimum();
        cout << "\nHighest grade is " << getMaximum()<<endl;
        outputBarChart();
    }

    void getAverage(size_t row) const{ 
        size_t total{ 0 }; 
        cout << fixed << setprecision(2);
        for (auto grades : courseGrade[row]) { total += grades; }
        cout<<setw(9)<<(static_cast<double>(total) / courseGrade[row].size());
    }

    size_t getMinimum() const{
        size_t lowestNum{100};
        for (auto const& rows : courseGrade)
        {
            for(auto const& grades:rows){
                if (grades < lowestNum) lowestNum = grades; }
        }
        return lowestNum;
    }

    size_t getMaximum() const {
        size_t highestNum{ 0 };
        for (auto const& rows : courseGrade)
        {
            for (auto const& grades : rows) {
                if (grades > highestNum) highestNum = grades;
            }
        }
        return highestNum;
    }
    
    void outputBarChart()const{
        cout << "\nGrade distribution:" << endl;

        const size_t frequencySize{ 11 };
        array<size_t, frequencySize>frequency = {};

        for (auto const& rows : courseGrade) {
            for(auto const& grades:rows){ 
                frequency[grades / 10]++; }
        }

        for (size_t range{ 0 }; range < frequency.size(); range++) {
            if (range == 0)
                cout << setw(6) << "0-9:";
            else if (range == 10)
                cout << setw(6) << "100:";
            else
                cout << range * 10 << "-" << range * 10 + 9 << ":";
            for (int starnum{ 1 }; starnum <= frequency[range]; starnum++)
                cout << "*";
            cout << endl;
        }
    }
    void outputGrades()const{
        cout << "\nThe grades are:" << endl;
        cout << "\n            Test 1  Test 2  Test 3  Average" << endl;
        for (size_t student{ 0 }; student < courseGrade.size(); student++) {
            cout << "\nStudent" << setw(3) << (student + 1);
            for (size_t test{ 0 }; test < courseGrade[student].size(); test++) {
                cout << setw(8) << courseGrade[student][test];
            } 
            getAverage(student);
        }
    }

private:
	string courseName;
	array<array<size_t,testNum>,studentNum> courseGrade;
};





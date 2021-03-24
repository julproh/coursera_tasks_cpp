#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Lecture {
    string title;
    int duration;
    string author;
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
};

struct DetailedLecture {
    LectureTitle title;
    int duration;
};
void PrintLecture(const Lecture& lecture) {
    cout <<"Title: " << lecture.title 
    << ", duration: " << lecture.duration
     << ", author: " << lecture.author << "\n";
}

void PrintCourse (const vector<Lecture>& lectures) {
    for (const Lecture& lecture : lectures) {
        PrintLecture(lecture);
    }
}
Lecture GetCurrentLecture() {
    return {"OOP",5400,"Anthon"};
}
int main () {
    Lecture lecture1;
    lecture1.title = "OOP";
    lecture1.duration = 5400;
    lecture1.author = "Anton";
    Lecture lecture0 ={"OOP", 5400, "Anthon"};
    Lecture current_Lecture = GetCurrentLecture();
    LectureTitle title = {"C++", "White belt", "OOP"};
    DetailedLecture lecture1 = {title, 5400};
    DetailedLecture lecture2 = {{"C++", "White belt", "OOP"}, 5400};
    cout << lecture2.title.specialization << endl;
        return 0;

}
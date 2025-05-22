#include <iostream>
#include <string>

struct Lecture {
    std::string title;
    std::string author;
    int duration; // in minutes
};

void print(const struct Lecture& lecture);

int main() {
    struct Lecture lecture;

    lecture.title = "Classes and Objects";
    lecture.author = "Igor";
    lecture.duration = 75;

    print(lecture);

    return 0;
}

void print(const struct Lecture& lecture) {
    std::cout << "Lecture: " << lecture.title << " by " << lecture.author << " - " << lecture.duration << " minutes long" << std::endl;
}
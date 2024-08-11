#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Question {
    string question;
    string option1;
    string option2;
    string option3;
    string option4;
    int correctAnswer;
};

Question questions[5];

void addQuestion(int index) {
    cout << "Enter question: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, questions[index].question);
    cout << "Enter option 1: ";
    getline(cin, questions[index].option1);
    cout << "Enter option 2: ";
    getline(cin, questions[index].option2);
    cout << "Enter option 3: ";
    getline(cin, questions[index].option3);
    cout << "Enter option 4: ";
    getline(cin, questions[index].option4);
    cout << "Enter correct answer (1-4): ";
    cin >> questions[index].correctAnswer;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void takeQuiz() {
    int score = 0;
    for (int i = 0; i < 5; i++) {
        cout << "Question: " << questions[i].question << endl;
        cout << "Options:" << endl;
        cout << "1. " << questions[i].option1 << endl;
        cout << "2. " << questions[i].option2 << endl;
        cout << "3. " << questions[i].option3 << endl;
        cout << "4. " << questions[i].option4 << endl;
        int answer;
        cout << "Enter your answer (1-4): ";
        cin >> answer;
        if (answer == questions[i].correctAnswer) {
            score++;
            cout << "Correct!" << endl;
        } else {
            cout << "Incorrect. Correct answer is " << questions[i].correctAnswer << endl;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Your final score is " << score << " out of 5" << endl;
}

int main() {

    for (int i = 0; i < 5; i++) {
        addQuestion(i);
    }

    
    takeQuiz();

    return 0;
}

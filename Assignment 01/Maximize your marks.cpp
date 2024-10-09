#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Question {
    int marks;
    int time;
    int index;
};

bool compare(Question q1, Question q2) {
    return (q1.marks / (double)q1.time) > (q2.marks / (double)q2.time);
}

void maximizeMarks(vector<Question>& questions, int totalMarks, int totalTime, bool withFriend) {
    sort(questions.begin(), questions.end(), compare);

    vector<int> answerStatus(questions.size(), 0);

    int totalAnsweredMarks = 0;
    int remainingTime = totalTime;

    for (int i = 0; i < questions.size(); ++i) {
        if (remainingTime >= questions[i].time) {
            answerStatus[questions[i].index] = 100;
            totalAnsweredMarks += questions[i].marks;
            remainingTime -= questions[i].time;
        } else {
            int percentageDone = (remainingTime * 100) / questions[i].time;
            answerStatus[questions[i].index] = percentageDone;
            totalAnsweredMarks += (percentageDone * questions[i].marks) / 100;
            remainingTime = 0;
        }
    }

    cout << "Maximum " << totalAnsweredMarks << " marks answering ";
    if (withFriend) {
        cout << "with a friend" << endl;
    } else {
        cout << "alone" << endl;
    }

    for (int i = 0; i < questions.size(); ++i) {
        if (answerStatus[questions[i].index] > 0) {
            cout << "ques " << questions[i].index + 1 << " " << answerStatus[questions[i].index] << "% done -- " << (answerStatus[questions[i].index] * questions[i].marks) / 100 << " marks" << endl;
        }
    }
}

int main() {
    int totalMarks, totalTime, numQuestions;
    cin >> totalMarks >> totalTime >> numQuestions;

    vector<Question> questions(numQuestions);

    for (int i = 0; i < numQuestions; ++i) {
        cin >> questions[i].marks >> questions[i].time;
        questions[i].index = i;
    }

    maximizeMarks(questions, totalMarks, totalTime, false);
    maximizeMarks(questions, totalMarks, totalTime, true);

    return 0;
}

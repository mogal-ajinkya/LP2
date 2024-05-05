#include<bits/stdc++.h>
using namespace std;
// change   
int main()
{
    vector<string> questions = {
        "Do you have experience in airline scheduling?",
        "Are you familiar with cargo scheduling?",
        "Have you worked with airline operations before?",
        "Do you understand aircraft routing and scheduling?",
        "Are you familiar with cargo loading procedures?",
        "Do you know about aviation regulations and safety standards?",
        "What is your experience with optimizing flight routes and schedules?",
        "Have you dealt with cargo capacity management?",
        "Are you comfortable with managing flight delays and disruptions?",
        "Have you worked with airline IT systems for scheduling and operations?"
    };

    map<string, int> threshold;
    threshold["Beginner"] = 0;
    threshold["Intermediate"] = 37;
    threshold["Expert"] = 70;

    cout << "\n\n\tWelcome To The Airline Scheduling and Cargo Schedules EXPERT SYSTEM\n"
         << endl;
    cout << "\tNote : Please answer the following questions \n\n"
         << endl;

    int score = 0;

    for (auto &question : questions)
    {
        cout << question << " (Y/N)";
        cout << ">  ";
        char ans;
        cin >> ans;
        while (tolower(ans) != 'y' && tolower(ans) != 'n')
        {
            cout << "Enter a valid input:" << endl;
            cout << question << " (Y/N) ";
            cout << ">  ";
            cin >> ans;
        }
        if (tolower(ans) == 'y')
        {
            cout << "On a scale of 1-10, how would you rate yourself?";
            cout << ">  ";
            int val;
            cin >> val;
            while (val < 1 || val > 10)
            {
                cout << "Enter a valid input:" << endl;
                cout << ">  ";
                cin >> val;
            }
            score += val;
        }
    }

    if (score >= threshold["Expert"])
    {
        cout << "According to our system, you seem to be an expert in airline scheduling and cargo schedules!" << endl;
        cout << "We believe you have a deep understanding of this domain." << endl;
    }
    else if (score >= threshold["Intermediate"])
    {
        cout << "Based on your answers, you seem to be at an intermediate level." << endl;
        cout << "You are advised to enhance your knowledge further." << endl;
    }
    else if (score >= threshold["Beginner"])
    {
        cout << "Based on your answers, you seem to be a beginner in this field." << endl;
        cout << "We recommend you start learning about airline and cargo scheduling basics." << endl;
        cout << "You can gain experience by working on practical projects or seeking training opportunities." << endl;
    }
    return 0;
}
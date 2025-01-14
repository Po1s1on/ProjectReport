#include <iostream>
#include <string>
using namespace std;

const int MAX_ACTIVITIES = 10; 

struct Activity {
    string name;
    int duration;
};

void logDailyActivities(Activity weeklyLog[], int& activityCount) {
    int numActivities;
    cout << "\nEnter the number of activities you want to log today (max " << (MAX_ACTIVITIES - activityCount) << "): ";
    cin >> numActivities;

    if (activityCount + numActivities > MAX_ACTIVITIES) {
        cout << "Cannot log more than " << MAX_ACTIVITIES << " activities.\n";
        return;
    }

    for (int i = 0; i < numActivities; ++i) {
        Activity activity;
        cout << "Enter activity name: ";
        cin >> activity.name;
        cout << "Enter duration in minutes: ";
        cin >> activity.duration;

       
        weeklyLog[activityCount] = activity;
        activityCount++;
    }
    cout << "\nActivities logged successfully!\n";
}

void displayWeeklySummary(const Activity weeklyLog[], int activityCount) {
    cout << "\n===== Weekly Fitness Summary =====\n";
    for (int i = 0; i < activityCount; ++i) {
        cout << "Activity: " << weeklyLog[i].name << " | Total Time: " << weeklyLog[i].duration << " minutes\n";
    }
    cout << "=================================\n";
}

int main() {
    Activity weeklyLog[MAX_ACTIVITIES];
    int activityCount = 0;
    int choice;

    do {
        cout << "\n====== Fitness Activity Log ======\n";
        cout << "1. Log Daily Activities\n";
        cout << "2. View Weekly Summary\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            logDailyActivities(weeklyLog, activityCount);
            break;
        case 2:
            displayWeeklySummary(weeklyLog, activityCount);
            break;
        case 3:
            cout << "Exiting the program. Stay fit and healthy!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
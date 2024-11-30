#include <iostream>
#include <queue>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

class Person {
public:
    string name;
    int ticket_number;

    Person(const string& n, int t) : name(n), ticket_number(t) {}
};

class Queue {
private:
    queue<Person> line;
    int ticket_counter;

public:
    Queue() : ticket_counter(1) {}

    void Enqueue(const string& name) {
        Person new_person(name, ticket_counter++);
        line.push(new_person);
        cout << name << " added to the queue with Ticket #" << new_person.ticket_number << "\n";
        cout << "Queue size: " << line.size() << "\n";
    }

    void AutoDequeue() {
        if (!line.empty()) {
            cout << "\nAfter 1 minute ...\n";
            Person front_person = line.front();
            line.pop();
            cout << "Dequeue: " << front_person.name << " received a ticket (Ticket #" << front_person.ticket_number << ")\n";
            if (!line.empty()) {
                Person next_person = line.front();
                cout << "Next in line: " << next_person.name << " (Ticket #" << next_person.ticket_number << ")\n";
            }
            cout << "Queue size: " << line.size() << "\n";
        } else {
            cout << "Queue is empty.\n";
        }
    }

    bool IsEmpty() const {
        return line.empty();
    }

    int Size() const {
        return line.size();
    }

    void Peek() const {
        if (!line.empty()) {
            Person front_person = line.front();
            cout << "Next in line: " << front_person.name << " (Ticket #" << front_person.ticket_number << ")\n";
        } else {
            cout << "Queue is empty.\n";
        }
    }

    void Position(const string& name) const {
        int position = 1;
        bool found = false;
        queue<Person> temp = line;

        while (!temp.empty()) {
            Person current = temp.front();
            temp.pop();
            if (current.name == name) {
                cout << name << " is currently at position " << position << " in the queue.\n";
                found = true;
                break;
            }
            position++;
        }

        if (!found) {
            cout << name << " is not in the queue.\n";
        }
    }
};

int main() {
    Queue concertQueue;
    int choice;
    string name;

    cout << "Welcome to Olivia Rodrigo's Concert Ticketing System!\n";
    while (true) {
        cout << "\n1. Enqueue a person\n2. Check your position in the queue\n3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the name: ";
                cin >> name;
                concertQueue.Enqueue(name);
                break;

            case 2:
                cout << "Enter your name: ";
                cin >> name;
                concertQueue.Position(name);
                break;

            case 3:
                cout << "Exiting the system...\n";
                return 0;

            default:
                cout << "Invalid option. Try again.\n";
        }


        this_thread::sleep_for(chrono::seconds(1));
        concertQueue.AutoDequeue();
    }

    return 0;
}

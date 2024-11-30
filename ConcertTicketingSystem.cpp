#include <iostream>
#include <string>
#include <queue>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std; 

class Person {
public:
    string name;
    string ticket_number;

    Person(string n, string t) : name(n), ticket_number(t) {}
};

class TicketQueue {
private:
    queue<Person> q;
    int ticket_count = 0;

public:
    void enqueue(string name) {
        ticket_count++;
        string ticket_number = to_string(ticket_count);
        ticket_number.insert(0, 3 - ticket_number.length(), '0'); 
        q.push(Person(name, ticket_number));
        cout << name << " added to the queue with Ticket #" << ticket_number << endl;
        cout << "Queue size: " << q.size() << endl;
    }

    void auto_dequeue() {
        while (!q.empty()) {
            this_thread::sleep_for(chrono::seconds(60)); 
            Person p = q.front();
            cout << "Dequeue: " << p.name << " received a ticket (Ticket #" << p.ticket_number << ")" << endl;
            q.pop();
            cout << "Queue size: " << q.size() << endl;
            if (!q.empty()) {
                cout << "Next in line: " << q.front().name << " (Ticket #" << q.front().ticket_number << ")" << endl;
            } else {
                cout << "No one is in line." << endl;
            }
        }
    }

    bool is_empty() {
        return q.empty();
    }

    int size() {
        return q.size();
    }

    void peek() {
        if (!q.empty()) {
            Person p = q.front();
            cout << "Next in line: " << p.name << " (Ticket #" << p.ticket_number << ")" << endl;
        } else {
            cout << "No one is in line." << endl;
        }
    }

    int position(string identifier) {
        queue<Person> temp = q; 
        int pos = 1;

        while (!temp.empty()) {
            if (temp.front().name == identifier || temp.front().ticket_number == identifier) {
                return pos;
            }
            temp.pop();
            pos++;
        }
        return -1; 
    }
};

int main() {
    TicketQueue ticketQueue;
    cout << "Welcome to Olivia Rodrigo's Concert Ticketing System!" << endl;

    while (true) {
        cout << "\n1. Enqueue a person" << endl;
        cout << "2. Check your position in the queue" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            cout << "Enter the name: ";
            cin.ignore(); 
            getline(cin, name); 
            ticketQueue.enqueue(name);
            
            static bool dequeue_thread_running = false;
            if (!dequeue_thread_running) {
                dequeue_thread_running = true;
                thread(&TicketQueue::auto_dequeue, &ticketQueue).detach();
            }
        } else if (choice == 2) {
            string identifier;
            cout << "Enter your name or ticket number: ";
            cin.ignore(); 
            getline(cin, identifier); 
            int pos = ticketQueue.position(identifier);
            if (pos != -1) {
                cout << identifier << " is currently at position " << pos << " in the queue." << endl;
            } else {
                cout << identifier << " not found in the queue." << endl;
            }
        } else if (choice == 3) {
            break; 
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}

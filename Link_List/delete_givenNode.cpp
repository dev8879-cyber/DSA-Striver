#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* getnode(int x) {
    node* ptr = (node*)malloc(sizeof(node));
    ptr->data = x;
    ptr->next = nullptr;
    return ptr;
}

void prt_Ll(node* head) {
    node* pt = head;
    while (pt != nullptr) {
        cout << pt->data << "->";
        pt = pt->next;
    }
    cout << "Null" << endl;
}

int getLength(node* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

void Insert_Strt(node* head) {
    int x1;
    cout << "Enter data: ";
    cin >> x1;
    node* strt = getnode(x1);
    strt->next = head;
    head = strt;
    prt_Ll(head);
}

void Del_Last(node*& head) {
    if (head == nullptr) {
        cout << "List is already empty." << endl;
        return;
    }
    if (head->next == nullptr) {
        free(head);
        head = nullptr;
        prt_Ll(head);
        return;
    }
    node* del = head;
    node* prev = nullptr;
    while (del->next != nullptr) {
        prev = del;
        del = del->next;
    }
    prev->next = nullptr;
    free(del);
    prt_Ll(head);
}

void Insert_Last(node*& head) {
    int xL;
    cout << "Enter value of last node: ";
    cin >> xL;
    node* last = getnode(xL);
    if (head == nullptr) {
        head = last;
    } else {
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = last;
    }
    prt_Ll(head);
}

void Del_first(node*& head) {
    if (head == nullptr) {
        cout << "List is already empty." << endl;
        return;
    }
    node* del = head;
    head = head->next;
    free(del);
    prt_Ll(head);
}

void Insert_pos(node*& head) {
    int pos;
    cout << "Enter position to insert: ";
    cin >> pos;

    int len = getLength(head);
    if (pos <= 1) {
        cout << "Inserting at start..." << endl;
        Insert_Strt(head);
    } else if (pos > len) {
        cout << "Inserting at end..." << endl;
        Insert_Last(head);
    } else {
        int val;
        cout << "Enter data: ";
        cin >> val;
        node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        node* newNode = getnode(val);
        newNode->next = temp->next;
        temp->next = newNode;
        prt_Ll(head);
    }
}

void Del_pos(node*& head) {
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    if (pos <= 1) {
        Del_first(head);
        return;
    }

    node* temp = head;
    node* prev = nullptr;

    for (int i = 1; i < pos; i++) {
        prev = temp;
        if (temp->next == nullptr) {
            cout << "Position out of bounds." << endl;
            return;
        }
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);
    prt_Ll(head);
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    node* head = nullptr;

    if (n > 0) {
        int val;
        cout << "Enter data of node 1: ";
        cin >> val;
        head = getnode(val);
        node* temp = head;
        for (int i = 1; i < n; i++) {
            cout << "Enter data of node " << i + 1 << ": ";
            cin >> val;
            temp->next = getnode(val);
            temp = temp->next;
        }
    } else {
        cout << "Creating an empty list..." << endl;
    }

    cout << "Initial linked list: ";
    prt_Ll(head);

    while (true) {
        int opr;
        cout << "\nChoose operation to perform:\n";
        cout << "0. Exit\n";
        cout << "1. Insert at start\n";
        cout << "2. Delete last\n";
        cout << "3. Insert at end\n";
        cout << "4. Delete first\n";
        cout << "5. Insert at position\n";
        cout << "6. Delete at position\n";
        cout << "Enter operation number: ";
        cin >> opr;

        switch (opr) {
            case 0:
                cout << "Exiting program..." << endl;
                return 0;
            case 1:
                Insert_Strt(head);
                break;
            case 2:
                Del_Last(head);
                break;
            case 3:
                Insert_Last(head);
                break;
            case 4:
                Del_first(head);
                break;
            case 5:
                Insert_pos(head);
                break;
            case 6:
                Del_pos(head);
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}

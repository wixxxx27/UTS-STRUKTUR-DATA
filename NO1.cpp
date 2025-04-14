#include <iostream>
using namespace std;

// Struktur node untuk linked list
struct Node {
    int bit;
    Node* next;
    Node(int b) : bit(b), next(NULL) {}
};

// Menambahkan node baru ke akhir linked list
void tambah(Node*& head, int bit) {
    Node* baru = new Node(bit);
    if (!head) {
        head = baru;
    } else {
        Node* node = head;
        while (node->next) {
            node = node->next;
        }
        node->next = baru;
    }
}

// Menghitung nilai desimal dari linked list biner
int konversiKeDesimal(Node* head) {
    int desimal = 0;
    int faktor = 1;
    while (head) {
        desimal += head->bit * faktor;
        faktor *= 2;
        head = head->next;
    }
    return desimal;
}

// Input 1 byte (8 bit) dari user
void inputBiner(Node*& head) {
    cout << "\nMasukkan 8 bit dari bit ke-8 (MSB) ke bit ke-1 (LSB):\n";
    for (int i = 0; i < 8; i++) {
        int bit;
        do {
            cout << "Bit ke-" << 8 - i << " (0 atau 1): ";
            cin >> bit;
        } while (bit != 0 && bit != 1);
        tambah(head, bit);
    }
}

int main() {
    cout << "\n=============================\n";
    cout << "  KONVERSI BINER KE DESIMAL\n";
    cout << "=============================\n";

    Node* head = NULL;
    inputBiner(head);

    cout << "\nHasil Konversi:\n";
    cout << "Nilai Desimal: " << konversiKeDesimal(head) << endl;

    return 0;
}



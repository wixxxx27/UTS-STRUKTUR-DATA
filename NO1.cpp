// KONVERSI NILAI BINER KE DESIMAL

#include <iostream>
using namespace std;

// STRUKTUR NODE UNTUK LINKED LIST (TANPA CONSTRUCTOR)
struct Node {
    int bit;
    Node* next;
};

// MENAMBAHKAN NODE BARU KE AKHIR LINKED LIST
void tambah(Node*& head, int bit) {
    
    Node* currentNode = new Node;
    currentNode->bit = bit;
    currentNode->next = NULL;

    if (!head) {
        head = currentNode;
    } else {
        Node* node = head;
        while (node->next) {
            node = node->next;
        }
        node->next = currentNode;
    }
}

// MENGHITUNG NILAI DESIMAL DARI LINKED LIST BINER
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

// INPUT 1 BYTE (8 BIT) DARI USER
void inputBiner(Node*& head) {
    cout << "\nMasukkan nilai 8 bit:\n";
    for (int i = 0; i < 8; i++) {
        int bit;
        do {
            cout << "Bit ke-" << i + 1 << " (0 atau 1): ";
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


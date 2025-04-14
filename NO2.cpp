
#include <iostream>

using namespace std;

const int MAX = 100;
char stack[MAX];
int top = -1;

// Fungsi dasar stack
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    } else {
        cout << "Stack penuh!\n";
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        cout << "Stack kosong!\n";
        return '\0';
    }
}

bool isEmpty() {
    return top == -1;
}

// Konversi desimal ke heksadesimal
void decimalToHex(int decimal) {
    char hexDigits[] = "0123456789ABCDEF";

    if (decimal == 0) {
        cout << "Hasil: 0" << endl;
        return;
    }

    while (decimal > 0) {
        int sisa = decimal % 16;
        push(hexDigits[sisa]);
        decimal /= 16;
    }

    cout << "Hasil: ";
    while (!isEmpty()) {
        cout << pop();
    }
    cout << endl;
}

int main() {
    // Tampilan judul di awal program
    cout << "\n\n==================================\n";
    cout << " KONVERSI DESIMAL KE HEXADECIMAL\n";
    cout << "==================================\n";

    int decimal;
    cout << "Masukkan bilangan desimal: ";
    cin >> decimal;
    decimalToHex(decimal);
    return 0;
}

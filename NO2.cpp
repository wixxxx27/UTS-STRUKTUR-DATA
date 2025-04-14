// KONFERSI NILAI DESIMAL KE HEXADESIMAL

#include <iostream>
using namespace std;

//VARIABEL GLOBAL
const int MAX = 100;
char stack[MAX];
int top = -1;

// FUNGSI STACK
void push(char x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    } else {
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        return '\0';
    }
}

bool isEmpty() {
    return top == -1;
}

// KONVERSI DESIMAL KE HEXADESIMAL
void desimalkeHexa(int desimal) {
    char hexaDigits[] = "0123456789ABCDEF";

    if (desimal == 0) {
        cout << "Hasil: 0" << endl;
        return;
    }

    while (desimal > 0) {
        int sisa = desimal % 16;
        push(hexaDigits[sisa]);
        desimal /= 16;
    }

    cout << "Hasil: ";
    while (!isEmpty()) {
        cout << pop();
    }
    cout << endl;
}

int main() {
    
    cout << "\n\n==================================\n";
    cout << " KONVERSI DESIMAL KE HEXADECIMAL\n";
    cout << "==================================\n";

    int decimal;
    cout << "Masukkan bilangan desimal: ";
    cin >> decimal;
    desimalkeHexa(decimal);
    return 0;
}

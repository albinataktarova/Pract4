#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

#include "AES.h"
#include "SERP.h"


using namespace std;
using namespace CryptoPP;

int main ()
{
    cout << "Шифратор файлов" << endl;
    cout << "Группа 19PT1, 2020" << endl;
    cout << "Тактарова" << endl;
    cout << "-----2020-----" << endl;
    unsigned op, cip;
    string FIn, FOut, Pass;

    do {
        cout << "\nВведите действие (0 - Выход, 1 - Шифрование, 2 - Дешифрование): ";
        cin >> op;

        if (op != 0) {
            cout << "\nВыбор алгоритма: " << endl;
            cout << "|   AES-256    |=1" << endl;
            cout << "|   tSerpent   |=2" << endl;

            cout << "Выберите алгоритм: ";
            cin >> cip;
        }

        if (op > 2) {
            cerr << "Ошибка\n";
        }

        else if (op > 0) {
            cout << "\nВыберите файл для совершения действия: ";
            cin >> FIn;

            cout << "\nВыборите файл для записи действия: ";
            cin >> FOut;

            cout << "\nЗапишите пароль: ";
            cin >> Pass;

            if (cip == 1) {
                AES_Cryptor aes(FIn, FOut, Pass);
                if (op == 1) {
                    if (aes.AES_Encrypt())
                        cout << "Файл зашифрован!" << endl;
                    else
                        cout << "Ошибка зашифрования!" << endl;
                } else {
                    if (aes.AES_Decrypt())
                        cout << "Файл дешифрован!" << endl;
                    else
                        cout << "Ошибка дешифрования!" << endl;
                }
            } else if (cip == 2) {
                Serpent_Cryptor s(FIn, FOut, Pass);
                if (op == 1) {
                    if (s.Serpent_Encrypt())
                        cout << "Файл зашифрован!" << endl;
                    else
                        cout << "Ошибка зашифрования!" << endl;
                } else {
                    if (s.Serpent_Decrypt())
                        cout << "Файл дешифрован!" << endl;
                    else
                        cout << "Ошибка дешифрования!" << endl;
                }
            } else {
                cerr << "Ошибка\n";
            }
        }
    } while (op != 0);
    return 0;
}

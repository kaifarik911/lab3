#include "modGronsfeld.h"
#include <iostream>
#include <locale>

// Функция проверки валидности текста
bool isValid(const std::wstring& s) {
    for (auto c : s) {
        if (!modAlphaCipher::isValidChar(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    try {
        // Устанавливаем русскую локаль
        std::locale loc("ru_RU.UTF-8");
        std::locale::global(loc);

        std::wstring key, text;
        int op;

        std::wcout << L"Введите ключ для шифра Гронсвельда: ";
        std::wcin >> key;

        modAlphaCipher cipher(key);

        do {
            std::wcout << L"Выберите операцию (0 - выход, 1 - зашифровать, 2 - расшифровать): ";
            std::wcin >> op;

            if (op > 2) {
                std::wcout << L"Некорректная операция\n";
            } else if (op > 0) {
                std::wcin.ignore(); // Игнорируем остатки в буфере
                std::wcout << L"Введите текст: ";
                std::getline(std::wcin, text);

                if (isValid(text)) {
                    if (op == 1) {
                        std::wcout << L"Зашифрованный текст: " << cipher.encrypt(text) << std::endl;
                    } else {
                        std::wcout << L"Расшифрованный текст: " << cipher.decrypt(text) << std::endl;
                    }
                } else {
                    std::wcout << L"Текст содержит недопустимые символы\n";
                }
            }
        } while (op != 0);

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}

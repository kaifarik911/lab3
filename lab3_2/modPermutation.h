#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include <locale>
#include <map>
#include <algorithm>

class modPermutationCipher {
private:
    std::wstring alphabet; // Алфавит
    std::vector<int> key;  // Ключ в виде вектора

public:
    explicit modPermutationCipher(const std::wstring& skey); // Конструктор с ключом

    std::wstring encrypt(const std::wstring& open_text);   // Шифрование
    std::wstring decrypt(const std::wstring& cipher_text); // Расшифровка

    void validateKey(const std::wstring& key);             // Валидация ключа
    void validateText(const std::wstring& text);           // Валидация текста
};

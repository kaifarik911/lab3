#include "modPermutation.h"

// Конструктор, инициализирующий ключ
modPermutationCipher::modPermutationCipher(const std::wstring& skey) {
    if (skey.empty()) {
        throw std::invalid_argument("Ошибка: ключ не может быть пустым. Пожалуйста, введите положительное целое число.");
    }
    alphabet = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯabcdefghijklmnopqrstuvwxyz"; // Русский и английский алфавиты
    validateKey(skey);
    for (auto& ch : skey) {
        key.push_back(wchar_t(ch) - L'0');
    }
}

// Валидация ключа
void modPermutationCipher::validateKey(const std::wstring& skey) {
    for (const auto& ch : skey) {
        if (!iswdigit(ch)) {
            throw std::invalid_argument("Ошибка: ключ должен состоять только из цифр. Пожалуйста, введите положительное целое число.");
        }
    }

    int keyValue = std::stoi(skey);
    if (keyValue <= 0) {
        throw std::invalid_argument("Ошибка: ключ должен быть положительным целым числом. Пожалуйста, введите корректный ключ.");
    }
}

// Валидация текста
void modPermutationCipher::validateText(const std::wstring& text) {
    if (text.empty()) {
        throw std::invalid_argument("Ошибка: текст не может быть пустым. Пожалуйста, введите текст для шифрования/расшифрования.");
    }
    for (const auto& ch : text) {
        if (alphabet.find(ch) == std::wstring::npos) {
            throw std::invalid_argument("Ошибка: текст должен содержать только буквы из заданного алфавита (русские и английские буквы).");
        }
    }
}

// Шифрование текста
std::wstring modPermutationCipher::encrypt(const std::wstring& open_text) {
    validateText(open_text);
    std::wstring result;
    size_t keySize = key.size();

    for (size_t i = 0; i < open_text.size(); ++i) {
        wchar_t ch = open_text[i];
        size_t index = alphabet.find(ch);
        if (index != std::wstring::npos) {
            int shift = key[i % keySize];  // Сдвиг из ключа
            result.push_back(alphabet[(index + shift) % alphabet.size()]);  // Сдвигаем символ
        }
    }
    return result;
}

// Расшифровка текста
std::wstring modPermutationCipher::decrypt(const std::wstring& cipher_text) {
    validateText(cipher_text);
    std::wstring result;
    size_t keySize = key.size();

    for (size_t i = 0; i < cipher_text.size(); ++i) {
        wchar_t ch = cipher_text[i];
        size_t index = alphabet.find(ch);
        if (index != std::wstring::npos) {
            int shift = key[i % keySize];  // Сдвиг из ключа
            result.push_back(alphabet[(index - shift + alphabet.size()) % alphabet.size()]);  // Расшифровка
        }
    }
    return result;
}

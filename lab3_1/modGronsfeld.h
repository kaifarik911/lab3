#pragma once
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <iostream>

class modAlphaCipher {
private:
    static const std::wstring numAlpha;
    static std::map<wchar_t, int> alphaNum;
    std::vector<int> key;

    std::vector<int> convert(const std::wstring& s);
    std::wstring convert(const std::vector<int>& v);

public:
    modAlphaCipher() = delete;
    explicit modAlphaCipher(const std::wstring& skey);

    std::wstring encrypt(const std::wstring& open_text);
    std::wstring decrypt(const std::wstring& cipher_text);

    // Новый публичный статический метод для проверки валидности символа
    static bool isValidChar(wchar_t c);
};

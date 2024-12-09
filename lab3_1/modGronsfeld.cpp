#include "modGronsfeld.h"

// Инициализация статического поля
std::map<wchar_t, int> modAlphaCipher::alphaNum = []() {
    std::map<wchar_t, int> m;
    std::wstring alpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    for (size_t i = 0; i < alpha.size(); ++i) {
        m[alpha[i]] = static_cast<int>(i);
    }
    return m;
}();

const std::wstring modAlphaCipher::numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";

modAlphaCipher::modAlphaCipher(const std::wstring& skey) {
    if (skey.empty()) {
        throw std::invalid_argument("Key is empty.");
    }
    key = convert(skey);
}

std::vector<int> modAlphaCipher::convert(const std::wstring& s) {
    std::vector<int> result;
    for (auto c : s) {
        if (alphaNum.find(c) == alphaNum.end()) {
            throw std::invalid_argument("Invalid character in text.");
        }
        result.push_back(alphaNum[c]);
    }
    return result;
}

std::wstring modAlphaCipher::convert(const std::vector<int>& v) {
    std::wstring result;
    for (auto n : v) {
        result += numAlpha[n % numAlpha.size()];
    }
    return result;
}

std::wstring modAlphaCipher::encrypt(const std::wstring& open_text) {
    auto work = convert(open_text);
    for (size_t i = 0; i < work.size(); ++i) {
        work[i] = (work[i] + key[i % key.size()]) % numAlpha.size();
    }
    return convert(work);
}

std::wstring modAlphaCipher::decrypt(const std::wstring& cipher_text) {
    auto work = convert(cipher_text);
    for (size_t i = 0; i < work.size(); ++i) {
        work[i] = (work[i] + numAlpha.size() - key[i % key.size()]) % numAlpha.size();
    }
    return convert(work);
}

bool modAlphaCipher::isValidChar(wchar_t c) {
    return alphaNum.find(c) != alphaNum.end();
}

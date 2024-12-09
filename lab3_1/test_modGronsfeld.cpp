#include "modGronsfeld.h"
#include <UnitTest++/UnitTest++.h>

// Функция проверки валидности текста
bool isValid(const std::wstring& s) {
    for (auto c : s) {
        if (!modAlphaCipher::isValidChar(c)) {
            return false;
        }
    }
    return true;
}

// Тесты
SUITE(GronsfeldCipherTests) {
    TEST(EncryptEmptyText) {
        modAlphaCipher cipher(L"БКД");
        std::wstring encrypted = cipher.encrypt(L"");
        CHECK(encrypted == L"");
    }

    TEST(DecryptEmptyText) {
        modAlphaCipher cipher(L"БКД");
        std::wstring decrypted = cipher.decrypt(L"");
        CHECK(decrypted == L"");
    }

    TEST(EncryptInvalidChars) {
        modAlphaCipher cipher(L"БКД");
        CHECK_THROW(cipher.encrypt(L"бгеж"), std::invalid_argument);
    }

    TEST(DecryptInvalidChars) {
        modAlphaCipher cipher(L"БКД");
        CHECK_THROW(cipher.decrypt(L"бгеж"), std::invalid_argument);
    }

    TEST(EncryptWithInvalidSymbol) {
        modAlphaCipher cipher(L"БКД");
        CHECK_THROW(cipher.encrypt(L"Hello"), std::invalid_argument);
    }

    TEST(EncryptMinimalKey) {
        modAlphaCipher cipher(L"БКД");
        std::wstring encrypted = cipher.encrypt(L"БГЕЖ");
        CHECK(!encrypted.empty());
    }

    TEST(EncryptLongKey) {
        modAlphaCipher cipher(L"БКДБКДБКДБКД");
        std::wstring encrypted = cipher.encrypt(L"БГЕЖ");
        CHECK(!encrypted.empty());
    }

    TEST(CorrectEncryption) {
        modAlphaCipher cipher(L"БКД");
        std::wstring encrypted = cipher.encrypt(L"БГЕЖ");
        CHECK(encrypted == L"ВНИЗ");
    }

    TEST(CorrectDecryption) {
        modAlphaCipher cipher(L"БКД");
        std::wstring decrypted = cipher.decrypt(L"ВНИЗ");
        CHECK(decrypted == L"БГЕЖ");
    }
}

// Главная функция для тестов
int main() {
    return UnitTest::RunAllTests();
}

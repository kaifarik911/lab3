#include <UnitTest++/UnitTest++.h>
#include "modPermutation.h"
#include <locale>
#include <codecvt>

std::string wstring_to_string(const std::wstring& wstr) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstr);
}

TEST(TestConstructorValidKey) {
    modPermutationCipher cipher(L"123");
    CHECK(true);
}

TEST(TestConstructorInvalidKeyNonDigit) {
    CHECK_THROW(modPermutationCipher(L"бкд"), std::invalid_argument);
}

TEST(TestConstructorEmptyKey) {
    CHECK_THROW(modPermutationCipher(L""), std::invalid_argument);
}

TEST(TestEncryptEmptyText) {
    modPermutationCipher cipher(L"123");
    CHECK_THROW(cipher.encrypt(L""), std::invalid_argument);
}

TEST(TestEncryptValidText) {
    modPermutationCipher cipher(L"123");
    std::wstring encrypted = cipher.encrypt(L"АБВ");
    CHECK_EQUAL(wstring_to_string(encrypted), "БГЕ");
}

TEST(TestDecryptValidText) {
    modPermutationCipher cipher(L"123");
    std::wstring decrypted = cipher.decrypt(L"БГД");
    CHECK_EQUAL(wstring_to_string(decrypted), "АББ");
}

int main() {
    return UnitTest::RunAllTests();
}

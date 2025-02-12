#include <iostream>
#include <string>
#include <random>
#include <ctime>

class RandomString
{
private:
    static const std::string CHAR_LOWER;
    static const std::string CHAR_UPPER;
    static const std::string NUMBER;
    static const std::string SPECIAL_CHAR;
    static const std::string ALL_CHAR;

public:
    static std::string generate(int length)
    {
        if (length < 1)
        {
            throw std::invalid_argument("Length must be positive");
        }

        std::mt19937 generator(time(0));
        std::uniform_int_distribution<int> distribution(0, ALL_CHAR.length() - 1);

        std::string result;
        for (int i = 0; i < length; i++)
        {
            result += ALL_CHAR[distribution(generator)];
        }

        return result;
    }
};

const std::string RandomString::CHAR_LOWER = "abcdefghijklmnopqrstuvwxyz";
const std::string RandomString::CHAR_UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string RandomString::NUMBER = "0123456789";
const std::string RandomString::SPECIAL_CHAR = "!@#$%^&*_=+-/";
const std::string RandomString::ALL_CHAR = CHAR_LOWER + CHAR_UPPER + NUMBER + SPECIAL_CHAR;

int main()
{
        std::string randomString = RandomString::generate(10);
        std::cout << randomString << std::endl;
    
    return 0;
}

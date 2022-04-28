#include <gtest/gtest.h>
#include "hardsource.h"
#include "hard1.h" // Сюда я вытащила все заголовки с первой домашки, что бы не плодить
using namespace std;


TEST(TaskOne, Pers){
   Person a =  {"Ibanov", "Dimirtiy"};
   Person b = {"Dmitriev", "Ivam"};
   ASSERT_FALSE(a==b);
  ASSERT_LT(b, a);
}

TEST(TaskOne, Phone){
    PhoneNumber testA =  {7, 909, "7877759", 4};
    PhoneNumber testB = {8, 302, "3453455"};
    ASSERT_FALSE(testA  == testB);
    ASSERT_LT(testA , testB);
}

class TestDate : public testing::Test{
protected:
    void SetUp() override {
        Person a =  {"Ibanov", "Dimirtiy"};
        Person b = {"Dmitriev", "Ivam"};
        Person c = {"Kotov", "Anton"};
        PhoneNumber testA =  {7, 909, "7877759", 4};
        PhoneNumber testB = {8, 302, "3453455"};
        PhoneNumber testC = {8, 302, "3453453"};
        std::pair<Person, PhoneNumber> f (a,testA);
        std::pair<Person, PhoneNumber>  s (b,testB);
        std::pair<Person, PhoneNumber> t (c,testC);
       std::vector<std::pair<Person, PhoneNumber>> testBook;
       testBook.push_back(f);
        testBook.push_back(s);
        testBook.push_back(t);
       PhoneBook book(testBook);
        cout << "done";
    };
    void TearDown() override {
        delete book;
    }
    PhoneBook *book;

};

TEST_F(TestDate, phoneBookOne){
    book->SortByPhone();
    std::string testDateA = book->bookPh.end()->first.lastName;
    ASSERT_TRUE(testDateA == "Kotov");
}

TEST_F(TestDate, phoneBookTwo){
    book->SortByName();
    std::string testDateA = book->bookPh.begin()->first.lastName;
    ASSERT_TRUE(testDateA == "Kotov");
}

TEST_F(TestDate, phoneBookThree) {
    std::pair<std::string, std::vector<PhoneNumber>> testB = book->GetPhoneNumber("Udin");
    const char *s = testB.first.c_str();
    ASSERT_STREQ("not found", s);

}
int main() {
   testing::InitGoogleTest();
    RUN_ALL_TESTS();
    return  0;
}
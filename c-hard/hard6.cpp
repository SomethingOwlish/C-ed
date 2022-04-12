//
// Created by Morgan Valravn on 10.04.2022.
//

#include "hardsource.h"
// Task 1
static std::mutex mCout;

class pcout
{
private:
    std::lock_guard<std::mutex> lockCout;
public:
    pcout() : lockCout(std::lock_guard<std::mutex>(mCout))
    {
    }

    template<typename T>
    pcout& operator<<(const T &data)
    {
        std::cout << data;
        return *this;
    }

    pcout& operator<<(std::ostream& (*fp)(std::ostream&))
    {
        std::cout << fp;
        return *this;
    }
};


void printTest(int thInfo)
{
    pcout() << "start #" << thInfo << std::endl;
    pcout() << "stop #" << thInfo << std::endl;
};

//task 2
bool isSimple(size_t num)
{
    size_t l = num / 2;

    if (num > 2)
    {
        for (size_t i = 2; i <= l; ++i)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
    }

    return true;
};


std::mutex mSimple;
std::mutex mCounter;
bool isReady = false;

bool isSimple(int n){
    if (n <=0){
        return false;
    } else {
        for (int i = 2; i < n; i++)
            if (n % i == 0) {
                 return false;}
        else{};
        return true;};

};


int UniqueNumber(){
    static int i = 2;
    return i++;
};


class SimpleNumber{
private:
    int counter = 1;
    int resalt;
    int num;

public:
    int getCounter(){
        return counter;};
    int getNumber(){
        return num;};
    int getRes(){
        return resalt;};
        SimpleNumber(int i) {
            num = i;
        };
    int returnNumber(){
        std::vector<int> numbers(50000);
        std::generate(numbers.begin(), numbers.end(), UniqueNumber);


        std::vector<int> res;
        res.clear();
        for (int it = 0; counter<num; it++){
            if(isSimple(numbers[it])){
                mCounter.lock();
                counter++;
                res.push_back(numbers[it]);
                mCounter.unlock();
            } else {};
          //  std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Костыль замедляющий процесс, что бы было вижно прогресс выполнения
        };

        int a = getNumber() - 2;
        resalt = res[a];
        return res[a];


    };};


void countAndPrint(SimpleNumber &task){
    int simple = task.returnNumber();
    isReady = true;
    mSimple.lock();
    std::cout << task.getNumber() <<"-ное простое число = "<< simple << std::endl;
    mSimple.unlock();
};

void progressBar(SimpleNumber &task){
    std::cout << "Progress:" << std::endl;
    int max = task.getNumber();
    while (!isReady){
        int progress;
        mCounter.lock();
        progress = (task.getCounter() * 100)/ max;
        mSimple.lock();
        std::cout << progress << "% выполнено" << std::endl;
        mCounter.unlock();
        mSimple.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(5));


    }


};

//Task 3
std::mutex hCout;

int randNum(){
    return rand() % 500 +1;
};

class Home{
private:

    std::vector<int> homeCase;
    bool isAv;

    public:

    Home(){
        homeCase.clear();
        homeCase.resize(5);
        std::generate(homeCase.begin(),homeCase.end(),randNum);
        isAv = true;
    };

    void addNum(int i)
    {
        homeCase.push_back(i);
    };

    int getNum(){
 //std::sort(homeCase.begin(), homeCase.end());
       // std::max_element(homeCase.begin(), homeCase.end())
size_t s = homeCase.size();
auto a = std::max_element(homeCase.begin(), homeCase.end());
     int i =    std::distance(homeCase.begin(), a);
        int res = homeCase[i];
        homeCase.erase(a);
 if (s == 1){isAv = false;};
 return i;
    };

    int getSize(){
        return homeCase.size() - 1;
    };

    bool isAviable(){
     return isAv;
    };

};

void houseOwner(Home &h){
   do { int object = randNum();
    h.addNum(object);
    mCout.lock();
    std::cout << "Принес. В доме "<< h.getSize() << " Вещей" << std::endl;
    mCout.unlock();
    std::this_thread::sleep_for(std::chrono::seconds(1));}
   while (h.isAviable());

};

void thief(Home &h){
    do {

        int still = h.getNum();
        mCout.lock();
        std::cout << "Украл "<< still << " из дома" << std::endl;
        mCout.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds (500));
    } while (h.isAviable());
};

int main(){
    srand(time(0));
    std::cout  << "Task 1" << '\n';
    std::thread th1(printTest, 1);
    std::thread th2(printTest, 2);
    std::thread th3(printTest, 3);
    th1.join();
    th2.join();
    th3.join();
    std::cout  << "Task 2" << '\n';
int iSimple =  rand() % 500 +10; //число не очень большое, что бы не ужасаться ждать и удобно проверять.
   SimpleNumber task(iSimple);
    std::thread task21(countAndPrint, std::ref(task));
    std::thread task22(progressBar, std::ref(task));
task21.join();
task22.join();
    std::cout  << "Task 3" << '\n';
    Home home;
    auto first(std::async(std::launch::async, houseOwner, std::ref(home)));
    auto second(std::async(std::launch::async, thief, std::ref(home)));


    return 0;
};
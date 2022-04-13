//
// Created by Morgan Valravn on 13.04.2022.
//


#include "hardsource.h"
#include "s.pb.h"

    class IRepository {
        virtual void Open() = 0; // бинарная десериализация в файл
        virtual void Save() = 0; // бинарная сериализация в файл
    };

    class IMethods {
        virtual double GetAverageScore(const studentList::FullName &name) = 0;

        virtual std::string GetAllInfo(const studentList::FullName &name) = 0;

        virtual std::string GetAllInfo() = 0;
    };

    class StudentsGroup: public IRepository, public IMethods {
    private:
        std::vector<studentList::Student> allStudents;
    public:
        void addStudent(const studentList::Student &s) {
            allStudents.push_back(s);
        };

        double GetAverageScore(const studentList::FullName &name) {
            auto it = std::find_if(allStudents.begin(), allStudents.end(), [&](const studentList::Student &s) {
                return tie(s.full_name().name(), s.full_name().surname(), s.full_name().fathername()) ==
                       tie(name.name(), name.surname(), name.fathername());
            });

            if (it == allStudents.end()) {
                return 0.0;
            }

            return it->median();
        };

        std::string GetAllInfo(const studentList::FullName &name) {
            auto it = std::find_if(allStudents.begin(), allStudents.end(), [&](const studentList::Student &s) {
                return tie(s.full_name().name(), s.full_name().surname(), s.full_name().fathername()) ==
                       tie(name.name(), name.surname(), name.fathername());
            });

            if (it == allStudents.end()) {
                return {};
            }

            std::string temp = "Name: " + it->full_name().name() + ' ' + it->full_name().surname() + ' ' +
                               it->full_name().fathername() + '\n';
            temp += "Marks: ";
            for (int i = 0; i < it->marks().size(); ++i) {
                temp += std::to_string(it->marks(i)) + "; ";
            }
            temp += '\n';
            temp += "AVG: " + std::to_string(it->median()) + "\n\n";

            return temp;
        };

        std::string GetAllInfo() {
            std::string temp;

            std::for_each(allStudents.begin(), allStudents.end(), [&](const studentList::Student &s) {
                temp += GetAllInfo(s.full_name());
            });

            return temp;
        };

        void Save() {
            std::ofstream out("datas.bin", std::ios_base::binary);
            auto size = allStudents.size();
            out.write(reinterpret_cast<char *>(&size), sizeof(size));
            std::for_each(allStudents.begin(), allStudents.end(), [&](const studentList::Student &s) {
                s.SerializeToOstream(&out);
            });
            out.close();
        };

        void Open() {
            std::ifstream in("datas.bin", std::ios_base::binary);
            size_t size = 0;
            in.read(reinterpret_cast<char *>(&size), sizeof(size));
            while (size--) {
                studentList::Student s;
                s.ParseFromIstream(&in);
                allStudents.push_back(std::move(s));
            }
            in.close();
        }


    };


int main() {
    srand(time(0));

    studentList::FullName Owl;
    Owl.set_name("Anna");
    Owl.set_surname("Sova");
    Owl.set_fathername("Andreevna");
 /*
    studentList::Student s;
    *s.mutable_full_name() = Owl;
    s.add_marks(rand() % 5 +1);
    s.add_marks(rand() % 5 +1);
    s.add_marks(rand() % 5 +1);
    s.add_marks(rand() % 5 +1);
    s.add_marks(rand() % 5 +1);
    s.add_marks(rand() % 5 +1);
    s.add_marks(rand() % 5 +1);
    s.add_marks(rand() % 5 +1);
    s.set_median(std::accumulate(s.marks().begin(), s.marks().end(), 0) / s.marks().size());

   */
};
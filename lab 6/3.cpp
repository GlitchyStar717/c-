#include <iostream>
#include <string>

class Musicians {
protected:
    std::string stringInstruments[5] = {"veena", "guitar", "sitar", "sarod", "mandolin"};
    std::string windInstruments[5] = {"flute", "clarinet", "saxophone", "nadhaswaram", "piccolo"};
    std::string percInstruments[5] = {"tabla", "mridangam", "bangos", "drums", "tambour"};

public:
    void string() {
        std::cout << "String Instruments:" << std::endl;
        displayInstruments(stringInstruments, 5);
    }

    void wind() {
        std::cout << "Wind Instruments:" << std::endl;
        displayInstruments(windInstruments, 5);
    }

    void perc() {
        std::cout << "Percussion Instruments:" << std::endl;
        displayInstruments(percInstruments, 5);
    }

private:
    void displayInstruments(const std::string instruments[], int size) {
        for (int i = 0; i < size; i++) {
            std::cout << instruments[i] << std::endl;
        }
    }
};

class TypeIns : public Musicians {
public:
    void get() {
        char choice;
        std::cout << "Type of instruments to be displayed" << std::endl;
        std::cout << "a. String instruments" << std::endl;
        std::cout << "b. Wind instruments" << std::endl;
        std::cout << "c. Percussion instruments" << std::endl;
        std::cout << "Enter your choice (a/b/c): ";
        std::cin >> choice;

        switch (choice) {
            case 'a':
                show(stringInstruments, 5);
                break;
            case 'b':
                show(windInstruments, 5);
                break;
            case 'c':
                show(percInstruments, 5);
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    }

    void show(const std::string instruments[], int size) {
        std::cout << "Instruments:" << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << instruments[i] << std::endl;
        }
    }
};

int main() {
    Musicians musicians;
    musicians.string();
    std::cout << std::endl;

    musicians.wind();
    std::cout << std::endl;

    musicians.perc();
    std::cout << std::endl;

    TypeIns typeIns;
    typeIns.get();

    return 0;
}

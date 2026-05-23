#include <iostream>
#include <string>

class dynamic{
    private:
    int size;
    int *array;

    public:
    dynamic(int s);
    ~dynamic();
    dynamic(const dynamic& a);
    dynamic& operator=(const dynamic& a);

    int* getDataAddress() const { return array;}
    
};

dynamic::dynamic(int s){
    size = s;
    array = new int[s];
    for (int i = 0; i < size; i++ ){
        array[i]= 0;
    }
}

dynamic::~dynamic()
{
    delete[] array;
    size=0;
}

dynamic::dynamic(const dynamic& a){
    size = a.size;
    array = new int[size];
    for (int i = 0; i < size; i++ ){
        array[i]= a.array[i];
    }
}

dynamic& dynamic::operator=(const dynamic& a){
    if (this == &a) return *this;
    delete[] array;
    size = a.size;
    array = new int[size];
    for (int i = 0; i < size; i++) {
            array[i] = a.array[i];
        }
    return *this;

}

int main() {
    std::cout << "--- 'a' objektum létrehozása ---\n";
    dynamic a(12);

    std::cout << "\n--- 'b' objektum létrehozása 'a' alapján (Másoló konstr.) ---\n";
    dynamic b = a; 

    std::cout << "\n--- Ellenőrzés ---\n";
    std::cout << "'a' tömbjének címe a Heap-en: " << a.getDataAddress() << std::endl;
    std::cout << "'b' tömbjének címe a Heap-en: " << b.getDataAddress() << std::endl;

    if (a.getDataAddress() != b.getDataAddress()) {
        std::cout << "\nSIKER: A két objektum különböző memóriaterületet használ (Deep Copy)!\n" << std::endl;
    } else {
        std::cout << "\nHIBA: A két objektum ugyanoda mutat (Shallow Copy)!\n" << std::endl;
    }

    return 0;
}
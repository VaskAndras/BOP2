#include <string>
#include <iostream>

class eurhuf {

    private:
    int huf;
    double eur;
    
    public:
    explicit eurhuf(int a):huf(a){
        eur = (double)huf/400;
    }
    explicit operator double(){
        return eur;
    }
    explicit operator int(){
        return huf;
    } 
    };
    double division(eurhuf a, eurhuf b ){
        if(b.eur==0){
            throw "error";
        }
        else{
            return a.eur/b.eur;
        } 
 
    }

int main(){
eurhuf a(4), b(0);

try(
   double c = division(a, b);
)
catch(const string& a){
    std::cout << a;
}

}

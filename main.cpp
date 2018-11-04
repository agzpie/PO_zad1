#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
using namespace std;

//	SAMOCHOD
class Samochod {
    public:
        void ustawPoziomPaliwa(int poziomPaliwa) {
            if (poziomPaliwa < 0)
                return;

            this->poziomPaliwa = poziomPaliwa;
        }

        int dajPoziomPaliwa() {
            return poziomPaliwa;
        }

        void ustawStanTechniczny(bool stanTechniczny) {
            this->stanTechniczny = stanTechniczny;
        }

        bool dajStanTechniczy() {
            return stanTechniczny;
        }

        Samochod(int poziomPaliwa, bool stanTechniczny) {
            ustawPoziomPaliwa(poziomPaliwa);
            ustawStanTechniczny(stanTechniczny);
        }

        ~Samochod() {}

        void pokaz() {
            cout << "Poziom paliwa: " << dajPoziomPaliwa() << endl;
            cout << "Stan techniczny: " << dajStanTechniczy() << endl;
        }

    private:
        int	poziomPaliwa;
        bool stanTechniczny;
};

//	KIEROWCA
class Kierowca {
    public:
        bool czyMogeJechac(Samochod &s) {
            if (!s.dajStanTechniczy() || s.dajPoziomPaliwa() < 10)
                return false;
            else
                return true;
        }

		Kierowca() {}
		~Kierowca() {}
};

// MECHANIK
class Mechanik {
    public:
        void napraw(Samochod &s) {
            s.ustawStanTechniczny(true);
            s.ustawPoziomPaliwa(60);
        }

        Mechanik() {}
        ~Mechanik() {}
};

void sprawdzenie(Samochod &samochod, Mechanik &mechanik, Kierowca &kierowca) {
    if (!kierowca.czyMogeJechac(samochod)) {
        cout << "Stan samochodu przed naprawa: " << endl;
        samochod.pokaz();
        mechanik.napraw(samochod);
        cout << "Stan samochodu po naprawie: " << endl;
        samochod.pokaz();
    }
}

int main(){

    Samochod samochod1(9, false);

    Samochod samochod2(30, true);

    Mechanik zdzichu;

    Kierowca krzychu;

    cout << "Samochod nr 1: " << endl;
    sprawdzenie(samochod1, zdzichu, krzychu);

    cout << "Samochod nr 2: " << endl;
    sprawdzenie(samochod2, zdzichu, krzychu);

    system("pause");

    return 0;
}

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
using namespace std;


//	SAMOCHOD
class Samochod
{
    //int		poziomPaliwa;
    //bool		stanTechniczny;
public:
    void		ustawPoziomPaliwa(int poziomPaliwa){this->poziomPaliwa = poziomPaliwa;}
    int		dajPoziomPaliwa(){return poziomPaliwa;}
    void		ustawStanTechniczny(bool stanTechniczny){this->stanTechniczny = stanTechniczny;}
    bool		dajStanTechniczy(){return stanTechniczny;}

    void	ustaw(int, bool);

    Samochod(int, bool);
    Samochod();
    ~Samochod();
//int		Samochod(poziomPaliwa, stanTechniczny);

    void	pokaz();

private:
    int		poziomPaliwa;
    bool	stanTechniczny;

};

void Samochod::ustaw(int poziomPaliwa, bool stanTechniczny){
    this->poziomPaliwa = poziomPaliwa;
    this->stanTechniczny = stanTechniczny;
};

Samochod::Samochod(){
    this->poziomPaliwa = 0;
    this->stanTechniczny = false;
};

Samochod::~Samochod(){
    std::cout << "Samochod destroyed\n";
};

void Samochod::pokaz(){
    std::cout << "Poziom paliwa samochodu: " << this->poziomPaliwa << "\nStan techniczny: " << this->stanTechniczny << "\n";
};
/*
//	KIEROWCA

class	Kierowca
{
 		bool	czyMogeJechac;
 		int		paliwo = Samochod& samochod1.poziomPaliwa;
 		bool	stan = Samochod& samochod1.stanTechniczny;

 		if (paliwo >= 10 && stan = true)
		   		czyMogeJechac = true;
 		else
 				czyMogeJechac = false;

 		public:
			   bool		czyMogeJechac(){return czyMogeJechac;}


		Kierowca();
		~Kierowca();

		void 	pokazStan();

};

void Kierowca::pokazStan() {
	 std::cout << "Czy  mozna jechac?: \t" <<  this->czyMogeJechac << "\n";
};
*/






int main(){

    Samochod samochod1;
    samochod1.ustawPoziomPaliwa(9);
    samochod1.ustawStanTechniczny(false);
    samochod1.pokaz();

//	Kierowca kierowca1;
//	kierowca1.pokazStan();



    system("pause");

    return 0;
}

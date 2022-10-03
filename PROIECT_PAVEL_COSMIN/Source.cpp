#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class ExceptieCustomOperatorFunctie :public exception {
public:
	const char* what() const throw() {
		return "Pretul adaugat este < 2 sau > 8 \n";
	}
};

class ExceptieCustomOperatorIndex :public exception {
public:
	const char* what() const throw() {
		return "Eroare: index < 0 sau index > nr_de_preturi !! \n";
	}
};

class Pom_Fructifer {
	char* nume; // reprezinta numele arborelui/pomului fructifer
	int varsta; // reprezinta varsta de productie a pomului fructifer
	bool altoit; // 0 nu este altoit, 1 este altoit
	double cantitate_productie;  // cantitatea de fructe produse de un anumit soi de pom fructifer
	double pretul_de_cost; // pretul la care firma este pe 0, acest pret acopera invetitia 
	int nr_de_preturi; // numarul de preturi din lista de preturi
	double* lista_preturi;  // vectorul de preturi al roadelor din culvarea acestui soi
public:
	Pom_Fructifer() {
		this->nume = new char[strlen("---numele copacului fructitor nu este setat---") + 1];
		strcpy(this->nume, "---numele copacului fructitor nu este setat---");
		this->varsta = 3; // varsat la care un copac aduce primele roade
		this->altoit = 0;
		this->cantitate_productie = 0;
		this->pretul_de_cost = 0;
		this->nr_de_preturi = 0;
		this->lista_preturi = nullptr;
	}

	Pom_Fructifer(const char* name, int vrst, bool alt, double cant, double pret_cost, int nr, double* lst) {
		if (name != nullptr) {
			this->nume = new char[strlen(name) + 1];
			strcpy(this->nume, name);
		}
		else {
			this->nume = new char[strlen("---numele copacului fructitor nu este setat---") + 1];
			strcpy(this->nume, "---numele copacului fructitor nu este setat---");
		}

		if (vrst <= 3) {
			throw new exception("Varsta nu este valabila! \n");
		}
		else {
			this->varsta = vrst;
		}

		if (alt != 1 && alt != 0) {
			throw new exception("Altoit nu este adevarat sau fals! \n");
		}
		else {
			this->altoit = alt;
		}

		if (cant <= 0) {
			throw new exception("Valoare invalida !!\n");
		}
		else {
			this->cantitate_productie = cant;
		}

		if (pret_cost <= 0) {
			throw new exception("Invalid !!\n");
		}
		else {
			this->pretul_de_cost = pret_cost;
		}

		if (nr <= 0) {
			throw new exception("Numar invalida !!\n");
		}
		else {
			this->nr_de_preturi = nr;
		}

		if (this->lista_preturi != nullptr) {
			throw new exception("Vectorul de preturi nu este valid !!");
		}
		else {
			this->lista_preturi = new double[nr];
			for (int i = 0; i < nr; i++) {
				this->lista_preturi[i] = lst[i];
			}
		}
	}

	Pom_Fructifer(int vrst, bool alt, double cantitate, double pret_cost, int nr, double* lst) {

		if (vrst <= 3) {
			throw new exception("Varsta nu este valabila! \n");
		}
		else {
			this->varsta = vrst;
		}

		if (alt != 1 && alt != 0) {
			throw new exception("Altoit nu este adevarat sau fals! \n");
		}
		else {
			this->altoit = alt;
		}

		if (cantitate <= 0) {
			throw new exception("Valoare invalida !!\n");
		}
		else {
			this->cantitate_productie = cantitate;
		}

		if (pret_cost <= 0) {
			throw new exception("Invalid !!\n");
		}
		else {
			this->pretul_de_cost = pret_cost;
		}

		if (nr <= 0) {
			throw new exception("Numar invalida !!\n");
		}
		else {
			this->nr_de_preturi = nr;
		}

		if (this->lista_preturi != nullptr) {
			throw new exception("Vectorul de preturi nu este valid !!\n");
		}
		else {
			this->lista_preturi = new double[nr];
			for (int i = 0; i < nr; i++) {
				this->lista_preturi[i] = lst[i];
			}
		}

		this->nume = new char[strlen("---numele copacului fructitor nu este setat---") + 1];
		strcpy(this->nume, "---numele copacului fructitor nu este setat---");
	}
	virtual void administrareCalciu() = 0;

	Pom_Fructifer(const Pom_Fructifer& pom) {
		//cout << "Constructor de copiere\n";
		if (pom.nume != nullptr) {
			this->nume = new char[strlen(pom.nume) + 1];
			strcpy(this->nume, pom.nume);
		}
		else {
			this->nume = new char[strlen("---numele copacului fructitor nu este setat---") + 1];
			strcpy(this->nume, "---numele copacului fructitor nu este setat---");
		}

		this->varsta = pom.varsta;
		this->altoit = pom.altoit;
		this->cantitate_productie = pom.cantitate_productie;
		this->pretul_de_cost = pom.pretul_de_cost;
		this->nr_de_preturi = pom.nr_de_preturi;
		this->lista_preturi = new double[pom.nr_de_preturi];
		for (int i = 0; i < pom.nr_de_preturi; i++) {
			this->lista_preturi[i] = pom.lista_preturi[i];
		}
	}

	~Pom_Fructifer() {
		if (this->nume != nullptr) {
			delete[] this->nume;
		}

		if (this->lista_preturi != nullptr) {
			delete[] this->lista_preturi;
		}
	}

	Pom_Fructifer& operator=(const Pom_Fructifer& pom) {
		//cout << "\nOperator =\n";
		if (this != &pom) {
			if (this->nume != nullptr) {
				delete[] this->nume;
			}

			if (this->lista_preturi != nullptr) {
				delete[] this->lista_preturi;
			}

			if (pom.nume != nullptr) {
				this->nume = new char[strlen(pom.nume) + 1];
				strcpy(this->nume, pom.nume);
			}
			else {
				this->nume = new char[strlen("---numele copacului fructitor nu este setat---") + 1];
				strcpy(this->nume, "---numele copacului fructitor nu este setat---");
			}

			this->varsta = pom.varsta;
			this->altoit = pom.altoit;
			this->cantitate_productie = pom.cantitate_productie;
			this->pretul_de_cost = pom.pretul_de_cost;
			this->nr_de_preturi = pom.nr_de_preturi;

			this->lista_preturi = new double[pom.nr_de_preturi];
			for (int i = 0; i < pom.nr_de_preturi; i++) {
				this->lista_preturi[i] = pom.lista_preturi[i];
			}
		}
		return *this;
	}


	friend ostream& operator<<(ostream& out, const Pom_Fructifer& pom) {
		out << (pom.nume ? pom.nume : "---numele copacului fructitor nu este setat---") << " are varsta " << pom.varsta << (pom.altoit ? " ,este altoit" : " ,nu este altoit")
			<< " ,cantitatea de productie " << pom.cantitate_productie << " ,pretul de cost fiind " << pom.pretul_de_cost
			<< " ,preturile cu care se obtine profit sunt: ";
		for (int i = 0; i < pom.nr_de_preturi; i++) {
			out << pom.lista_preturi[i] << "  ";
		}
		return out;
	}

	friend istream& operator>>(istream& inn, Pom_Fructifer& pom) {
		char aux[100];
		cout << "Nume arbore: ";
		inn.get(aux, 100);

		if (pom.nume != nullptr) {
			delete[] pom.nume;
		}

		pom.nume = new char[strlen(aux) + 1];
		strcpy(pom.nume, aux);

		cout << "Varsta: "; inn >> pom.varsta;
		cout << "Altoit: [0/1] "; inn >> pom.altoit;
		cout << "Cantitate produsa: "; inn >> pom.cantitate_productie;
		cout << "Pret de cost: "; inn >> pom.pretul_de_cost;
		cout << "Numar de preturi: "; inn >> pom.nr_de_preturi;

		if (pom.lista_preturi != nullptr) {
			delete[] pom.lista_preturi;
		}

		pom.lista_preturi = new double[pom.nr_de_preturi];
		for (int i = 0; i < pom.nr_de_preturi; i++) {
			cout << "Pret [" << i << "] = ";
			inn >> pom.lista_preturi[i];
			inn.ignore();
		}

		return inn;
	}

	char* getNume() {
		return nume;
	}

	int getVartsa() {
		return varsta;
	}

	bool getAltoit() {
		return altoit;
	}

	double getCantitate() {
		return cantitate_productie;
	}

	double getPret_cost() {
		return pretul_de_cost;
	}

	int getNumar_preturi() {
		return nr_de_preturi;
	}

	double* getLista_preturi() {
		double* aux = new double[nr_de_preturi];
		for (int i = 0; i < nr_de_preturi; i++) {
			aux[i] = lista_preturi[i];
		}
		return aux;
	}

	void crestere_preturi(double* lst, int poz, double pret_nou) {
		if (lst != nullptr) {
			delete[] this->lista_preturi;

			this->lista_preturi = new double[nr_de_preturi];
			for (int i = 0; i < nr_de_preturi; i++) {
				this->lista_preturi[i] = lst[i];
				if (i == poz) {
					this->lista_preturi[i] = pret_nou;
				}
			}
		}
		else {
			throw new exception("Lst este null sau nr_preturi este <=0.");
		}
	}

	bool operator==(Pom_Fructifer& p) {
		if (this == &p) {
			return true;
		}

		bool nrm = strcmp(this->nume, p.nume) == 0 &&
			this->varsta == p.varsta &&
			this->altoit == p.altoit &&
			this->cantitate_productie == p.cantitate_productie &&
			this->pretul_de_cost == p.pretul_de_cost &&
			this->nr_de_preturi == p.nr_de_preturi;

		if (nrm == true) {
			for (int i = 0; i < nr_de_preturi; i++) {
				if (this->lista_preturi[i] != p.lista_preturi[i]) {
					return false;
				}
			}
			return true;
		}
		else {
			return false;
		}

	}

	void scrieInFisierBinar(ofstream& fisBin) {
		int dim = 0;
		dim = strlen(nume) + 1;
		fisBin.write((char*)&dim, sizeof(dim));
		fisBin.write(nume, dim);

		fisBin.write((char*)&this->varsta, sizeof(this->varsta));

		fisBin.write((char*)&this->altoit, sizeof(this->altoit));

		fisBin.write((char*)&this->cantitate_productie, sizeof(this->cantitate_productie));

		fisBin.write((char*)&this->pretul_de_cost, sizeof(this->pretul_de_cost));

		fisBin.write((char*)&this->nr_de_preturi, sizeof(this->nr_de_preturi));

		for (int i = 0; i < nr_de_preturi; i++) {
			fisBin.write((char*)&this->lista_preturi[i], sizeof(double));
		}
	}

	void citireDinFisierBinar(ifstream& fisBin) {
		int dim = 0;
		fisBin.read((char*)&dim, sizeof(dim));

		char aux[100];
		fisBin.read(aux, dim);
		if (nume != nullptr) {
			delete[] nume;
		}

		this->nume = new char[strlen(aux) + 1];
		strcpy(this->nume, aux);

		fisBin.read((char*)&this->varsta, sizeof(this->varsta));

		fisBin.read((char*)&this->altoit, sizeof(this->altoit));

		fisBin.read((char*)&this->cantitate_productie, sizeof(this->cantitate_productie));

		fisBin.read((char*)&this->pretul_de_cost, sizeof(this->pretul_de_cost));

		fisBin.read((char*)&this->nr_de_preturi, sizeof(this->nr_de_preturi));

		if (this->lista_preturi != nullptr) {
			delete[] this->lista_preturi;
		}

		this->lista_preturi = new double[nr_de_preturi];
		for (int i = 0; i < nr_de_preturi; i++) {
			fisBin.read((char*)&this->lista_preturi[i], sizeof(double));
		}
	}

};

class Mar : public Pom_Fructifer {
	int nr_pomi;
	string soi;
public:
	Mar() :Pom_Fructifer() {
		this->nr_pomi = 0;
		this->soi = "--- numele soiului nu este setat---";
	}

	Mar(const char* name, int vrst, bool alt, double cant, double pret_cost, int nr, double* lst, int nr_pomi, string soi)
		: Pom_Fructifer(name, vrst, alt, cant, pret_cost, nr, lst) {

		if (nr_pomi <= 0) {
			throw new exception("Numar invalida !!\n");
		}
		else {
			this->nr_pomi = nr_pomi;
		}

		if (soi.empty()) {
			throw new exception("Numele soiului este gol\n");
		}
		else {
			this->soi = soi;
		}
	}

	Mar(int vrst, bool alt, double cantitate, double pret_cost, int nr, double* lst, int nr_pomi, string soi)
		: Pom_Fructifer(vrst, alt, cantitate, pret_cost, nr, lst) {

		if (nr_pomi <= 0) {
			throw new exception("Numar invalida !!\n");
		}
		else {
			this->nr_pomi = nr_pomi;
		}

		if (soi.empty()) {
			throw new exception("Numele soiului este gol\n");
		}
		else {
			this->soi = soi;
		}
	}

	Mar(const Mar& m) :Pom_Fructifer(m) {
		this->nr_pomi = m.nr_pomi;
		this->soi = m.soi;
	}

	~Mar() { 	}

	Mar& operator=(const Mar& m) {
		if (this != &m) {
			Pom_Fructifer::operator=(m);

			this->nr_pomi = m.nr_pomi;
			this->soi = m.soi;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Mar& m) {
		operator<<(out, (Pom_Fructifer&)m);
		out << "numar de pomi " << m.nr_pomi << " ,soiul fiind " << m.soi << endl;

		return out;
	}

	void administrareCalciu() {
		cout << "Fiecare mar(pom) a primit 10ml de calciu\n";
	}

	//operator ++ - pre-incrementare
	const Mar& operator++() {
		nr_pomi++;

		return *this;
	}

	//operator ++ - post-incrementare
	const Mar operator++(int) {
		Mar aux(*this);
		nr_pomi++;
		return aux;
	}

	//operatori binari
	//op. + (ex: cout<<s5+2;)
	int operator+(int x) {
		return nr_pomi + x;
	}

	//op. +  (ex: cout<<s4+s3;)
	Mar operator+(Mar& mar) {
		Mar aux(*this);

		aux.soi = aux.soi + "-" + mar.soi;

		return aux;
	}

	//op. + (ex: cout<<10+s3;)
	friend int operator+(int x, Mar& mar) {
		return x + mar.nr_pomi;
	}

	//op += (s5+=3;)
	void operator+=(int c) {
		nr_pomi += c;
	}

	bool operator==(Mar& m) {

		if (this == &m) {
			return true;
		}

		return Pom_Fructifer::operator==(m) &&
			this->nr_pomi == m.nr_pomi &&
			this->soi == m.soi;
	}

	bool operator!() {
		return !getAltoit();
	}

	//operator functie ()
	void operator()(int pret) {
		if (pret >= 2 && pret <= 8) {
			for (int i = 0; i < getNumar_preturi(); i++) {
				if (getLista_preturi()[i] + pret <= 20)
					crestere_preturi(getLista_preturi(), i, getLista_preturi()[i] + pret);
			}
		}
		else {
			throw ExceptieCustomOperatorFunctie();
		}
	}

	//operator index
	double& operator[](int index) {
		if (index >= 0 && index < getNumar_preturi()) {
			return getLista_preturi()[index];
		}
		else {
			throw ExceptieCustomOperatorIndex();
		}
	}

	//operator cast - implicit si explicit
	operator int() {
		return nr_pomi;
	}

	//operator '--' - pre-decrementare
	const Mar& operator--() {

		nr_pomi--;
		return *this;
	}

	//operator '--' - post-decrementare
	const Mar operator--(int) {
		Mar aux(*this);
		nr_pomi--;
		return aux;
	}

	//operatori binari
	//op. - (ex: cout<<s5-2;)
	int operator-(int x) {
		return nr_pomi - x;
	}

	//op. - (ex: cout<< 10-s3;)
	friend int operator-(int x, Mar& mar) {

		return x - mar.nr_pomi;
	}

	//op -= (s5-=3;)
	void operator-=(int c) {
		nr_pomi -= c;
	}

	//operator * 
	double operator*(Mar& mar) {
		return this->getPret_cost() * mar.getPret_cost();
	}

	//op *= (s5*=3;)
	void operator*=(int c) {
		nr_pomi *= c;
	}

	int operator%(Mar& mar) {
		return  this->nr_pomi % mar.nr_pomi;
	}

	double operator/(Mar& mar) {

		return  this->getPret_cost() / mar.getPret_cost();
	}

	//op /= (s5/=3;)
	void operator/=(int c) {
		nr_pomi /= c;
	}

	//operator >>
	friend istream& operator>>(istream& inn, Mar& mar) {
		operator>>(inn, (Pom_Fructifer&)mar);
		cout << "Numar de pomi: "; inn >> mar.nr_pomi;
		cout << "Soi: ";
		inn.ignore(); getline(inn, mar.soi);

		return inn;
	}

	bool operator<(Mar cmp) {
		return this->getVartsa() < cmp.getVartsa();
	}

	bool operator>(Mar cmp) {
		return this->getVartsa() > cmp.getVartsa();
	}

	void scrieInFisierBinar(ofstream& fisBin) {
		Pom_Fructifer::scrieInFisierBinar(fisBin);
		fisBin.write((char*)&this->nr_pomi, sizeof(this->nr_pomi));
		int dim = soi.size() + 1;
		fisBin.write((char*)&dim, sizeof(dim));
		fisBin.write(this->soi.c_str(), dim);
	}

	void citireDinFisierBinar(ifstream& fisBin) {
		Pom_Fructifer::citireDinFisierBinar(fisBin);
		fisBin.read((char*)&this->nr_pomi, sizeof(this->nr_pomi));
		int dim = 0;
		fisBin.read((char*)&dim, sizeof(dim));
		char aux[100];
		fisBin.read(aux, dim);
		soi = aux;
	}

};

class Cires : public Pom_Fructifer {
	string anotimp;
	string soi;
public:
	Cires() :Pom_Fructifer() {
		this->anotimp = "---anotimpul nu este setat---";
		this->soi = "--- numele soiului nu este setat---";
	}

	Cires(const char* name, int vrst, bool alt, double cant, double pret_cost, int nr, double* lst, string ant, string soi)
		: Pom_Fructifer(name, vrst, alt, cant, pret_cost, nr, lst) {
		if (ant.empty()) {
			throw new exception("Numele anotimpului este gol\n");
		}
		else {
			this->anotimp = ant;
		}

		if (soi.empty()) {
			throw new exception("Numele soiului este gol\n");
		}
		else {
			this->soi = soi;
		}
	}

	Cires(int vrst, bool alt, double cant, double pret_cost, int nr, double* lst, string ant, string soi)
		: Pom_Fructifer(vrst, alt, cant, pret_cost, nr, lst) {
		if (ant.empty()) {
			throw new exception("Numele anotimpului este gol\n");
		}
		else {
			this->anotimp = ant;
		}

		if (soi.empty()) {
			throw new exception("Numele soiului este gol\n");
		}
		else {
			this->soi = soi;
		}
	}

	Cires(const Cires& crs) :Pom_Fructifer(crs) {
		this->anotimp = crs.anotimp;
		this->soi = crs.soi;
	}

	~Cires() {  }

	Cires& operator=(const Cires& crs) {
		if (this != &crs) {
			Pom_Fructifer::operator=(crs);
			this->anotimp = crs.anotimp;
			this->soi = crs.soi;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Cires& crs) {
		operator<<(out, (Pom_Fructifer&)crs);
		out << ",cirese de " << crs.anotimp << " ,soiul fiind " << crs.soi << endl;

		return out;
	}

	void administrareCalciu() {
		cout << "Fiecare cires(pom) a primit 30ml de calciu\n";
	}
};

class Prun : public Pom_Fructifer {
	string culoare_piele;// Pot avea pielea de culoare neagră, violetă, roșie sau galbenă.
	string soi;
public:
	Prun() :Pom_Fructifer() {
		this->culoare_piele = "---culoarea nu este setata---";
		this->soi = "--- numele soiului nu este setat---";
	}

	Prun(const char* name, int vrst, bool alt, double cant, double pret_cost, int nr, double* lst, string culoare_piele, string soi)
		: Pom_Fructifer(name, vrst, alt, cant, pret_cost, nr, lst) {
		if (culoare_piele.empty()) {
			throw new exception("Sirul este gol! \n");
		}
		else {
			this->culoare_piele = culoare_piele;
		}

		if (soi.empty()) {
			throw new exception("Numele soiului este gol\n");
		}
		else {
			this->soi = soi;
		}
	}

	Prun(int vrst, bool alt, double cant, double pret_cost, int nr, double* lst, string culoare_piele, string soi)
		: Pom_Fructifer(vrst, alt, cant, pret_cost, nr, lst) {
		if (culoare_piele.empty()) {
			throw new exception("Sirul este gol!\n");
		}
		else {
			this->culoare_piele = culoare_piele;
		}

		if (soi.empty()) {
			throw new exception("Numele soiului este gol\n");
		}
		else {
			this->soi = soi;
		}
	}

	Prun(const Prun& prun) :Pom_Fructifer(prun) {
		this->culoare_piele = prun.culoare_piele;
		this->soi = prun.soi;
	}

	~Prun() {  }

	Prun& operator=(const Prun& prun) {
		if (this != &prun) {
			Pom_Fructifer::operator=(prun);
			this->culoare_piele = prun.culoare_piele;
			this->soi = prun.soi;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Prun& prun) {
		operator<<(out, (Pom_Fructifer&)prun);
		out << ",prune de culoare " << prun.culoare_piele << " ,soiul fiind " << prun.soi << endl;

		return out;
	}

	void administrareCalciu() {
		cout << "Fiecare prun(pom) a primit 20ml de calciu\n";
	}
};

class Interfata_Livada {
public:
	virtual void adaugaSoi_de_Mar(Mar mar) = 0;
	virtual void stergeSoi_de_Mar(Mar mar) = 0;
};

class Livada : public Interfata_Livada {
	string Denumire_Livada;
	Mar* mere;
	int nr_meri;
public:
	Livada() {
		this->Denumire_Livada = "--nu este setata denumirea livezi--";
		this->mere = nullptr;
		this->nr_meri = 0;
	}

	Livada(string denumire, Mar* merele, int nrmeri) {
		if (denumire.empty()) {
			throw new exception("Sir invalid !");
		}
		else {
			this->Denumire_Livada = denumire;
		}

		if (nrmeri <= 0) {
			throw new exception("Numar invalid!");
		}
		else {
			this->nr_meri = nrmeri;
		}

		if (merele == nullptr) {
			throw new exception("Vectorul de mere nu este valid !");
		}
		else {
			this->mere = new Mar[nrmeri];
			for (int i = 0; i < nrmeri; i++) {
				this->mere[i] = merele[i];
			}
		}
	}

	Livada(const Livada& liv) {
		this->Denumire_Livada = liv.Denumire_Livada;
		this->nr_meri = liv.nr_meri;
		this->mere = new Mar[liv.nr_meri];
		for (int i = 0; i < liv.nr_meri; i++) {
			this->mere[i] = liv.mere[i];
		}
	}

	Livada& operator=(const Livada& liv) {
		if (this != &liv) {
			if (this->mere != nullptr) {
				delete[] this->mere;
			}
			this->Denumire_Livada = liv.Denumire_Livada;
			this->nr_meri = liv.nr_meri;
			this->mere = new Mar[liv.nr_meri];
			for (int i = 0; i < liv.nr_meri; i++) {
				this->mere[i] = liv.mere[i];
			}
		}
		return *this;
	}

	~Livada() {
		if (this->mere != nullptr) {
			delete[] this->mere;
		}
	}

	friend ostream& operator<<(ostream& ost, const Livada& liv) {
		ost << "Livada " << liv.Denumire_Livada << " are " << liv.nr_meri << " meri :" << endl;

		for (int i = 0; i < liv.nr_meri; i++) {
			ost << liv.mere[i] << endl;
		}
		return ost;
	}

	void adaugaSoi_de_Mar(Mar mar) {
		Mar* aux = new Mar[nr_meri + 1];
		for (int i = 0; i < nr_meri; i++) {
			aux[i] = mere[i];
		}

		aux[nr_meri++] = mar;
		delete[] mere;
		mere = aux;
	}

	void stergeSoi_de_Mar(Mar mar) {
		int nr_copie = 0;
		for (int i = 0; i < nr_meri; i++) {
			if (this->mere[i] == mar) {
				nr_copie++;
			}
		}

		if (nr_copie > 0) {
			for (int i = 0; i < nr_meri; i++) {
				if (this->mere[i] == mar) {
					for (int j = i; j < nr_meri - 1; j++) {
						this->mere[j] = mere[j + 1];
					}
					nr_meri--;
				}
			}

			Mar* aux = new Mar[nr_meri];
			for (int i = 0; i < nr_meri; i++) {
				aux[i] = mere[i];
			}

			delete[] mere;
			mere = aux;
		}
	}

	friend ofstream& operator<<(ofstream& ost, const Livada& liv) {
		int dimensiune = liv.Denumire_Livada.size() + 1;
		ost.write((char*)&dimensiune, sizeof(dimensiune));
		ost.write(liv.Denumire_Livada.c_str(), dimensiune);

		ost.write((char*)&liv.nr_meri, sizeof(liv.nr_meri));

		for (int i = 0; i < liv.nr_meri; i++) {
			liv.mere[i].scrieInFisierBinar(ost);
		}

		return ost;
	}

	friend ifstream& operator>>(ifstream& inn, Livada& liv) {
		int dimensiune = 0;
		inn.read((char*)&dimensiune, sizeof(dimensiune));

		char aux[100];
		inn.read(aux, dimensiune);
		liv.Denumire_Livada = aux;

		inn.read((char*)&liv.nr_meri, sizeof(liv.nr_meri));

		if (liv.mere != nullptr) {
			delete[] liv.mere;
		}

		liv.mere = new Mar[liv.nr_meri];
		for (int i = 0; i < liv.nr_meri; i++) {
			liv.mere[i].citireDinFisierBinar(inn);
		}

		return inn;
	}
};

class Livaadaa : private Interfata_Livada {
	string Denumire_Livada;
	vector<Mar> mere;
public:
	Livaadaa() {
		this->Denumire_Livada = "--nu este setata denumirea livezi--";
		mere.empty();
	}

	Livaadaa(string denumire, vector<Mar> merele) {
		if (denumire.empty()) {
			throw new exception("Sir invalid !");
		}
		else {
			this->Denumire_Livada = denumire;
		}

		if (merele.empty()) {
			throw new exception("Vectorul de mere nu este valid !");
		}
		else {
			this->mere.clear();
			for (int i = 0; i < merele.size(); i++) {
				this->mere.push_back(merele[i]);
			}
		}
	}

	Livaadaa(const Livaadaa& liv) {
		this->Denumire_Livada = liv.Denumire_Livada;
		this->mere.clear();
		for (int i = 0; i < liv.mere.size(); i++) {
			this->mere.push_back(liv.mere[i]);
		}
	}

	Livaadaa& operator=(const Livaadaa& liv) {
		if (this != &liv) {
			this->Denumire_Livada = liv.Denumire_Livada;
			this->mere.clear();
			for (int i = 0; i < liv.mere.size(); i++) {
				this->mere.push_back(liv.mere[i]);
			}
		}
		return *this;
	}

	~Livaadaa() { mere.clear(); }

	friend ostream& operator<<(ostream& ost, const Livaadaa& liv) {
		ost << "Livada " << liv.Denumire_Livada << " are " << liv.mere.size() << " meri :" << endl;

		for (int i = 0; i < liv.mere.size(); i++) {
			ost << liv.mere[i] << endl;
		}
		return ost;
	}

	void adaugaSoi_de_Mar(Mar mar) {
		this->mere.push_back(mar);
	}

	void stergeSoi_de_Mar(Mar mar) {
		for (int i = 0; i < mere.size(); i++) {
			if (this->mere[i] == mar) {
				mere.erase(mere.begin() + i);
			}
		}
	}

	friend ofstream& operator<<(ofstream& ost, Livaadaa& liv) {
		int dimensiune = liv.Denumire_Livada.size() + 1;
		ost.write((char*)&dimensiune, sizeof(dimensiune));
		ost.write(liv.Denumire_Livada.c_str(), dimensiune);

		int x = liv.mere.size();
		ost.write((char*)&x, sizeof(int));

		for (int i = 0; i < liv.mere.size(); i++) {
			liv.mere[i].scrieInFisierBinar(ost);
		}

		return ost;
	}

	friend ifstream& operator>>(ifstream& inn, Livaadaa& liv) {
		int dimensiune = 0;
		inn.read((char*)&dimensiune, sizeof(dimensiune));

		char aux[100];
		inn.read(aux, dimensiune);
		liv.Denumire_Livada = aux;

		int x;
		inn.read((char*)&x, sizeof(int));
		
		liv.mere.resize(x);
		for (int i = 0; i < x; i++) {
			liv.mere[i].citireDinFisierBinar(inn);
		}

		return inn;
	}
};

int main() {
	//aici am facut teste pe clasa parinte inainte sa fie transformata in clasa abstracta;
	/*Pom_Fructifer p1;
	cout << p1<<endl;

	double v[] = { 5.5, 6.5, 7.5 };
	Pom_Fructifer p2("Mar", 6, 1, 10000, 3.5, sizeof(v) / sizeof(v[0]), v);

	double f[] = { 10.2, 9.4, 12.5 };
	Pom_Fructifer p3( 6, 1, 20000, 5.5, sizeof(v) / sizeof(v[0]), v);

	Pom_Fructifer copiere=p2;

	p3 = p1;
	cout << p1;

	cout << endl << p2<<endl;
	cout << endl << p3<<endl;
	cout << endl << copiere<<endl;

	cout << p2.getNume()<<endl;
	cout << p2.getVartsa()<<endl;
	cout << (p2.getAltoit() ? " da " : " nu ") << endl;
	cout << p2.getCantitate()<<endl;
	cout << p2.getPret_cost()<<endl;
	cout << p2.getNumar_preturi()<<endl;
	for (int i = 0; i < p2.getNumar_preturi(); i++) {
		cout << p2.getLista_preturi()[i]<<"  ";
	}*/

	double preturi_mere0[] = { 12.5, 10.4, 30.5 };
	Mar ma("Mar verde", 5, 1, 500, 4.3, sizeof(preturi_mere0) / sizeof(preturi_mere0[0]), preturi_mere0, 50, "Slav");
	Mar m(5, 1, 500, 4.3, sizeof(preturi_mere0) / sizeof(preturi_mere0[0]), preturi_mere0, 50, "Uimitor");
	Mar m1;
	cout << m1 << endl << m << endl << ma << endl << endl;


	double preturi_cirese0[] = { 50.5,69.9,120.8 };
	Cires cr("Cires", 6, 1, 1000, 10.5, sizeof(preturi_cirese0) / sizeof(preturi_cirese0[0]), preturi_cirese0, "vara", "Rubin");
	Cires crs(6, 1, 1000, 10.5, sizeof(preturi_cirese0) / sizeof(preturi_cirese0[0]), preturi_cirese0, "vara", "Silva");
	Cires c1;
	cout << c1 << endl << crs << endl << cr << endl << endl;

	double preturi_prune0[] = { 13.9,18.5,19.7 };
	Prun pr("Prun", 8, 1, 1500, 6.9, sizeof(preturi_prune0) / sizeof(preturi_prune0[0]), preturi_prune0, "negru", "Moyer");
	Prun prn(8, 1, 1500, 6.9, sizeof(preturi_prune0) / sizeof(preturi_prune0[0]), preturi_prune0, "violet", "Common Damson");
	Prun p1;
	cout << p1 << endl << prn << endl << pr << endl;

	cout << "------------------------------ Supraincarcare operatori ++, +, += ------------------------------\n";

	//supraincarcare operatori pentru clasa Mar
	//operator ++ pre-incrementare pentru nr_pomi;
	cout << "operator ++ pre-incrementare pentru numar pomi: " << endl << ++ma << endl;

	//operator ++ post-incrementare pentru nr_pomi;
	cout << "operator ++ post-incrementare pentru numar pomi: " << endl << ma++ << endl;

	//operator + (ex: cout<<ma+30;) pentru nr_pomi;
	cout << "operator + (ex: cout<<ma+30;) pentru numar pomi: " << endl << ma + 30 << endl;

	//operator +  (ex: cout<<ma+m;) pentru tip soi;
	cout << "\noperator + (ex: cout<<ma+m;) pentru tip soi: " << endl << ma + m << endl;

	//operator + (ex: cout<<100+ma;) pentru nr_pomi;
	cout << "operator + (ex: cout<<100+ma;) pentru numar pomi: " << endl << 100 + ma << endl;

	//operator +=
	ma += 10;
	cout << "\noperator += (ex: ma+=10;) pentru numar pomi: " << endl << ma << endl;

	cout << "------------------------------ Supraincarcare operatori ==, !, (), [], cast ------------------------------\n";

	//operator ==
	cout << "operator == intre ma si m ";
	if (ma == m) {
		cout << endl << "ma==m" << endl;
	}
	else {
		cout << endl << "ma!=m" << endl;
	}

	Mar test123("Mar verde", 5, 1, 500, 4.3, sizeof(preturi_mere0) / sizeof(preturi_mere0[0]), preturi_mere0, 50, "SLAV");
	Mar test321("Mar galben", 7, 1, 800, 3.9, sizeof(preturi_mere0) / sizeof(preturi_mere0[0]), preturi_mere0, 50, "Uimitor");
	Mar test231("Mar verde", 5, 1, 500, 4.3, sizeof(preturi_mere0) / sizeof(preturi_mere0[0]), preturi_mere0, 50, "Slav");

	cout << "\noperator == intre test123 si test321 ";
	if (test123 == test231) {
		cout << endl << "test123==test231" << endl;
	}
	else {
		cout << endl << "test123!=test231" << endl;
	}

	//operator !

	cout << "\noperator ! pentru test123 ";
	if (!test123) {
		cout << "\nEste altoit! \n";
	}
	else {
		cout << "\nNu este altoit! \n";
	}

	//operator frunctie
	test123(5);
	cout << "\noperator functie penru crestere pret: \n" << test123 << "\n";

	//operator index
	cout << "operator index: [] " << test123[1] << "\n";

	//operator cast explicit
	cout << "\ncast explicit:  (int)test123 =>   " << (int)test123 << "\n";

	//operator cast implicit
	int nr_pomi = test123;
	cout << "\ncast implicit:  nr_pomi=   " << nr_pomi << "\n";

	cout << "------------------------------ Supraincarcare operatori --, -, -= ------------------------------\n";
	//operator -- pre-decrementare pentru nr_pomi;
	cout << "operator -- pre-decrementare pentru numar pomi: " << endl << --ma << endl;

	//operator -- post-decrementare pentru nr_pomi;
	cout << "operator -- post-decrementare pentru numar pomi: " << endl << ma-- << endl;

	//operator - (ex: cout<<ma-30;) pentru nr_pomi;
	cout << "operator - (ex: cout<<ma-30;) pentru numar pomi: " << endl << ma - 30 << endl;

	//operator - (ex: cout<<100-ma;) pentru nr_pomi;
	cout << "operator - (ex: cout<<100-ma;) pentru numar pomi: " << endl << 100 - ma << endl;

	//operator -=
	ma -= 10;
	cout << "\noperator -= (ex: ma-=10;) pentru numar pomi: " << endl << ma << endl;

	//operator * 
	cout << "operator * pentru pret cost intre test123 si test321 => " << test123 * test321 << endl;

	//operator *=
	ma *= 10;
	cout << "\noperator *= (ex: ma*=10;) pentru numar pomi: " << endl << ma << endl;

	//operator %
	cout << "operator % => restul impartiri pentru numar de meri este:  " << test321 % test123 << endl;

	//operator /
	cout << "\noperator / pentru pret cost intre test123 si test321 => " << test123 / test321 << endl;

	//operator /=
	ma /= 10;
	cout << "\noperator /= (ex: ma/=10;) pentru numar pomi: " << endl << ma << endl;

	cout << "------------------------------ Supraincarcare operatori > , < ------------------------------\n";
	if (test123 < test321) {
		cout << test123.getNume() << " este mai tanar decat " << test321.getNume()<<endl;
	}
	else {
		cout << test123.getNume() << " este mai batran decat " << test321.getNume()<<endl;
	}

	////operator >> 
	//cout << "------------------------------ Supraincarcare >> ------------------------------\n";
	//Mar i;
	//cin >> i;
	//cout << i;

	//clasa cu Compunere
	cout << "\n------------------------------ CLASA CU COMPUNERE ------------------------------\n";
	double preturi_mere1[] = { 8.4, 9.5, 10.4 };
	Mar compunere("Mar golden", 4, 0, 400, 4.9, sizeof(preturi_mere1) / sizeof(preturi_mere1[0]), preturi_mere1, 70, "Golden Delicious");

	Livada lvd("Voinesti", new Mar[]{ test321 }, 1);
	lvd.adaugaSoi_de_Mar(ma);
	lvd.adaugaSoi_de_Mar(compunere);
	cout << lvd << endl;

	lvd.stergeSoi_de_Mar(test321);
	cout << lvd << endl;

	cout << "------------------------------ Exceptii Custom ------------------------------\n";
	cout << "Exceptie pentru operatorul functie (): \n";
	try {
		test123(10);
	}
	catch (ExceptieCustomOperatorFunctie f) {
		cout << f.what() << endl;
	}

	cout << "Exceptie pentru operatorul index []: \n";
	try {
		test123[100];
	}
	catch (ExceptieCustomOperatorIndex i) {
		cout << i.what() << endl;
	}

	cout << "------------------------------ SCRIERE SI CITIRE FISIER BINAR ------------------------------\n";

	ofstream FisierBinarLivadaOut("test.bin", ios::out | ios::binary | ios::app);
	if (FisierBinarLivadaOut.is_open()) {
		FisierBinarLivadaOut << lvd;
		FisierBinarLivadaOut.close();
	}
	else {
		cout << "Fisierul test.bin nu poate fi deschis pentru scrire\n ";

	}

	Livada livadaprint;
	ifstream FisierBinarLivadaIn("test.bin", ios::in | ios::binary);
	if (FisierBinarLivadaIn.is_open()) {
		FisierBinarLivadaIn >> livadaprint;
		cout << endl << livadaprint << endl;
		FisierBinarLivadaIn.close();
	}
	else {
		cout << "Fisierul test.bin nu poate fi deschis pentru citire\n ";

	}

	cout << "------------------------------ CLASA COMPUSA FOLOSIND VECTOR STL IN CREARE ------------------------------\n";

	vector<Mar> merele; merele.push_back(test123); 
	Livaadaa lvd2("Voinesti", merele);
	lvd2.adaugaSoi_de_Mar(ma);
	lvd2.adaugaSoi_de_Mar(compunere);
	lvd2.stergeSoi_de_Mar(test123);

	cout << lvd2;

	vector<Mar> gmerele; gmerele.push_back(test321);
	Livaadaa lvdd("Gemenea", gmerele);
	lvdd.adaugaSoi_de_Mar(test231);
	lvdd.adaugaSoi_de_Mar(ma);

	cout << "------------------------------ SCRIERE SI CITIRE FISIER BINAR A CLASEI COMPUSE CU AJUTORUL STL------------------------------\n";

	ofstream FisierBinarLivadaOut2("stl.bin", ios::out | ios::binary | ios::app);
	if (FisierBinarLivadaOut2.is_open()) {
		FisierBinarLivadaOut2 << lvd2;
		FisierBinarLivadaOut2.close();
	}
	else {
		cout << "Fisierul stl.bin nu poate fi deschis pentru scrire\n ";

	}

	Livaadaa livadaprint2;
	ifstream FisierBinarLivadaIn2("stl.bin", ios::in | ios::binary);
	if (FisierBinarLivadaIn2.is_open()) {
		FisierBinarLivadaIn2 >> livadaprint2;
		cout << endl << livadaprint2 << endl;
		FisierBinarLivadaIn2.close();
	}
	else {
		cout << "Fisierul stl.bin nu poate fi deschis pentru citire\n ";

	}

	cout << "------------------------------ Vector STL de clasa compusa  ------------------------------\n";

	vector<Livaadaa> liv;
	liv.push_back(lvdd);
	liv.push_back(lvd2);

	for (Livaadaa fruct : liv) {
		cout << fruct << "\n";
	}

	cout << "------------------------------ Early Binding ------------------------------\n";
	ma.administrareCalciu();
	cr.administrareCalciu();
	pr.administrareCalciu();

	cout << "\n";
	cout << "------------------------------ Late Binding ------------------------------\n";
	Pom_Fructifer* pom = &ma;
	pom->administrareCalciu();

	pom = &cr;
	pom->administrareCalciu();

	pom = &pr;
	pom->administrareCalciu();

	cout << "\n------------------------------ Polimorfism ------------------------------\n";
	Pom_Fructifer* p;

	Mar mar_poli("Mar poli", 5, 1, 1000, 3.5, sizeof(preturi_mere1) / sizeof(preturi_mere1[0]), preturi_mere1, 80, "Golden");
	p = &mar_poli;
	p->administrareCalciu();
	cout << "---:: " << (*p);
	cout << endl<<endl;

	Cires cires_poli("Cires poli", 6, 1, 4000, 6.5, sizeof(preturi_cirese0) / sizeof(preturi_cirese0[0]), preturi_cirese0, "Vara", "Silva");
	p = &cires_poli;
	p->administrareCalciu();
	cout << "---:: " << (*p);
	cout << endl<<endl;

	Prun prun_poli("Prun poli", 8, 0, 3000, 4.2, sizeof(preturi_prune0) / sizeof(preturi_prune0[0]), preturi_prune0, "neagra", "Moyer");
	p = &prun_poli;
	p->administrareCalciu();
	cout << "---:: " << (*p);
	cout << endl<<endl;

	cout << "Colectie de pointeri: \n";
	vector<Pom_Fructifer*> vect;
	vect.push_back(&mar_poli);
	vect.push_back(&cires_poli);
	vect.push_back(&prun_poli);
	
	for (Pom_Fructifer* pom : vect) {
		(*pom).administrareCalciu();
	}

	return 0;
}
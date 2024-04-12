#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;

public:
   
    Data() : dia(0), mes(0), ano(0) {}

    Data(int d, int m, int a) : dia(d), mes(m), ano(a) {}

   
    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAno() const { return ano; }
};

class Contato {
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

public:
    Contato() {}

    
    Contato(string em, string nm, string tel, Data dt) : email(em), nome(nm), telefone(tel), dtnasc(dt) {}

    
    string getEmail() const { return email; }
    string getNome() const { return nome; }
    string getTelefone() const { return telefone; }
    Data getDataNascimento() const { return dtnasc; }


    int idade() const {
        time_t now = time(0);
        tm *localTime = localtime(&now);
        int anoAtual = 1900 + localTime->tm_year;
        return anoAtual - dtnasc.getAno();
    }
};

int main() {
	const int MAX_INFO = 5; 
    int num_infos;

    cout << "Quantas informacoes voce deseja inserir? (maximo de " << MAX_INFO << "): ";
    cin >> num_infos;
    cin.ignore(); 
    
    
    while (num_infos > MAX_INFO || num_infos <= 0 ) {
        cout << "Voce nao pode inserir mais do que " << MAX_INFO << " informacoes. tente novamente: ";
        cin >> num_infos;
        cin.ignore(); 
		    }
    
     system("cls");
     
    Contato contatos[num_infos];

    
    for (int i = 0; i < num_infos; ++i) {
       string email, nome, telefone;
        int dia, mes, ano;

        cout << "Digite o nome do contato " << i + 1 << ": ";
        getline(cin, nome);
        cout << "Digite o email do contato " << i + 1 << ": ";
        getline(cin, email);
        cout << "Digite o telefone do contato " << i + 1 << ": ";
        getline(cin, telefone);
        cout << "Digite a data de nascimento do contato " << i + 1 << " (DD MM AAAA): ";
        cin >> dia >> mes >> ano;
        cin.ignore(); 

        contatos[i] = Contato(email, nome, telefone, Data(dia, mes, ano));
    }
    
    system("cls");

    
    cout << "\nLista de Contatos:" << endl;
    for (int i = 0; i < num_infos; ++i) {
        cout << "Nome: " << contatos[i].getNome() << endl;
        cout << "Email: " << contatos[i].getEmail() << endl;
        cout << "Telefone: " << contatos[i].getTelefone() << endl;
        cout << "Idade: " << contatos[i].idade() << " anos" << endl;
        cout << "-----------------------" << endl;
    }

    return 0;

	
	}


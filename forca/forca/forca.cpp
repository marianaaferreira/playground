#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

void desenho(int tentativas) {
    switch (tentativas) {
        case 6:
            cout << "   +-------+ " << endl;
            cout << "   |       | " << endl;
            cout << "           | " << endl;
            cout << "           | " << endl;
            cout << "           | " << endl;
            cout << "           | " << endl;
            cout << "-------------" << endl;
            break;
        case 5:
            cout << "   +-------+ " << endl;
            cout << "   |       | " << endl;
            cout << "   O       | " << endl;
            cout << "           | " << endl;
            cout << "           | " << endl;
            cout << "           | " << endl;
            cout << "-------------" << endl;
            break;
        case 4:
            cout << "   +-------+ " << endl;
            cout << "   |       | " << endl;
            cout << "   O       | " << endl;
            cout << "   |       | " << endl;
            cout << "           | " << endl;
            cout << "           | " << endl;
            cout << "-------------" << endl;
            break;
        case 3:
            cout << "   +-------+ " << endl;
            cout << "   |       | " << endl;
            cout << "   O       | " << endl;
            cout << "  /|       | " << endl;
            cout << "           | " << endl;
            cout << "           | " << endl;
            cout << "-------------" << endl;
            break;
        case 2:
            cout << "   +-------+ " << endl;
            cout << "   |       | " << endl;
            cout << "   O       | " << endl;
            cout << "  /|\\      | " << endl;
            cout << "           | " << endl;
            cout << "           | " << endl;
            cout << "-------------" << endl;
            break;
        case 1:
            cout << "   +-------+ " << endl;
            cout << "   |       | " << endl;
            cout << "   O       | " << endl;
            cout << "  /|\\      | " << endl;
            cout << "  /        | " << endl;
            cout << "           | " << endl;
            cout << "-------------" << endl;
            break;
        case 0 :
            cout << "   +-------+ " << endl;
            cout << "   |       | " << endl;
            cout << "   O       | " << endl;
            cout << "  /|\\      | " << endl;
            cout << "  / \\      | " << endl;
            cout << "           | " << endl;
            cout << "-------------" << endl;
    }
}

string escolhePalavraAleatoria() {
    int indice;
    vector<string> palavras = {
        "torta", "crepusculo", "efemero",
        "labirinto", "quimera", "horizonte",
        "nostalgia", "finito", "abobora",
        "vertigem", "aurora", "paradoxo",
        "melancolia", "sussurro"
    };
    srand(time(0));
    indice = rand() % palavras.size();
    return palavras.at(indice);
}

int main() {
    int indice, tentativaPalavra = 3, tentativaLetra = 6;
    bool acertou = 0, resp;
    char letra;
    string chute, palavra;
    vector<char> palavracript;
    
    palavra = escolhePalavraAleatoria();

    cout << "Advinhe a seguinte palavra:" << endl;
    for (int i = 0; i < palavra.size(); i++) {
        cout << "* ";
    }
    cout << endl << endl;

    for (int i = 0; i < palavra.size(); i++)
        palavracript.push_back('*');

    while (not acertou and tentativaPalavra > 0 and tentativaLetra > 0) {
        desenho(tentativaLetra);
        cout << "Diga uma letra (Voce tem mais " << tentativaLetra << " tentaivas):"; tentativaLetra--;
        cin >> letra;
        cin.ignore(); 

        for (int i = 0; i < palavra.size(); i++) {
            if (palavra[i] == letra) {
                palavracript[i] = letra;  
            }
        }

        for (const auto& caractere : palavracript)
            cout << caractere << " ";
        cout << endl;

        acertou = 1;
        for (const auto& caractere : palavracript)
            if (caractere == '*') acertou = 0;
      
        if (not acertou) {
            cout << "Deseja dar algum palpite? (Voce tem apenas " << tentativaPalavra << " tentativa(s) restantes) Sim[1] Nao [0]" << endl;
            cin >> resp;
            cin.ignore();

            if (resp) {
                cout << "Digite seu palpite: ";
                getline(cin, chute);
                tentativaPalavra--;
                if (chute == palavra) {
                    cout << "Parabens, voce acertou!!!" << endl;
                    acertou = true;
                }
                else {
                    cout << "Palpite incorreto." << endl;
                }
            }
        }
        else {
            cout << "Parabens, voce acertou!!!";
        }
    }

    if (!acertou) {
        cout << "Suas tentativas acabaram! A palavra correta era: " << palavra << endl;
    }

    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

class Employe {
public:
    int Matricule;
    std::string Nom;
    std::string Prenom;
    std::string DateNaissance;
    std::string DateEmbauche;
    double Salaire;

    Employe(int matricule, const std::string& nom, const std::string& prenom, const std::string& dateNaissance, const std::string& dateEmbauche, double salaire)
        : Matricule(matricule), Nom(nom), Prenom(prenom), DateNaissance(dateNaissance), DateEmbauche(dateEmbauche), Salaire(salaire) {}

    int Age() const {
        int currentYear = 2023;  // Assuming the current year is 2023
        int birthYear = std::stoi(DateNaissance.substr(6, 4));
        return currentYear - birthYear;
    }

    int Anciennete() const {
        int currentYear = 2023;  // Assuming the current year is 2023
        int hireYear = std::stoi(DateEmbauche.substr(6, 4));
        return currentYear - hireYear;
    }

    void AugmentationDuSalaire() {
        int anciennete = Anciennete();
        if (anciennete < 5) {
            Salaire *= 1.02;  // 2%
        } else if (anciennete < 10) {
            Salaire *= 1.05;  // 5%
        } else {
            Salaire *= 1.1;   // 10%
        }
    }

    void AfficherEmploye() const {
        std::cout << "Matricule : " << Matricule << std::endl;
        std::cout << "Nom complet : " << Nom << " " << Prenom << std::endl;
        std::cout << "Age : " << Age() << std::endl;
        std::cout << "Anciennete : " << Anciennete() << " ans" << std::endl;
        std::cout << "Salaire : " << Salaire << std::endl;
    }

    void SauvegarderDansFichier(const std::string& nomFichier) const {
        std::ofstream fichier(nomFichier, std::ios::app);

        if (fichier.is_open()) {
            fichier << Matricule << "," << Nom << "," << Prenom << "," << DateNaissance << "," << DateEmbauche << "," << Salaire << std::endl;
            fichier.close();
        } else {
            std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        }
    }
};

void ChargerDonneesDepuisFichier(const std::string& nomFichier, std::vector<Employe>& employes) {
    std::ifstream fichier(nomFichier);

    if (fichier.is_open()) {
        while (!fichier.eof()) {
            int matricule;
            std::string nom, prenom, dateNaissance, dateEmbauche;
            double salaire;

            fichier >> matricule;
            fichier.ignore();  // Ignore the comma
            std::getline(fichier, nom, ',');
            std::getline(fichier, prenom, ',');
            std::getline(fichier, dateNaissance, ',');
            std::getline(fichier, dateEmbauche, ',');
            fichier >> salaire;

            employes.emplace_back(matricule, nom, prenom, dateNaissance, dateEmbauche, salaire);
        }
        fichier.close();
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
    }
}

void SauvegarderDansFichier(const std::string& nomFichier, const Employe& employe) {
    std::ofstream fichier(nomFichier, std::ios::app);

    if (fichier.is_open()) {
        fichier << employe.Matricule << "," << employe.Nom << "," << employe.Prenom << ","
                << employe.DateNaissance << "," << employe.DateEmbauche << "," << employe.Salaire << std::endl;
        fichier.close();
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
    }
}

// Function to add a new employee to the list
void AjouterEmploye(std::vector<Employe>& employes) {
    int matricule;
    std::string nom, prenom, dateNaissance, dateEmbauche;
    double salaire;

    std::cout << "Entrez le matricule de l'employe : ";
    std::cin >> matricule;

    std::cout << "Entrez le nom de l'employe : ";
    std::cin >> nom;

    std::cout << "Entrez le prenom de l'employe : ";
    std::cin >> prenom;

    std::cout << "Entrez la date de naissance de l'employe (format JJ/MM/AAAA) : ";
    std::cin >> dateNaissance;

    std::cout << "Entrez la date d'embauche de l'employe (format JJ/MM/AAAA) : ";
    std::cin >> dateEmbauche;

    std::cout << "Entrez le salaire de l'employe : ";
    std::cin >> salaire;

    employes.emplace_back(matricule, nom, prenom, dateNaissance, dateEmbauche, salaire);

    // Save the new employee to the file
    SauvegarderDansFichier("employes.csv", employes.back());

    std::cout << "Employe ajoute avec succes." << std::endl;
}

// Function to search for an employee by Matricule
void RechercherParMatricule(const std::vector<Employe>& employes) {
    int matriculeRecherche;
    std::cout << "Entrez le matricule de l'employe a rechercher : ";
    std::cin >> matriculeRecherche;

    for (const auto& employe : employes) {
        if (employe.Matricule == matriculeRecherche) {
            std::cout << "Informations de l'employe trouve : " << std::endl;
            employe.AfficherEmploye();
            return;  // Exit the function once the employee is found
        }
    }

    std::cout << "Aucun employe trouve avec le matricule " << matriculeRecherche << "." << std::endl;
}

// Function to display the menu options
void AfficherMenu() {
    std::cout << "\nMenu :\n";
    std::cout << "1. Ajouter un employe\n";
    std::cout << "2. Rechercher un employe par matricule\n";
    std::cout << "3. Quitter\n";
    std::cout << "Choix : ";
}

int main() {
    std::vector<Employe> employes;

    // Load existing data from the file
    ChargerDonneesDepuisFichier("employes.csv", employes);

    int choix;
    do {
        AfficherMenu();
        std::cin >> choix;

        switch (choix) {
            case 1:
                AjouterEmploye(employes);
                break;
            case 2:
                RechercherParMatricule(employes);
                break;
            case 3:
                std::cout << "Fin du programme.\n";
                break;
            default:
                std::cout << "Choix invalide. Veuillez reessayer.\n";
        }
    } while (choix != 3);

    return 0;
}

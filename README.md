# Employee category


This C++ program for managing employee data. It includes a class Employe to represent employee information, functions to load and save data from/to a file, and a menu-driven main program allowing users to add new employees, search for employees by matricule, and exit the program.

## Employee Class:
- Attributes: Matricule, Nom, Prenom, DateNaissance, DateEmbauche, Salaire.
- Methods: Age(), Anciennete(), AugmentationDuSalaire(), AfficherEmploye(), SauvegarderDansFichier().

## Functions:
- `ChargerDonneesDepuisFichier`: Loads employee data from a file into a vector.
- `SauvegarderDansFichier`: Saves employee data to a file.
- `AjouterEmploye`: Adds a new employee to the vector and saves it to the file.
- `RechercherParMatricule`: Searches for an employee by Matricule and displays their information.
- `AfficherMenu: Displays` a menu for user interaction.

## Main Function:
- Initializes a vector of employees.
- Loads existing data from a file.
- Displays a menu for the user to add an employee, search by Matricule, or quit the program.

## Usage:

- The program reads and writes employee data to a file (`employes.csv`).
- Users can interact with the program by choosing options from the menu.

> [!NOTE]
> Ensure that the file "employes.csv" exists before running the program, and the data in the file should be formatted correctly (Matricule, Nom, Prenom, DateNaissance, DateEmbauche, Salaire).


## here are 10 example entries in the CSV format for the "employes.csv" file:
```
101,Smith,John,05/12/1980,03/20/2010,60000.00
202,Jones,Jane,08/18/1995,02/15/2018,70000.00
303,Williams,David,11/05/1982,09/10/2007,80000.00
404,Brown,Emily,03/22/1990,07/01/2015,55000.00
505,Johnson,Michael,06/15/1988,04/30/2012,65000.00
606,Davis,Susan,09/28/1993,01/05/2019,75000.00
707,Miller,Christopher,02/10/1985,08/15/2011,72000.00
808,Anderson,Amy,07/14/1987,06/22/2014,68000.00
909,Martin,Katherine,12/03/1992,11/10/2016,90000.00
1010,Clark,Richard,04/19/1984,10/25/2009,82000.00
```
## How if I want to view employee data?
```
Matricule : 156
Nom complet : employe156 employe156
Age : 31
Anciennete : 10 ans
Salaire : 15600
```

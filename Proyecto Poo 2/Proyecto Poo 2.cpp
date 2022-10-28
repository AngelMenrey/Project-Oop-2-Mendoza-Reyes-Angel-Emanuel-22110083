//ANGEL EMANUEL MENDOZA REYES 
//22110083
//GRUPO 2 O
//PROGRAMACION ORIENTADA A OBJETOS(POO)
//PARCIAL 2
//PROYECTO 2
//PROFESOR: LUIS MANUEL MORALES MEDINA 
//CETI COLOMOS 
//PAPERS PLEASE
#include <cstdlib>
#include <iostream> 
#include <time.h> 
#include <string>
#include <stdio.h>
#include <SFML/Audio.hpp>
#include <Windows.h>

using namespace std;

string formattedDateString(int, int);

class Document {
public:
    string ID;//ID DE LA PERSONA
    string name;//NOMBRE DE LA PERSONA
    string lastName;//APELLIDO DE LA PERSONA
    char   gender;//SEXO DE LA PERSONA
    string dateOfBirth;//FECHA DE NACIMIENTO DE LA PERSONA
    string CURP;//CURP
    string nationality;//NACIONALIDAD DE LA PERSONA
    virtual void show() = 0;
};
//HERENCIA
class Passport : public Document {
public:
    Passport(string ID, string name, string lastName, char gender, string dateOfBirth, string CURP, string nationality){//CONSTRUCTOR
        Document::ID = ID;
        Document::name = name;
        Document::lastName = lastName;
        Document::gender = gender;
        Document::dateOfBirth = dateOfBirth;
        Document::CURP = CURP;
        Document::nationality = nationality;
    }
    void show() {//IMPRIMIR EN CONSOLA LOS DATOS DEL PASAPORTE
        cout << "____________________________________________" << endl;
        cout << "PASAPORTE" << endl;
        cout << "____________________________________________" << endl;
        cout << "NUMERO DE PASAPORTE: " << ID << endl;
        cout << "____________________________________________" << endl;
        cout << "APELLIDOS: " << lastName << endl;
        cout << "____________________________________________" << endl;
        cout << "NOMBRE: " << name << endl;
        cout << "____________________________________________" << endl;
        cout << "FECHA DE NACIMIENTO: " << dateOfBirth << endl;
        cout << "____________________________________________" << endl;
        cout << "CURP: " << CURP << endl;
        cout << "____________________________________________" << endl;
        cout << "SEXO: " << gender << endl;
        cout << "____________________________________________" << endl;
        cout << "NACIONALIDAD: " << nationality << endl;
        cout << "____________________________________________" << endl;
    }
};
//HERENCIA
class INE : public Document {
public:
    INE(string ID, string name, string lastName, char gender, string dateOfBirth, string CURP,string nationality) {//CONSTRUCTOR
        Document::ID = ID;
        Document::name = name;
        Document::lastName = lastName;
        Document::gender = gender;
        Document::dateOfBirth = dateOfBirth;
        Document::CURP = CURP;
        Document::nationality = nationality;
    }
    
    void show() {//IMPRIMIR EN CONSOLA LOS DATOS DE LA INE
        cout << "____________________________________________" << endl;
        cout << "INE" << endl;
        cout << "____________________________________________" << endl;
        cout << "CLAVE DE ELECTOR: " << ID << endl;
        cout << "____________________________________________" << endl;
        cout << "NOMBRE: " << lastName << " " << name << endl;
        cout << "____________________________________________" << endl;
        cout << "SEXO: " << gender << endl;
        cout << "____________________________________________" << endl;
        cout << "CURP: " << CURP << endl;
        cout << "____________________________________________" << endl;
        cout << "FECHA DE NACIMIENTO: " << dateOfBirth << endl;
        cout << "____________________________________________" << endl;
        cout << "NACIONALIDAD: " << nationality << endl;
        cout << "____________________________________________" << endl;
    }
};
class Person {
public:
    Document* documents[2];//GUARDA EL PASAPORTE Y LA INE
    int status;//STATUS DE LA PERSONA: 1 = TODO CORRECTO | 2 = HAY UN ERROR
    bool terrorist;//TERRORISTA PUEDE SER TRUE O FALSE
    string reason;//RAZON POR LA CUAL SE PERDIO PUNTOS
    Person() {
        srand(time(0));//GENERA UNA NUEVA SEMILLA EN CADA LLAMADA DEL PROGRAMA
        string names[8] = { "Alex", "Ariel", "Charlie", "Cris", "Dani", "Denis", "Getsemani", "Zaid" };
        string lastNames[8] = { "Hernandez", "Garcia", "Lopez", "Martinez", "Gonzalez", "Perez", "Mora", "Campos" };
        string nationalities[5] = { "Mexicana","Argentina","Colombiana","Peruana","Cubana" };
        string name = names[rand() % 8];//NOMBRES EN ALEATORIO
        string lastName = lastNames[rand() % 8];//APELLIDOS EN ALEATORIO
        string secondLastName = lastNames[rand() % 8];//SEGUNDO APELLIDO EN ALEATORIO
        lastName += " " + secondLastName;//SE JUNTAN LOS APELLIDOS
        string nationality = nationalities[rand() % 5];
        char gender;
        if (rand() % 2 == 0) gender = 'F';//SEXO FEMENINO ALEATORIO
        else gender = 'M';//SEXO MASCULINO ALEATORIO
        string day = formattedDateString(28, 1);
        string month = formattedDateString(12, 1);
        string year = formattedDateString(103, 1900);
        string dateOfBirth = day + "/" + month + "/" + year;
        string CURP = lastName.substr(0, 1) + string(1, toupper(lastName.at(1))) + secondLastName.substr(0, 1) + name.substr(0, 1);
        CURP += year + month + day;
        CURP += string(1, gender) + "JCLRNA5";
        //CREACION DE LOS DOCUMENTOS
        documents[0] = new Passport("PAS" + CURP, name, lastName, gender, dateOfBirth, CURP, nationality);
        if (rand() % 2 == 0) {//CREAR DOCUMENTOS IGUALES
            documents[1] = new INE("INE" + CURP, name, lastName, gender, dateOfBirth, CURP, nationality);
            status = 1;//TODO CORRECTO
            terrorist = false;//LA PERSONA NO ES TERRORISTA
            reason = "LOS DATOS DE LA PERSONA SON CORRECTOS\n";
        }
        else {//GENERAR UN ERROR EN LOS DOCUMENTOS
            string identifiers[6] = { "NOMBRE", "APELLIDO", "GENERO", "NACIMIENTO", "CURP","NACIONALIDAD"};//SE GENERA ALGUN ERROR EN ALGUNOS DE ESTOS DATOS
            string tempIdentifier;
            int random = rand() % 6;
            switch (random) {
            case 0:
                do {
                    tempIdentifier = names[rand() % 8];//NUEVO NOMBRE
                } while (tempIdentifier == name);//OBTENER NUEVO NOMBRE
                name = tempIdentifier;//SE CAMBIA EL NOMBRE ACTUAL POR EL NOMBRE NUEVO
                break;
            case 1:
                do {
                    tempIdentifier = lastNames[rand() % 8] + " " + lastNames[rand() % 8];//NUEVO APELLIDO
                } while (tempIdentifier == name);//OBTENER EL NUEVO APELLIDO
                lastName = tempIdentifier;//SE CAMBIA EL APELLIDO ACTUAL POR EL APELLIDO NUEVO
                break;
            case 2:
                if (gender == 'F') gender = 'M';//CAMBIA EL GENERO
                else gender = 'F';//CAMBIA EL GENERO
                break;
            case 3:
                do {
                    day = formattedDateString(28, 1);
                    month = formattedDateString(12, 1);
                    year = formattedDateString(103, 1900);
                    tempIdentifier = day + "/" + month + "/" + year;
                } while (tempIdentifier == dateOfBirth);
                dateOfBirth = tempIdentifier;
                break;
            case 4:
                CURP.replace(13, 7, "DFRJXL5");//SE ALTERA LA ULTIMA SECCION
                break;
            case 5:
                do {
                    tempIdentifier = nationalities[rand() % 5];//NUEVA NACIONALIDAD
                } while (tempIdentifier == nationality);//OBTENER NUEVA NACIONALIDAD
                nationality = tempIdentifier;//SE CAMBIA LA NACIONALIDAD POR LA ACTUAL
                break;
            }            
            documents[1] = new INE("INE" + CURP, name, lastName, gender, dateOfBirth, CURP, nationality);//CREACION DE LA INE 
            status = 2;//HAY UN ERROR
            reason = "EL o LA\n" + identifiers[random] + " NO COINCIDE ";
            if (rand() % 2 == 0) terrorist = false;
            else {
                terrorist = true;
                reason += " Y ES TERRORISTA";
            }
        }
    }
};

int main() {
    system ("color 70"); 
    bool gameloop = true;
    int option, points = 0;
    Person* person;//CREAR UNA NUEVA PERSONA
    
    sf::Music music;
    music.openFromFile("audio/papermusic.wav");//SONIDO DE FONDO
    music.setVolume(50);
    music.play();
    music.setLoop(true);

    
    sf::Music music_1;
    music_1.openFromFile("audio/true.wav");
    music_1.setVolume(150);                  //SONIDO CORRECTO
 

    sf::Music music_0;
    music_0.openFromFile("audio/false.wav");
    music_0.setVolume(150);                 //SONIDO INCORRECTO
   

    while (gameloop) {
        person = new Person();//SE GENERA UNA NUEVA PERSONA EN CADA ITERACION
        cout << "**************************" << endl;
        cout << "PAPERS, PLEASE" << endl;
        cout << "**************************" << endl;
        cout << "*********" << endl;
        cout << "PUNTOS: " << points << endl;
        cout << "*********" << endl;
        cout << "SUS PAPELES POR FAVOR: " << endl;
        person->documents[0]->show();//SE MUESTRA EN LA CONSOLA EL PASAPORTE
        person->documents[1]->show();//SE MUESTRA EN CONSOLA LA INE 
        cout << "[1] PERMITIR ACCESO\n";
        cout << "[2] DENEGAR ACCESO\n";
        cout << "[3] SALIR DEL JUEGO\n";
        do {
            cout << "OPCION: ";
            cin >> option;
           
        } while (option < 1 || option > 3);
        switch (option) {
        case 1:
            if (person->status == 1){
                music_1.play();
                music_1.play();
                cout << "SE TE AUMENTO 1 PUNTO YA QUE ";
                points++;  
                system("color A");
            }
            else {
                if (person->terrorist) {
                    music_0.play();
                    music_0.play();
                    cout << "SE TE QUITARON 2 PUNTOS YA QUE ";
                    points -= 2;
                    system("color 4");
                }
                else {
                    music_0.play();
                    music_0.play();
                    cout << "SE TE QUITO 1 PUNTO YA QUE ";
                    points--;
                    system("color 4");
                }
            }
            cout << person->reason << endl;//SE MUESTRA LA RAZON
            break;
        case 2:
            if (person->status == 1) {
                music_0.play();
                music_0.play(); 
                cout << "SE TE QUITO 1 PUNTO YA QUE ";
                points--;
                system("color 4");
            }
            else {
                music_1.play();
                music_1.play();
                cout << "SE TE AUMENTO 1 PUNTO YA QUE ";
                points++;
                system("color A");  
            }
            cout << person->reason << endl;//SE MUESTRA LA RAZON
            break;
        case 3:
            gameloop = false;
            break;
        } 
        system("pause");
        system("cls");
        system("color 70");
    }
}

string formattedDateString(int max, int add) {
    int date = rand() % max + add;//CREACION DE UNA PARTE DE LA FECHA
    if (date < 10) return "0" + to_string(date);
    else return to_string(date);
}

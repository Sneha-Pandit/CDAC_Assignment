//============================================================================
// Name        : 3.cpp
// Author      : Sneha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Patient
{
private:
    int patientId;
    string name;
    int age;
    string ward;


    const string bloodGroup;

public:


    Patient()
        : patientId(0),
          name("Unknown"),
          age(0),
          ward("General"),
          bloodGroup("O+")
    {
        cout << "[Constructor] Default patient registered."
             << endl;
    }




    Patient(int id, const string& patientName)
        : patientId(id),
          name(patientName),
          age(0),
          ward("Emergency"),
          bloodGroup("O+")
    {
        cout << "[Constructor] Emergency: "
             << name << endl;
    }


    Patient(int id,
            const string& patientName,
            int patientAge,
            const string& patientWard,
            const string& bg)
        : patientId(id),
          name(patientName),
          age(patientAge),
          ward(patientWard),
          bloodGroup(bg)
    {
        cout << "[Constructor] Full admission: "
             << name << endl;
    }


    ~Patient()
    {
        cout << "[Destructor] Patient "
             << name
             << " discharged."
             << endl;
    }



    void displayRecord() const
    {
        cout << "\nPatient Record:" << endl;

        cout << " ID : "
             << patientId << endl;

        cout << " Name : "
             << name << endl;

        cout << " Age : "
             << age << endl;

        cout << " Ward : "
             << ward << endl;

        cout << " Blood Grp : "
             << bloodGroup << endl;
    }



    void transferWard(const string& newWard)
    {
        cout << "Ward Transfer: "
             << name
             << " -> "
             << newWard
             << endl;

        ward = newWard;
    }
};


int main()
{
    cout << "===== HOSPITAL PATIENT REGISTRY ====="
         << endl;



    Patient patient1;


    Patient patient2(1002, "Raj Patel");


    Patient patient3(
        1001,
        "Meera Joshi",
        34,
        "Cardiology",
        "B+"
    );



    cout << "\nPatient 1:";
    patient1.displayRecord();

    cout << "\nPatient 2:";
    patient2.displayRecord();

    cout << "\nPatient 3:";
    patient3.displayRecord();




    cout << "\n===== DYNAMIC PATIENT ARRAY ====="
         << endl;

    Patient* patients = new Patient[4];



    for (int i = 0; i < 4; i++)
    {
        cout << "\nPatient "
             << i + 1
             << ":";

        patients[i].displayRecord();
    }



    cout << endl;

    patients[1].transferWard("ICU");



    cout << "\nDeleting dynamic patient array..."
         << endl;

    delete[] patients;


    cout << "\n===== END OF QUESTION 2 ====="
         << endl;

    return 0;
}

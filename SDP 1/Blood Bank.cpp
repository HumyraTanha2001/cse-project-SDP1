#include <iostream>
#include<bits/stdc++.h>
#include <string.h>
#include <fstream>
using namespace std;

struct Donor                                      // Structure declaration
{
    string name,department,email,bloodType,date;  // Member (string variable)
    int age;                                      // Member (int variable)
    long long int id;                             // Member (long long int variable)
    long long int number;                         // Member (long long int variable)
    long long int num;
};

const int MAX_DONORS = 100;
Donor donors[MAX_DONORS];
int numdonors = 0;
void savedonerdata()
{
    ofstream file("donors.csv");
    if (file.is_open()) 
    {
        for (int i = 0; i < numdonors; i++) {
            file << donors[i].name << " \t " << donors[i].id<<" \t "<< donors[i].department<<"  "<< donors[i].bloodType << "  " << donors[i].age <<"  "<< donors[i].date<<"  "<< donors[i].num<<"  "<< donors[i].number<<"  " << donors[i].email<<"  "<<endl;
        }
        file.close();
    } else {
        cout << "Unable to open the file for saving." << endl;
    }
}
void DonorsdataFile() 
{
    ifstream file("donors.csv");

    if (file.is_open()) 
    {
        numdonors = 0;
        while (file >> donors[numdonors].name >> donors[numdonors].id >> donors[numdonors].department >> donors[numdonors].bloodType >> donors[numdonors].age>> donors[numdonors].date>> donors[numdonors].num>> donors[numdonors].number>> donors[numdonors].email) 
        {
            numdonors++;
        }
        file.close();
    } else {
        cout << "Unable to open the file. Starting with an empty donor list." << endl;
    }
}
void addDonors()
 {
    if (numdonors < MAX_DONORS) 
    {
        Donor newdonor;
        cout << "Enter donor frst name: ";
        cin>>newdonor.name; 
        //getline(cin,newdonor.name);             //using getline() function
        cout<<"Enter Your Id: ";
        cin>>newdonor.id;
        cout<<"Enter Your Department: ";
        cin>>newdonor.department;
        cout << "Enter blood type: ";
        cin >> newdonor.bloodType;
        cout << "Enter donor age: ";
        cin >> newdonor.age;
        cout<<"Enter Last Date Of Donation: ";
        cin>>newdonor.date;
        cout<<"Enter Number Of Donation: ";
        cin>>newdonor.num;
        cout<<"Enter Your Phone No: ";
        cin>>newdonor.number;
        cout<<"Enter Your Email: ";
        cin>>newdonor.email;

        donors[numdonors] = newdonor;
        numdonors++;

        cout << "\t\t\t Donor added successfully!" << endl;
        savedonerdata();  // Save donors' data to the file after adding a new donor
    }else{
         cout << "\t\t\t The blood bank is full. Cannot add more donors." << endl;
    }
}

void displayDonors()
 {
    cout << "::Donor List::" << endl;
    cout << "---------------" << endl;
    for (int i = 0; i < numdonors; i++) 
    {
        cout << "Donor " << i + 1 << ":" << endl;
        cout << "Name: " << donors[i].name << endl;
        cout<<"Student ID: "<<donors[i].id<<endl;
        cout << "Blood Type: " << donors[i].bloodType << endl;
        cout << "Age: " << donors[i].age << endl;
        cout<<"Last Date Of Donation: "<<donors[i].date<<endl;
        cout<<"Number Of Donation: "<<donors[i].num<<endl;
        cout<<" :-:Contact Info:-:"<<endl;
        cout<<"Phone: "<<donors[i].number<<endl;
        cout<<"Email: "<<donors[i].email<<endl;

        cout << "---------------------" << endl;
    }
}

void searchDonors() 
{
    string search;
    cout<<"\n\t\t========================================";
        cout<<"\n\t\t|   Enter a blood type to search for   |"<<endl;
        cout<<"\t\t========================================";
        cout<<endl;
        cout<<"\t\t\t: ";
    cin >> search;
    cout << "::Search Results::" << endl;
    cout << "------------------" << endl;
    for (int i = 0; i < numdonors; i++)
     {
        if (donors[i].bloodType == search)   //donors[i].name == search || donors[i].id == search
        {
            cout << "Donor " << i + 1 << ":" << endl;
            cout << "Name: " << donors[i].name << endl;
            cout<<"Student ID: "<<donors[i].id<<endl;
            cout << "Blood Type: " << donors[i].bloodType << endl;
            cout << "Age: " << donors[i].age << endl;
            cout<<"Last Date Of Donation: "<<donors[i].date<<endl;
            cout<<"Number Of Donation: "<<donors[i].num<<endl;
            cout<<" :-:Contact Info:-:"<<endl;
            cout<<"Phone: "<<donors[i].number<<endl;
            cout<<"Email: "<<donors[i].email<<endl;

            cout << "---------------------" << endl;
        }
        else
        {cout << " Blood Group not found" << endl;}
    }
}
void updateDonor() {
    string updateinfo;
    cout<<"\n\t\t=====================================================";
        cout<<"\n\t\t|   Enter The Name of The Donor You Want to Update   |"<<endl;
        cout<<"\t\t====================================================";
        cout<<endl;
        cout<<"\t\t\t: ";
    //cout << "Enter the name of the donor you want to update: ";
    cin >> updateinfo;
    
    for (int i = 0; i < numdonors; i++) 
    {
        if (donors[i].name == updateinfo) 
        {
            cout << "Enter the new Last Date Of Donation " << updateinfo << ": ";
            cin >> donors[i].date;
            cout << "Enter the new age for " << updateinfo << ": ";
            cin >> donors[i].age;
            cout << "Enter the new Number Of Donation " << updateinfo << ": ";
            cin >> donors[i].num;


            cout << "\t\t\t Donor information updated!" << endl;
            savedonerdata();
            return;
        }
    }
    
    cout << "\t\t\t Donor not found. Could not update." << endl;
}
void deleteDonor()
 {
    string deleteName;
    int j;
    cout<<"\n\t\t=====================================================";
        cout<<"\n\t\t|   Enter The Name of The Donor You Want to Delete  |"<<endl;
        cout<<"\t\t====================================================";
        cout<<endl;
        cout<<"\t\t\t: ";
    cin >> deleteName;
    for (int i = 0; i < numdonors; i++) {
        if (donors[i].name == deleteName) 
        {
            
            for (j = i; j < numdonors - 1; j++)     // Shift donors to remove the deleted donor
             {
                donors[j] = donors[j + 1];
            }
            numdonors--;
            cout <<"\t\t\t"<<deleteName << " Has been deleted from the list." << endl;
            savedonerdata();
            return;
        }
    }
    
    cout << "\t\t\t Donor not found. Could not delete." << endl;
}


int main() 
{
    DonorsdataFile();
    int choice;

    while (true) 
    {

        cout<<"\n\t\t=================================================";
        cout<<"\n\t\t|   BUBT Student Blood Bank Management System   |"<<endl;
        cout<<"\t\t=================================================";
        cout<<"\n\t \t \t ::Enter Your Choice::"<<endl;
        cout<<"\n\t\t\tTo Add New Donar Data \t(1)\n\t\t\tTo View List Of Donar\t(2)\n\t\t\tTo Search Donar \t(3)"<<endl;
        cout<<"\t\t\tTo Update Donar Data \t(4)\n\t\t\tTo Delete Donar Data\t(5)\n\t\t\tTo Log Out \t\t(6)"<<endl;
        cout<<"\t\t\t: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                system("cls");
                addDonors();
                break;
            case 2:
                system("cls");
                displayDonors();
                break;
            case 3:
             system("cls");
             searchDonors();
                break;
            case 4:
            system("cls");
            updateDonor();
                 break;
            case 5:
            system("cls");
            deleteDonor();
                break;    
            case 6:
                cout << "\n\t\t\t Thank You For Visiting Us!" << endl;
                return 0;
            default:
                system("cls");
                cout << "\t\t\t Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
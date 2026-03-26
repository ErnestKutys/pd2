#include <iostream>
#include <string>

using namespace std;

int main()
{
    int mokiniuKiekis = 0;
    string mokiniai[100];
    int pazymiai[100][10];
    int pazymiuKiekis[100];
    int pasirinkimas = -1;

    string temp;
    int tempint;
    while (pasirinkimas != 0)
    {
        // meniu:
        cout << "Pasirinkite veiksma:" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "1 - Prideti mokini." << endl;
        cout << "2 - Rodyti visus mokinius." << endl;
        cout << "3 - Rodyti vieno mokinio pazymius." << endl;
        cout << "4 - Keisti pazymi." << endl;
        cout << "5 - Istrinti mokini." << endl;
        cout << "0 - Iseiti." << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Iveskite veiksma: " << endl;
        cin >> pasirinkimas;

        switch (pasirinkimas)
        {
        case 1:
            cout << "Jus pasirinkote prideti mokini." << endl;
            cout << "Iveskite vardus ir kiek pazymius: " << endl;

            cin >> temp >> pazymiuKiekis[mokiniuKiekis];

            mokiniai[mokiniuKiekis] = temp;

            cout << "Jus pasirinkote prideti " << pazymiuKiekis[mokiniuKiekis] << " pazymiai." << endl;
            for (int i = 0; i < pazymiuKiekis[mokiniuKiekis]; i++)
            {
                cout << "Iveskite " << i + 1 << " pazymi" << endl;
                cin >> pazymiai[mokiniuKiekis][i];
            }
            mokiniuKiekis++;
            break;
        case 2:
            cout << "Jus pasirinkote parodyti visus mokinius." << endl;
            for (int i = 0; i < mokiniuKiekis; i++)
            {
                cout << i + 1 << " - " << mokiniai[i] << " - Pazymiai: ";
                for (int j = 0; j < pazymiuKiekis[i]; j++)
                {
                    cout << pazymiai[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 3:
            cout << "Jus pasirinkote parodyti vieno mokinio pazymius." << endl;
            cout << "Iveskite mokinio varda: " << endl;
            cin >> temp;
            for (int i = 0; i < mokiniuKiekis; i++)
            {
                if (temp == mokiniai[i])
                {
                    cout << mokiniai[i] << " - Pazymiai: ";
                    for (int j = 0; j < pazymiuKiekis[i]; j++)
                    {
                        cout << pazymiai[i][j] << " ";
                    }
                    break;
                }
            }
            break;
        case 4:
            cout << "Jus pasirinkote pasikeisti pazymi." << endl;
            cout << "Iveskite mokinio varda: " << endl;
            cin >> temp;
            for (int i = 0; i < mokiniuKiekis; i++)
            {
                if (temp == mokiniai[i])
                {
                    int temp1;
                    int temp2;
                    cout << "Rastas!" << endl;
                    cout << "Iveskite pazymio pozicija: " << endl;
                    cin >> temp1;
                    cout << "Iveskite pazymi: " << endl;
                    cin >> temp2;
                    pazymiai[i][temp1 - 1] = temp2;
                    break;
                }
            }
            break;
        case 5:
            int temp1;
            int temp2;
            temp2 = -1;
            cout << "Jus pasirinkote istrinti mokini." << endl;
            cout << "Iveskite mokinio varda: " << endl;
            cin >> temp;
            for (int i = 0; i < mokiniuKiekis; i++)
            {
                if (temp == mokiniai[i])
                {
                    cout << "Rastas!" << endl;
                    temp2 = i;
                    break;
                }
            }
            if (temp2 != -1)
            {
                cout << "Ar tikrai? Sio veiksmo atsaukti nebus galima. (1 - taip, 0 - ne) " << endl;

                cin >> temp1;
                switch (temp1)
                {
                case 1:
                    for (int i = temp2; i < mokiniuKiekis; i++)
                    {
                        mokiniai[i] = mokiniai[i + 1];
                        pazymiuKiekis[i] = pazymiuKiekis[i + 1];
                        for (int j = 0; j < pazymiuKiekis[i]; j++)
                        {
                            pazymiai[i][j] = pazymiai[i + 1][j];
                        }
                    }
                    mokiniuKiekis--;
                    break;
                case 0:
                    cout << "Istrinimas buvo atsauktas." << endl;
                    break;
                }
            }
            else
            {
                cout << "Vardas nera musu sarasoje." << endl;
            }
            break;
        case 0:
            cout << "Jus pasirinkote iseiti." << endl;
            break;
        }

    }

}
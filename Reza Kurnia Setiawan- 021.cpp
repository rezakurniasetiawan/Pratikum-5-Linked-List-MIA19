#include <iostream>
#include <conio.h>
#include <iomanip> 

using namespace std;


struct node
{
    string nama;
    string tanggal_lahir;
    string nim;
    node* next;
};

node* _head;
node* _tail;
node* _curr;
struct node* _entry;
node* _del;


void inisialisasi()
{
    _head = NULL;
    _tail = NULL;
}


void input(node &temp)
{
    _entry = new node;

    _entry->nama = temp.nama;
    _entry->tanggal_lahir = temp.tanggal_lahir;
    _entry->nim = temp.nim;
    _entry->next = NULL;

    if (_head == NULL)
    {
        _head = _entry;
        _tail = _head;
    }
    else
    {
        _tail->next = _entry;
        _tail = _entry;
    }
}

void hapus()
{
    node* _simpan;
    if (_head == NULL)
    {
        cout << "\nLinked list kosong, penghapusan tidak bisa dilakukan." << endl;
    }
    else
    {
        _simpan = _head;
        cout << "\nData yang dihapus adalah ";
        cout << _simpan->nama << "/" << _simpan->tanggal_lahir << "/" << _simpan->nim << endl;


        
        _del = _head;
        _head = _head->next;
        delete _del;
    }
}

void cetak()
{
    _curr = _head;
    if (_head == NULL)
        cout << "\ntidak ada data dalam linked list" << endl;
    else
    {
        cout << "\nData yang ada dalam linked list : \n" << endl;
        cout << "\t";
        while (_curr != NULL)
        {
            cout << _curr->nama << "/" << _curr->tanggal_lahir << "/" << _curr->nim;
            cout << " -> ";
            _curr = _curr->next;
        }
        cout << "NULL";
        cout << endl;
    }
}

void menu()
{
    char pilih, ulang;
    node tmp;

    do
    {
        fflush(stdin);
        system("cls");
        cout << "SINGLE LINKED LIST NON CIRCULAR" << endl;
        cout << "-------------------------------" << endl;
        cout << "Menu : " << endl;
        cout << "1. Input data" << endl;
        cout << "2. Hapus data" << endl;
        cout << "3. Cetak Data" << endl;
        cout << "4. Exit" << endl;
        cout << "Masukkan pilihan Anda : ";
        cin >> pilih;

        switch (pilih)
        {
        case '1':

            fflush(stdin);
            cout << "\nMasukkan nama  : ";
            cin >> tmp.nama;
            cout << "Masukkan tanggal_lahir : ";
            cin >> tmp.tanggal_lahir;
            cout << "Masukkan NIM   : ";
            cin >> tmp.nim;


            input(tmp);
            break;

        case '2':
            hapus();
            break;
        case '3':
            cetak();
            break;
        case '4':
            exit(0);
            break;
        default:
            cout << "\nPilihan salah" << endl;
        }
        cout << "\nKembali ke menu?(y/n)";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');
}

int main()
{

    inisialisasi();
    menu();

}


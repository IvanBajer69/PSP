#include <iostream>
#include <string>
using namespace std;
class Loto
{
private:
    int *niza;
    int vneseni_broevi;

public:
    Loto(int *n = NULL, int vb = 0)
    {
        if (n == NULL)
        {
            vb = 0;
            niza = new int[1];
            niza[0] = 1;
        }
        else
        {
            if (vb >= 0)
            {
                vneseni_broevi = vb;
                niza = new int[vneseni_broevi];
                for (int i = 0; i < vneseni_broevi; i++)
                {
                    niza[i] = n[i];
                }
            }
        }
    }
    ~Loto()
    {
        delete[] niza;
    }
    friend istream &operator>>(istream &in, Loto &p)
    {
        cout << "Vnesi dolzina na listata: " << endl;
        in >> p.vneseni_broevi;
        delete[] p.niza;
        p.niza = new int[p.vneseni_broevi];
        cout << "Vnesi gi elementite od listata: " << endl;
        for (int i = 0; i < p.vneseni_broevi; i++)
        {
            in >> p.niza[i];
        }
        return in;
    }
    friend ostream &operator<<(ostream &out, Loto &k)
    {
        out << "Dolzina na listata e: " << k.vneseni_broevi << endl;
        out << "Elementite vo listata se: " << endl;
        for (int i = 0; i < k.vneseni_broevi; i++)
        {
            out << k.niza[i] << "\t";
        }
        return out;
    }
    Loto &operator=(const Loto &l)
    {
        if (this == &l)
        {
            return *this;
        }
        vneseni_broevi = l.vneseni_broevi;
        delete[] niza;
        niza = new int[l.vneseni_broevi];
        for (int i = 0; i < l.vneseni_broevi; i++)
        {
            niza[i] = l.niza[i];
        }
        return *this;
    }
    friend bool operator==(const Loto &l1, const Loto &l2)
    {
        if (l1.vneseni_broevi != l2.vneseni_broevi)
        {
            return false;
        }
        for (int i = 0; i < l1.vneseni_broevi; i++)
        {
            if (l1.niza[i] != l2.niza[i])
            {
                return false;
            }
        }
        return true;
    }
    int &operator[](const int poz)
    {
        if (poz > vneseni_broevi)
        {
            cout << "Nevalidna pozicija" << endl;
            exit(-1);
        }
        return niza[poz];
    }
    Loto &operator++()
    {
        int *pom = new int[vneseni_broevi + 1];
        for (int i = 0; i < vneseni_broevi; i++)
        {
            pom[i] = niza[i];
        }
        delete[] niza;
        int br;
        cout << "Vnesete broj" << endl;
        cin >> br;
        pom[vneseni_broevi] = br;
        vneseni_broevi++;
        niza = pom;
        return *this;
    }
};
int main()
{
    Loto l1;
    cout << "Vnesi podatoci za livce 1: " << endl;
    cin >> l1;
    Loto l2;
    cout << "Vnesi podatoci za livce 2: " << endl;
    cin >> l2;
    cout << "Livce 1:" << l1 << endl;
    cout << "Livce 2:" << l2 << endl;
    if (l1 == l2)
    {
        cout << "livcinjata se isti" << endl;
    }
    else
    {
        cout << "Livcinjata se razlicni" << endl;
    }
    int index1, index2;
    cout <<"Vnesi index na element od livce 1" << endl;
    cin >> index1;
    cout << "Elementot na poz" << index1 << " e:" << l1[index1] << endl;
    cout<< "Vnesi index na element od livce 2" << endl;
    cin >> index2;
    cout << "Elementot na poz" << index2 << " e:" << l2[index2] << endl;
    ++l1;
    cout << "Livce 1 po dodavanje na element: " << l1 << endl;
    ++l2;
    cout << "Livce 2 po dodavanje na element: " << l2 << endl;
    return 0;
    
}

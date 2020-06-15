#include "iostream"
using namespace std;

float salario_total(int, int);
float salario_real(float);

int main(void)
{
    int n, i, hr, he;
    float SalarioT, SalarioR;

    cout << "\nIngresar el numero de empleados: ";
    cin >> n;

    for (i=1; i<=n; i++){
        cout << "\nIngresa el numero de horas regulares trabajadas por el empleado " << i << ":\n";
        cin >> hr;
        cout << "\nIngresa el numero de horas extra para el empleado numero " << i << ":\n";
        cin >> he;

        SalarioT = salario_total(hr, he);
        cout << "El salario total (sin descuentos) es: $ " << SalarioT << endl;

        SalarioR = salario_real(SalarioT);
        cout << "El salario real (salario neto) es: $ " << SalarioR << endl << endl;
    }

    return 0;
}

//Funcion que calcula el salario total

float salario_total(int hr, int he)
{
    float pago_hr, pago_he, total;

    pago_hr = hr * 1.75;
    pago_he = he * 2.50;

    total = pago_hr + pago_he;

    return total;
}

//Funcion que calcula el salario real

float salario_real(float SalarioT)
{
    float desc_ISSS, desc_AFP, renta = 0,total;

    desc_ISSS = SalarioT * 0.04;
    desc_AFP = SalarioT * 0.0625;

    if (SalarioT >= 500)
        renta = SalarioT * 0.1;

    total = SalarioT - desc_ISSS - desc_AFP - renta;

    return total;
}

/*#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double Te_eV;    // electron temperature in eV
    double ne_cm3;   // electron density in cm^{-3}

    cout << "=== Debye Length Calculator ===\n";
    cout << "Enter electron temperature Te (in eV): ";
    cin >> Te_eV;

    cout << "Enter electron density ne (in cm^{-3}, e.g. 1e12): ";
    cin >> ne_cm3;

    // Formula: λ_D ≈ 7430 * sqrt(Te / ne)   in meters
    // (valid for Te in eV, ne in cm^{-3})
    double lambda_D = 7430.0 * sqrt(Te_eV / ne_cm3);

    // Also show in microns and mm for convenience
    double lambda_um = lambda_D * 1e6;     // meters → micrometers
    double lambda_mm = lambda_D * 1e3;     // meters → millimeters

    cout << fixed << setprecision(4);
    cout << "\nResults:\n";
    cout << "Debye length λ_D = " << lambda_D << " m\n";
    cout << "                   = " << lambda_um << " µm\n";
    cout << "                   = " << lambda_mm << " mm\n";

    cout << "\n(using λ_D = 7430 √(Te/ne)   [Te in eV, ne in cm⁻³])\n";

    return 0;
}*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double Te_eV;     // electron temperature [eV]
    double ne_cm3;    // electron density     [cm^{-3}]

    cout << "=== Plasma Basics Calculator ===\n";
    cout << "Density always in cm^{-3}\n\n";

    cout << "Enter electron temperature Te (eV): ";
    cin >> Te_eV;

    cout << "Enter electron density ne (cm^{-3}, e.g. 1e12 or 5e13): ";
    cin >> ne_cm3;

    // Debye length: lambda_D ≈ 7430 * sqrt(Te / ne)   [m]
    double lambda_D_m  = 7430.0 * sqrt(Te_eV / ne_cm3);
    double lambda_D_um = lambda_D_m * 1e6;   // micrometers
    double lambda_D_mm = lambda_D_m * 1e3;   // millimeters

    // Electron plasma freq: f_pe ≈ 8988 * sqrt(ne)   [Hz]  (more precise constant)
    // From standard sources: ~8988 Hz / sqrt(cm^{-3})
    double f_pe_Hz  = 8988.0 * sqrt(ne_cm3);
    double f_pe_MHz = f_pe_Hz / 1e6;

    cout << fixed << setprecision(4) << "\n";
    cout << "Results (ne = " << scientific << setprecision(2) << ne_cm3 << " cm-3, Te = " << Te_eV << " eV):\n";
    cout << "----------------------------------------------------\n";
    cout << "Debye length lambda_D     = " << lambda_D_m  << " m     = " << lambda_D_um << " um\n";
    cout << "Electron plasma freq f_pe = " << f_pe_MHz << " MHz   (" << f_pe_Hz << " Hz)\n";
    cout << "----------------------------------------------------\n";

    cout << "\n(lambda_D = 7430 * sqrt(Te/ne) [m],  f_pe = 8988 * sqrt(ne) [Hz])\n";

    return 0;
}

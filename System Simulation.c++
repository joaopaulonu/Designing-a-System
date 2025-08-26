#include <iostream>
#include <cmath>
using namespace std;

// Estrutura para representar o material
struct Material {
    string name;
    double tensileStrength; // Limite de resistência (MPa)
    double elasticity;      // Módulo de elasticidade (GPa)
};

// Estrutura para representar a barra
struct Bar {
    double length;      // Comprimento (m)
    double area;        // Área da seção transversal (m²)
    Material material;  // Material
};

// Função que calcula tensão
double calculateStress(double force, double area) {
    return force / area; // Fórmula σ = F / A
}

// Função que calcula aceleração
double calculateAcceleration(double force, double mass) {
    return force / mass; // Fórmula a = F / m
}

int main() {
    // Definindo material
    Material steel = {"Steel", 400, 210}; // 400 MPa, 210 GPa

    // Criando barra
    Bar bar;
    bar.length = 2.0;   // metros
    bar.area = 0.01;    // m²
    bar.material = steel;

    // Força aplicada
    double force = 3000; // Newtons
    double mass = 50;    // kg

    // Cálculos
    double stress = calculateStress(force, bar.area) / 1e6; // convertido para MPa
    double acceleration = calculateAcceleration(force, mass);

    // Saída
    cout << "=== System Simulation ===" << endl;
    cout << "Material: " << bar.material.name << endl;
    cout << "Applied Force: " << force << " N" << endl;
    cout << "Stress: " << stress << " MPa" << endl;
    cout << "Acceleration: " << acceleration << " m/s²" << endl;

    if (stress > bar.material.tensileStrength) {
        cout << "⚠️ WARNING: Stress exceeds material strength. Failure expected!" << endl;
    } else {
        cout << "✅ Safe: Stress is within material limits." << endl;
    }

    return 0;
}

// 📊 What this project demonstrates:

//  Kinematics: indirect result on displacement (related to acceleration and time).

//Dynamics: use of Newton's Second Law (F = m · a).

//Material Strength: compares stress with the material's limit.

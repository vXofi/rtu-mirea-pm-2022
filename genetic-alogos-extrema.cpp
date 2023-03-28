#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <map>
#include <fstream>
#include <stdlib.h>
#include <random>
#include <sstream>
#include <algorithm>
#include <cstddef>
#include <type_traits>

using namespace std;

// www.math3d.org for plot (R3)
// 
//globals
const int population_size = 1024; // must be divisible by four
const int number_iterations = 4096;
const double mt_rate = 0.25;
int param = 0;



double f(double x, double y) {
    // selection of desired functions to find extrema of
    // global variable param, chosen in init() function
    // input: x value, y value
    // output: z value
    switch (param) {
    case 0:
        return 3 * x * x + x * y + 2 * y * y - x - 4 * y;
        break;
    case 1:
        return y * y + 2 * x * y - 4 * x - 2 * y - 3;
        break;
    case 2:
        return 4 + cbrt(pow(x * x + y * y, 2));
        break;
    case 3:
        return x * x * x + 8 * y * y * y - 6 * x * y + 5;
        break;
    case 4:
        return 2 * x * x * x * y * y * y + 3 * x * x * x * x + 5 * y - 7;
        break;
    case 5:
        return x * x * y - 3 * y * y + 5 * x;
        break;
    case 6:
        return y * log(x);
        break;
    case 7:
        return x * x - y * y * y;
        break;
    case 8:
        return x * x * y * y * (1 - x - y);
        break;
    case 9:
        return 3 * x + 9 * y - x * x - x * y - y * y - 4;
        break;
    case 10:
        return x * x * x + x * y * y + x * x + y * y;
        break;
    case 11:
        return x * x * x + 3 * x * y * y - 15 * x - 12 * y;
        break;
    case 12:
        return 1 - sqrt(x * x * x + y * y);
        break;
    case 13:
        return x * x + 3 * x * y * y - 15 * x - 12 * y;
        break;
    case 14:
        return x * x + y * y - x * y + x + y;
        break;
    case 15:
        return y * y * y + 2 * x * x - 12 * x * y + 4 * x - 12 * y + 2;
        break;
    }
}

int init() {
    // function to output selection of functions
    // global param variable in body of f() then should be reassigned to input
    int input;
    cout << "Choose function to find an extrema of by entering its number:" << endl;
    cout << "0) F(x,y) = 3x^2 + xy + 2y^2 - x - 4y" << endl;
    cout << "1) F(x,y) = y^2 + 2xy - 4x - 2y - 3" << endl;
    cout << "2) F(x,y) = 4 + cbrt((x * x + y * y)^2)" << endl;
    cout << "3) F(x,y) = x^3 + 8y^3 - 6xy + 5" << endl;
    cout << "4) F(x,y) = 2x^2 * xy^3 + 3x^4 + 5y - 7" << endl;
    cout << "5) F(x,y) = x^2y - 3y^2 + 5x" << endl;
    cout << "6) F(x,y) = ylog(x)" << endl;
    cout << "7) F(x,y) = x^2 - y^3" << endl;
    cout << "8) F(x,y) = x^2 * y^2 * (1 - x - y)" << endl;
    cout << "9) F(x,y) = 3x + 9y - x^2 - xy - y^2 - 4" << endl;
    cout << "10) F(x,y) = x^3 + xy^2 + x^2 + y^2" << endl;
    cout << "11) F(x,y) = x^3 + 3xy^2 - 15x - 12y" << endl;
    cout << "12) F(x,y) = 1 - sqrt(x^3 + y^2)" << endl;
    cout << "13) F(x,y) = x^2 + 3xy^2 - 15x - 12y" << endl;
    cout << "14) F(x,y) = x^2 + y^2 - xy + x + y" << endl;
    cout << "15) F(x,y) = y^3 + 2x^2 - 12xy + 4x - 12y + 2" << endl;
    cin >> input;
    if (input < 0 || input > 15) {return -1;}
    return input;
}

pair<double, double> grad_f(double x, double y, double epsilon = 0.00001) {
    // gradient of desired function, finding derivative numerically
    // input: x value, y value, /optional/ increment epsilon value
    //output: gradient pair by x value, y value respectively
    return make_pair((f(x + epsilon, y) - f(x, y)) / epsilon, (f(x, y + epsilon) - f(x, y)) / epsilon);
}

double fitness(pair<double, double> individual) {
    // evaluates fitness of a chromosome
    // the closer the value to 0 the better
    //input: (Chromosome) pair of x value, y value
    //output: fitness of a point (Chromosome)
    double x = individual.first;
    double y = individual.second;
    pair<double, double> values = grad_f(x, y);
    return abs(values.first) + abs(values.second);
}

class Chromosome
{
    // individual chromosome implementation
    // gene is a pair of x value, y value (individual point on a plain)
public:
    pair<double, double> gene;
    double fit = -1;

    Chromosome() {
        // Chormosome intitialization if no x, y values provided
        // initializases with a ranmdom value of <x, y> between 0 and 10
        // calculates intial fitness 
        gene = make_pair(static_cast <double> (((double)rand() / (RAND_MAX)) * 20 - 10), static_cast <double> (((double)rand() / (RAND_MAX)) * 20 - 10));
        fit = fitness(gene);
    }

    Chromosome(double x, double y) {
        // Chormosome intitialization if x, y values are provided
        // calculates fitness of a chromosome
        // input: x value, y value
        gene.first = x;
        gene.second = y;
        fit = fitness(gene);
    }

    void change_genes(pair<double, double> value) {
        // change x, y values of a Chromosome
        // input: pair of x value, y value
        gene.first = value.first;
        gene.second = value.second;
        fit = fitness(gene);
    }

    void set_fit() {
        // sets (calculated) fitness of a chromosome 
        fit = fitness(gene);
    }

};

bool less_than_fit(const Chromosome& struct1, const Chromosome& struct2) {
    // function to compare chromosomes by their fitness value
    // input: chromosome, chromosome
    // output: bool True/False
    return (struct1.fit < struct2.fit);
}

pair<Chromosome, Chromosome> offspring(Chromosome guy1, Chromosome guy2) {
    // function to calculate offspring of two chromosomes
    // input: two Chromosomes to get offspirng of
    // output: pair<Chromosome, Chromosome> of two new Chromosomes
    double beta = ((double)rand() / (RAND_MAX));
    double predict = ((double)rand() / (RAND_MAX));
    double xnew1, xnew2;

    if (predict < mt_rate) { xnew1 = ((double)rand() / (RAND_MAX)) * 20 - 10; }
    else { xnew1 = (1 - beta) * guy1.gene.first + beta * guy2.gene.first; }

    predict = ((double)rand() / (RAND_MAX));

    if (predict < mt_rate) { xnew2 = ((double)rand() / (RAND_MAX)) * 20 - 10; }
    else { xnew2 = (1 - beta) * guy2.gene.first + beta * guy1.gene.first; }

    Chromosome offspring1 = Chromosome(xnew1, guy1.gene.second);
    Chromosome offspring2 = Chromosome(xnew2, guy2.gene.first);

    return make_pair(offspring1, offspring2);
}

class Population
{
    //population of chromosomes implementation
    // population is a vector of chromosomes of specified size
public:
    vector<Chromosome> population;

    Population() {
        // initialization of population
        // input: size i.e. number of Chromosomes in a Population
        for (int i = 0; i < population_size; i++) {
            population.push_back(Chromosome());
        }
    }

    void print(int n) {
        // outputs n Chromosomes of Population in console in a column
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " - x: " << population[i].gene.first << " y: " << population[i].gene.second << " z:" << f(population[i].gene.first, population[i].gene.second) << endl;
        }
    }

    void print() {
        // outputs Chromosomes of Population in console in a column
        for (int i = 0; i < population.size(); i++) {
            cout << i+1 << " - x: " << population[i].gene.first << " y: " << population[i].gene.second << endl;
        }
    }

    double find_best_fitness() {
        // finds Chormosome with best fitness in a Population
        double minim = 10;
        Chromosome guy;

        for (auto a : population) {
            minim = min(minim, a.fit);
        }
        return minim;
    }

    void popul_sort() {
        // sorts Chromosomes in Population by fitness
        sort(population.begin(), population.end(), less_than_fit);
    }

    void new_gen() {
        //
        // !!!population must be sorted before a call!!!
        //
        // creates a new generation of Population
        // old Chromosomes are replaced with new ones
        int diverse = population.size() / 4;
        vector<Chromosome> offsprings;

        for (int i = 0; i < diverse; i++) {
            pair<Chromosome, Chromosome> siblings = offspring(population[i], population[i + 1]);
            offsprings.push_back(siblings.first);
            offsprings.push_back(siblings.second);
        }
        for (int i = 0; i < diverse * 2; i++) {
            offsprings.push_back(population[i]);
        }

        for (int i = 0; i < population.size(); i++) {
            population[i] = offsprings[i];
        }
    }

};

class GeneticAlgorithm
{
public:
    Population pup = Population();
    GeneticAlgorithm() {
    }
    void run() {
        // body of a genetic algorithm
        for (int i = 0; i < number_iterations; i++) {
            pup.popul_sort();
            pup.new_gen();
        }
        pup.print();
    }

    void best_estimation(int n) {
        //outputs n best estimation in a console
        cout << "BEST ESTIMATIONS" << endl;
        pup.print(n);
    }
};



int main(int argc, char* argv[]){
    srand(static_cast <unsigned> (time(0)));

    GeneticAlgorithm ga;
    int input;

    input = init();
    param = input;
    if (param == -1) {
        cout << "AN INVALID CHARACTER HAS BEEN ENTERED" << endl;
        return 0;
    }
    ga.run();
    cout << endl << "========" << endl;
    ga.pup.popul_sort();
    ga.best_estimation(1);

    cout << "Want to choose another funtion? (1-YES/0-NO)" << endl;
    cin >> input;
    if (input != 1 && input != 0) {
        cout << "AN INVALID CHARACTER HAS BEEN ENTERED" << endl;
        return 0;
    }

    while (input != 0) {

        input = init();
        param = input;
        if (param == -1) {
            cout << "AN INVALID CHARACTER HAS BEEN ENTERED" << endl;
            return 0;
        }
        ga.run();
        cout << endl << "========" << endl;
        ga.pup.popul_sort();
        ga.best_estimation(1);

        cout << "Want to choose another funtion? (1-YES/0-NO)" << endl;
        cin >> input;
        if (input != 1 && input != 0) {
            cout << "AN INVALID CHARACTER HAS BEEN ENTERED" << endl;
            return 0;
        }
    }
    return 0;
}




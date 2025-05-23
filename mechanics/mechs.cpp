#include <iostream> //only for testing
#include <vector>
#include <cmath>

using namespace std; 

namespace mechs {
    //All available functions are listed here
    double magnitude(const vector<double>&); //alias = l2norm
    double dot(const vector<double>&,const vector<double>&);


    double magnitude(const vector<double>& U){
        //Computes the euclidian norm of a vector 
        double squared_sum = 0;
        for (const double& component : U){
            squared_sum += component*component;
        }

        return sqrt(squared_sum);
    }
    const auto& l2norm = magnitude;

    double dot(const vector<double>& U,const vector<double>& V){
        double prod = 0;
        for (unsigned int i = 0; i<U.size(); i++){
            prod += U[i]*V[i];
        } 
        return prod;
    }
    
    double dot(const double& magA, const double& magB, const double& theta){
        return magA*magB*cos(theta);
    }
}

int main(){
    cout << mechs :: magnitude({3.43,5.87,2.871}) << endl;
    cout << mechs :: l2norm({3.43,5.87,2.871}) << endl;
    cout << mechs :: dot({3.43,5.87,2.871}, {3.43,5.87,2.871}) << endl;
    cout << mechs :: dot(32, 56, 1.43); 
    return 0;
}
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

    vector<double> resultant(vector<vector<double>> vecs){
        vector<double> resultant_vec;
        double summed_components; 
        
        for (unsigned int component_indx=0; component_indx<vecs[0].size(); component_indx++){
            summed_components = 0; 
            for (unsigned int vector_indx=0; vector_indx<vecs.size(); vector_indx++){
                summed_components += vecs[vector_indx][component_indx]; 
            }
            resultant_vec.push_back(summed_components);  
        }
        return resultant_vec;
    } 
}

int main(){ 
    vector<double> R; 
    R = mechs :: resultant({{3.43,5.87,2.871}, {3.43,5.87,6.871}, {3.43,2.87,2.871}, {3.43,5.87,2.871}});
    for (const double& component : R){
        cout << component << ", ";
    }
    return 0;
}`
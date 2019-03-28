#ifndef  MODEL_H
#define  MODEL_H

/**
 *  @file   model.h
 *  @brief  
 */

#include <string>

using namespace std;
// Model is responsible for data get and set

class Model {
    public:
        Model(const double &data);
        Model() { } // default constructor
        double Data();
 
        void SetData(const double &data);

    private:
        double data = 0;
};

#endif  /*< MODEL_H */

/**
 *  @file   model.h
 *  @brief  
 */

#include <string>

using namespace std;
// Model is responsible for data get and set


class Model {
    public:
        Model(const string &data);
        Model() { } // default constructor
        string Data();
 
        void SetData(const string &data);

    private:
        string data = "";
};
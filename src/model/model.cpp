/**
 *  @file   model.cpp
 *  @brief  
 */

#include "model.h"

Model::Model(const string &data) {
    this->SetData(data);
}

string Model::Data(){
    return this->data;
}

void Model::SetData(const string &data) {
    this->data = data;
}

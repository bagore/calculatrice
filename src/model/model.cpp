/**
 *  @file   model.cpp
 *  @brief  
 */

#include "Model.h"

Model::Model(const double &data) {
    this->SetData(data);
}

double Model::Data(){
    return this->data;
}

void Model::SetData(const double &data) {
    this->data = data;
}
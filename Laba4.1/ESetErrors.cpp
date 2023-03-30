//
//  ESetErrors.cpp
//  Laba4.1
//
//  Created by Ксения Дубова on 30.03.2023.
//

#include "ESetErrors.hpp"
#include <iostream>
using namespace std;

EUnpossibal::EUnpossibal() {};
void EUnpossibal:: print_error() const
{
    cout <<"Operation is unpossibal"<<endl;
}

EUncorrectIndex::EUncorrectIndex() {};
void EUncorrectIndex:: print_error() const
{
    cout <<"Uncorrect index"<<endl;
}

EEmpty::EEmpty() {};
void EEmpty:: print_error() const
{
    cout <<"It is empty"<<endl;
}

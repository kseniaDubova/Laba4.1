//
//  ESetErrors.hpp
//  Laba4.1
//
//  Created by Ксения Дубова on 30.03.2023.
//

#ifndef ESetErrors_hpp
#define ESetErrors_hpp

#include <stdio.h>
class ESetErrors
{
public: virtual void print_error() const = 0;
};

class EUnpossibal: public ESetErrors
{
public:
    EUnpossibal();
    void print_error() const;
};
class EUncorrectIndex: public ESetErrors
{
public:
    EUncorrectIndex();
    void print_error() const;
};
class EEmpty: public ESetErrors
{
public:
    EEmpty();
    void print_error() const;
};
#endif /* ESetErrors_hpp */

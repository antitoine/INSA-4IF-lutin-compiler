#ifndef LUTIN_COMPILER_SYMBOL_H
#define LUTIN_COMPILER_SYMBOL_H

class Symbol {

protected:
    int id;

public:
    Symbol(int id) : id(id) {}
    virtual ~Symbol() {}
    void print();
    operator int() const { return id; }

};

#endif //LUTIN_COMPILER_SYMBOL_H

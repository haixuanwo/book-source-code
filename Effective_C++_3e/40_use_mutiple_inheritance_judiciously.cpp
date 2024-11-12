

/*
条款40：明智而审慎地使用多重继承
多重继承可以让一个类同时继承多个基类的特性和功能。然而，不当使用多重继承会导致
复杂的继承层次、歧义和其他问题，应当谨慎使用。
*/

class Printer {
public:
    void printDocument() {}
};

class Scanner {
public:
    void scanDocument() {}
};

class Copier : public Printer, public Scanner {
    // 多重继承允许Copier同时具备打印和扫描的功能
};

Copier copier;
copier.printDocument();
copier.scanDocument();

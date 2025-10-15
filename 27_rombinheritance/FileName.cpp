#include <iostream>
using namespace std;

//1 варіант:

class component {
    string company_name;
public:
    component(string company_name) {
        this->company_name = company_name;
    }

    void set(string company_name) {
        this->company_name = company_name;
    }

    string get() {
        return company_name;
    }
};

class memory : public component {
public:
    memory(string company_name)
        : component(company_name) {}
};

class gpu : public component {
public:
    gpu(string company_name)
        : component(company_name) {}
};

class graphic_card : public gpu, public memory {
public:
    graphic_card(string gpu_company_name, string memory_company_name)
        :gpu(gpu_company_name), memory(memory_company_name) { }
};



//2 варіант:

class character {
public:
    int hp;
};

class warrior : public virtual character{

};

class boss : public virtual character {

};

class boss_warrior : public warrior, public boss {

};


int main() {

    //1
    /*graphic_card gc("Nvidia", "Sumsung");
    cout << gc.gpu::get();
    cout << gc.memory::get();*/

    //2
    character c;
    c.hp = 100;

    return 0;
}
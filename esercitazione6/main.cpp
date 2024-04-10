#include<iostream>

class List_uguali{
  public:
    List_uguali();
    List_uguali(const List_uguali& l);

    void aggiungi(int elem);
    void rimuovi(int elem);
    void stampa() const; 

    List_uguali operator+(const List_uguali& l) const;
    List_uguali& operator=(const List_uguali& l);

    ~List_uguali();

  private:
    struct Cella;
    typedef Cella* pCella;

    pCella list;


    /*spazio per altri metodo privati*/
};

struct List_uguali::Cella{
    int info;
    pCella next;
};

//Costruttore di default: non modificare il metodo
List_uguali::List_uguali() {
  list = nullptr;
}

//Distruttore: non modificare il metodo
List_uguali::~List_uguali() {
  pCella p=list;
  while(p) {
    p=p->next;
    delete list;
    list=p;
  }
}

//Implementare: Esercizio 1
//Aggiungi un elemento alla lista
void List_uguali::aggiungi(int elem) {

   pCella el_curr = list;
   pCella el_prec = nullptr;
   
   while( el_curr && el_curr->info != elem){
       el_prec = el_curr;
       el_curr = el_curr->next;
   }
   
   if(el_curr){
       pCella new_el = new Cella{elem, el_curr};
       if(el_prec) el_prec->next = new_el;
       else list = new_el;
       }else{
           pCella new_el  = new Cella{elem, nullptr}; 
             if(el_prec) el_prec->next = new_el;
             else list = new_el;
   }
        
}

//Implementare: Esercizio 1
//Stampa gli elementi della lista
void List_uguali::stampa() const {  
    pCella l = list ;    
    while(l){
        std::cout<<l->info<<std::endl;
        l=l->next ;
    }     
}

//Implementare: Esercizio 1
//Rimuovi un elemento dalla lista
void List_uguali::rimuovi(int elem) {
       pCella el_curr = list;
       pCella el_prec = nullptr;
       //[1|]->[5|]->[1|]->[1|]->[1|]->[3|]->[5|]
       //.          ^                          x    
       while(el_curr && el_curr->info != elem){
           el_prec = el_curr;
           el_curr = el_curr->next;
           }
           
       if(el_curr){
           if(el_prec){
               el_prec->next = el_curr->next;
           } else{
               list = el_curr->next;
           }
           delete el_curr;
       }
       
       
}
//Implementare: Esercizio 2
//Ridefinizione del copy constructor
List_uguali::List_uguali(const List_uguali& l) {
    list = nullptr;
    pCella el_curr = l.list;
    while(el_curr){
        aggiungi(el_curr->info);
        el_curr = el_curr->next;
    }

}
//Implementare: Esercizio 3
List_uguali& List_uguali::List_uguali::operator=(const List_uguali& l) {
    pCella el = list;
    while (el ){
        pCella el_succ = el->next;
        delete el;
        el =el_succ;
    }
    el = l.list;
    while (el) {
        aggiungi(el->info);
        el = el->next;
    }
  
  return *this;
}


//Implementare: Esercizio 3
List_uguali List_uguali::List_uguali::operator+(const List_uguali& l) const{
  List_uguali res;
  pCella el = list;

  
    while (el) {
        res.aggiungi(el->info);
          pCella el_succ = el->next;
            el = el_succ;
        }
    
    el = l.list;
    while (el) {
        res.aggiungi(el->info);
         pCella el_succ = el->next;
        el = el_succ;
    }
  // Aggiungi gli elementi di `l` alla nuova lista

  return res;

}
void leggi_lista(List_uguali& l) {
  int tote;
  int e;
  std::cin>>tote;
  for (int i=0; i<tote; i++) {
    std::cin>>e;
    l.aggiungi(e);
  }
}

void rimuovi(List_uguali& l) {
  int tote;
  int e;
  std::cin>>tote;
  for (int i=0; i<tote; i++) {
    std::cin>>e;
    l.rimuovi(e);
  }
}

void leggi_ancora(List_uguali l) {
  leggi_lista(l);
  std::cout<<"Output copia"<<std::endl;
  l.stampa();
}

int main() {
  List_uguali l1, l2;
  leggi_lista(l1);
  leggi_lista(l2);
  l2 = l1+l2;
  std::cout<<"Output"<<std::endl;
  l1.stampa();
  std::cout<<"Output"<<std::endl;
  l2.stampa();

  return 0;
}


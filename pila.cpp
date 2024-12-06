 #include <iostream>
using namespace std;
//-------------------------------------------------------
template <typename T>
class Pila {
 private:
 
   struct Nodo {
       T valore;    
       Nodo* next;    
   };
 
   Nodo* topPila;  
   int lenght;        
 
 public:

   Pila() {
       topPila = NULL;
       lenght = 0;
   }
 
   ~Pila() {
       while (topPila != NULL) {
           Nodo* temp = topPila;
           topPila = topPila->next;
           delete temp;
       }
   }
 
//PUSH
   void push(T elem) {
       Nodo* nuovo = new Nodo{elem, topPila};
       topPila = nuovo;
       lenght++;
   }

//POP
   T pop() {
       if (isEmpty()) {
           cout << "ERROR: Pila vuota." <<endl;
           return T();
       }
 
       Nodo* temp = topPila;
       T valore = topPila->valore;
       topPila = topPila->next;
       delete temp;
       lenght--;
 
       return valore;
   }

//-TOP
   T top() const {
       if (isEmpty()) {
           cout << "ERROR: Pila vuota." <<endl;
           return T();
       }
 
       return topPila->valore;
   }

//IS EMPTY
   bool isEmpty() const {
       return lenght == 0;
   }

//SIZE
   int size() const {
       return lenght;
   }
   //-------------------------------------------------------
};
 
 
using namespace std;
 
int main() {
 
   Pila<int> pila;
 
   cout << "La pila e' vuota? ---> " << (pila.isEmpty() ? "SI" : "NO") << endl;
   cout << "Dimensione della pila ---> " << pila.size() << endl;
   cout << "Aggiungo 27 alla pila." << endl;
   pila.push(27);
   cout << "Aggiungo 34 alla pila." << endl;
   pila.push(34);
   cout << "Aggiungo 69 alla pila." << endl;
   pila.push(69);
   cout << "Elemento in cima alla pila ---> " << pila.top() << endl;
   cout << "Dimensione della pila ---> " << pila.size() << endl;
   cout << "Tolgo dalla pila ---> " << pila.pop() << endl;
   cout << "Nuovo elemento in cima ---> " << pila.top() << endl;
   cout << "Dimensione della pila ---> " << pila.size() << endl;
   cout << "Tolgo dalla pila ---> " << pila.pop() << endl;
   cout << "Tolgo dalla pila ---> " << pila.pop() << endl;
   cout << "La pila e' vuota? ---> " << (pila.isEmpty() ? "SI" : "NO") << endl;
   cout << "Dimensione della pila ---> " << pila.size() << endl;
 
   return 0;
}

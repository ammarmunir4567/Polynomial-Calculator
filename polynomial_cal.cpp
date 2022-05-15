#include <iostream>
#include <cmath>

using namespace std;

class polynomial {
private:
    class term
    {
    public:
        int expo;
        int cof;
        term* next;
    public:
        term(int p, int c) {
            expo = p;
            cof = c;
            next = nullptr;
        }
        term() {
            expo = NULL;
            cof = NULL;
            next = nullptr;
        }
        term(int x) {
            expo = x;
            cof = x;
            next = nullptr;
        }
    };
    term* head;
    int size;

public:

    polynomial() {
        head = nullptr;
        size = 0;

    }
  

    polynomial(polynomial & p){
        head = nullptr;
        
        
        term *temp2=p.head;
        int c;
        int ex;
            while(temp2!=nullptr){
                c=temp2->cof;
                ex=temp2->expo;
                insert(head, c, ex);


                temp2=temp2->next;
            }



        }

    


    void input() {
        cout << "----polynomial------" << endl;
        cout << "Enter the number of terms" << endl;
        cin >> size;
        int cof;
        int expo;
       
        for (int i = 0; i < size; i++) {
            cout << "Enter the coefficient of term" << endl;
            cin >> cof;
            cout << "Enter the exponent of term" << endl;
            cin >> expo;
            insert(head,cof, expo);
        }
        simple(head);
    }
    term* insert(term* &h,int co, int  exp) {
        term* current = new term;
        current = h;
        term* temp = new term;
        temp->cof = co;
        temp->expo = exp;
        if (h == nullptr) {
            h = temp;
            current = h;
        }
        else {
            if (h->expo < temp->expo)
            {
                temp->next = h;
                h = temp;
                current = h;
            }

            else if (h->expo == temp->expo) {

                h->cof = h->cof + temp->cof;
            }
            else if (h->expo > temp->expo)
            {
                current = h;
                bool flag = false;
                if (current->next == nullptr) {
                    current->next = temp;
                }
                else {
                    while (current->next != nullptr && flag == false)
                    {
                        if (current->next->expo < temp->expo) {

                            temp->next = current->next;
                            current->next = temp;
                            flag = true;
                            
                        }
                        if (current->next->next == nullptr) {
                            current->next->next = temp;
                            flag = true;
                        }
                        current = current->next;
                    }
                }
            }

        }
        
        return h;
    }
    void simple(term* current) {
        while (current != nullptr) {

            if (current->next == nullptr)
            {
                break;
            }

            if (current->expo == current->next->expo)
            {

                if (current->next->next == nullptr) {
                    current->cof = current->cof + current->next->cof;
                    current->next = nullptr;
                }
                else {
                    current->cof = current->cof + current->next->cof;
                    current->next = current->next->next;
                }
            }
            if (current->cof == 0) {


            }
            current = current->next;
        }
    }
    void output(term* t) {
        term* t1 = new term;
        t1=t;
        cout << t1->cof << "n^" << t1->expo << " ";
        t1 = t1->next;
        while (t1 != nullptr) {
            if (t1->expo == 0 && t1->cof > 0) {

                cout << "+" << t1->cof;
            }
            else if (t1->expo == 0 && t1->cof < 0) {
                cout << t1->cof;

            }

            else   if (t1->cof > 0) {
                cout << "+" << t1->cof << "n^" << t1->expo << " ";

            }
            else if (t1->cof == 0) {

            }
            else {
                cout << t1->cof << "n^" << t1->expo << " ";
            }

            t1 = t1->next;

        }
        cout << endl;
       

    }

    void print() {
        term* t1 = new term;
        t1=head;
        cout << t1->cof << "n^" << t1->expo << " ";
        t1 = t1->next;
        while (t1 != nullptr) {
            if (t1->expo == 0 && t1->cof > 0) {

                cout << "+" << t1->cof;
            }
            else if (t1->expo == 0 && t1->cof < 0) {
                cout << t1->cof;

            }

            else   if (t1->cof > 0) {
                cout << "+" << t1->cof << "n^" << t1->expo << " ";

            }
            else if (t1->cof == 0) {

            }
            else {
                cout << t1->cof << "n^" << t1->expo << " ";
            }

            t1 = t1->next;

        }
        cout << endl;
      

    }

void add(const polynomial & p) {
    term* temp = new term;
    temp = head;
    term* temp2 = new term;
    temp2 = p.head;
    term* iso = new term;
    term* temp3 = iso;
    while (temp != nullptr && temp2 != nullptr) {

        if (temp->expo == temp2->expo) {
            temp3->next = temp;

            temp = temp->next;
            temp3 = temp3->next;
            temp3->next = temp2;

            temp2 = temp2->next;

        }


        else if (temp->expo > temp2->expo) {
            temp3->next = temp;

            temp = temp->next;


        }
        else if (temp->expo < temp2->expo) {
            temp3->next = temp2;

            temp2 = temp2->next;

        }
        

        temp3 = temp3->next;


    }
    while (temp2 != nullptr) {

        temp3->next = temp2;
        temp2 = temp2->next;
        temp3 = temp3->next;

    }

    while (temp != nullptr) {

        temp3->next = temp;
        temp = temp->next;
        temp3 = temp3->next;
    }

    head = iso->next;
    simple(head);
    cout<<"The sum of polynomaials is :"<<endl;
    output(head);
  
}
    

    void multiply(const polynomial & p){
        term* temp=new term;
        temp=head;
        term *temp2=new term;
        temp2=p.head;
        term* temp3=new term;
        int cof_result;
        int expo_result;
        while(temp!=nullptr){
            temp2=p.head;
            while(temp2!=nullptr){
                expo_result=temp->expo+temp2->expo;
                cof_result=temp->cof*temp2->cof;
               insert(temp3,cof_result, expo_result);
                
                temp2=temp2->next;
            }
            temp=temp->next;
            
        }
       simple(temp3);
        output(temp3);
     
        
    }
    
    void evaluate(int x){
        int sum=0;
        term* temp=new term;
        temp=head;
        while(temp!=nullptr){
            sum=sum+pow(x,temp->expo)*temp->cof;
            temp=temp->next;
        }
        cout<<"the evaluation :  "<<sum;
       
    }


    
    void operator +(polynomial const p ){
     
        add(p);
    }
    void operator *(polynomial const p ){
     
        multiply(p);
    }
    void operator [](int x){
     
        evaluate( x);
    }
    
    
    void operator =(const polynomial & p){
        
        {
            term *temp2=new term;
                temp2=p.head;
                int co;
                int ex;

                while(temp2!=nullptr){
                    co=temp2->cof;
                    ex=temp2->expo;

                    insert(head, co, ex);

                    temp2=temp2->next;
                }

          

            }
    }
    
  
//    ~polynomial(){
//        term* current = head;
//        term* t;
//
//        while( current != nullptr ) {
//
//            t= current->next;
//            delete current;
//            current = t;
//        }
//        head = nullptr;
//
//
//    }
    

};

int main() {
    polynomial p, p1;
    int x;
    cout<<"---=-W-E-L-C-O-M-E----T-O----P-O-L-Y-N-O-M-I-A-L----C-A-L-C-U-L-A-T-O-R------"<<endl<<endl;
    cout<<"Press 1: For addition of two polynomials"<<endl;
    cout<<"Press 2: For multiplication of two polynomials"<<endl;
    cout<<"Press 3: For evaluation of a polynomial"<<endl;
    cout<<"Press 4: For copying "<<endl;
    cin>>x;
    if(x==1){
        p.input();
        p1.input();
        cout<<"the first polynomal is :";
        p.print();
        cout<<endl;
        cout<<"the second polynomal is :";
        p1.print();
        cout<<endl;
        p+p1;
     
        
    }
    if(x==2){
        p.input();
        p1.input();
        cout<<"the first polynomal is :";
        p.print();
        cout<<endl;
        cout<<"the second polynomal is :";
        p1.print();
        cout<<"The product of polynomials is : "<<endl;
        p*p1;
      
        
    }
    if(x==3){
        int x;
        p.input();
        cout<<"the first polynomal is :";
        p.print();
        cout<<"Enter the number to put "<<endl;
        cin>>x;
        p[x];
        cout<<endl;
      
        
    }
    if(x==4){
        p.input();
        polynomial p1(p);
        p1.print();
        
    }
    return 0;
}

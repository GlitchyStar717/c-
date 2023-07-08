//2.cpp
//dynamiclly allocate and delete operator

#include<iostream>

using namespace std;

int strlen(const char input[]){
    int i = 0;
    while (input[i] != '\0'){
        i++;
    }
    return (i);
}

void strcpy(char* s1, const char* s2){
    int i, length = strlen(s2);
    for (i=0; i < length; i++){
        s1[i]=s2[i];
    }
    s1[i]= '\0';
}

char* strcat(char* s1, char* s2){
    int i, len1 = strlen(s1), len2 = strlen(s2);
    char *string;
    string = new char[len1 + len2 + 1];
    strcpy (string, s1);
    for (i=0; i< len2; i++){
        string[len1+i]= s2[i];
    }
    string[len1+i]='\0';
    return string;

}

class text{
    private:
        char* phrase;
    public:
        text (const char* input = nullptr){
            if (input == nullptr){
                cout << "Nothing was passed while creation of object.\n";
                phrase = nullptr;
            }
            else {
                phrase = new char[strlen(input) + 1];
                strcpy(phrase,input);
            }
    }
    ~text (){
        delete[] phrase;
        cout<<"Destructor called. !.!\n";
    }  
    void display_text(){
        if(phrase != nullptr){
            cout<<phrase<<endl;
        }
        else{
            cout<< "nothing to display here\n";
        }
    }
    void join(text t1, text t2){
        if(phrase != nullptr){
            delete[] phrase;
        }
        phrase = new char[strlen(t1.phrase) + strlen(t2.phrase) + 1];
        phrase = strcat(t1.phrase,t2.phrase);
    }

};

int main(){

    text t1("Engineers are"), t2(" Creatures of logic"),t3;
    t1.display_text();
    t2.display_text();
    t3.display_text();
    t3.join(t1,t2);
    t3.display_text();
    return 0;
}
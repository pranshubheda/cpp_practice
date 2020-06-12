#include<iostream>
using namespace std;

void print_pattern_1() 
{
    for(int i=0; i<5; i++) 
    {
        if(i%2 != 0) 
            cout << " ";
        for(int j=0; j<5; j++)
        {
            cout << "* ";
        }
        cout << std::endl;
    }    
}

void print_pattern_2() 
{
    for(int i=0; i<5; i++) 
    {
        for(int j=0; j<5; j++)
        {
            if(i==0 || i==4 || j==0 || j==4 )
                cout << "* ";
            else
                cout << "  ";
        }
        cout << std::endl;
    }    
}

void print_pattern_3() 
{
    for(int i=0; i<5; i++) 
    {
        for(int j=0; j<i; j++)
        {
            cout << " ";
        }

        for(int j=0; j<5-i; j++)
        {
            if(i==0 || j==0 || j==(5-i-1))
                cout << "* ";
            else
                cout << "  ";
        }

        cout << std::endl;
    }    
}

void pint_pattern_4()
{
    for(int i=0; i<3; i++) 
    {
        for(int j=0; j<3-i; j++)
        {
            cout << "  ";
        }
        for(int k=0; k<2*i+1; k++) {
            if(k==0 || k==2*i)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }

    for(int i=3; i>=0; i--) 
    {
        for(int j=0; j<3-i; j++)
        {
            cout << "  ";
        }
        
        for(int k=0; k<2*i+1; k++) {
            if(k==0 || k==2*i)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

int main() 
{
    cout << "Enter pattern number" << std::endl;
    int pattern_number;
    cin >> pattern_number;

    switch (pattern_number) 
    {
    case 1:
        print_pattern_1();    
        break;
    case 2:
        print_pattern_2();
        break;
    case 3:
        print_pattern_3();
        break;
    case 4:
        pint_pattern_4();
        break;
    
    default:
        cout << "Invalid Selection";
        break;
    }
}
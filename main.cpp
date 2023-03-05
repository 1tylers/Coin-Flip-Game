
// Include Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//Put the Coin class definition after this line
class Coin
{
    // Make the variables private
private:
    double coin_value;
    string coin_side;
    
    // Make the constructors and method initializers public
public:
    Coin();
    Coin(double);
    Coin(double, string);
    
    void flip();
    string getSide();
    double getValue();
};

int main()
{
    
//Set the random number generator and the formatting for the output
srand(15);
cout << fixed << setprecision(2);
    
    // Create the 4 coin objects
    Coin penny;
    Coin dime( 0.10 );
    Coin nickel( 0.05 );
    Coin quarter( 0.25, "heads" );
    
    // Initialize Starting value
    double starting_val = 0.00;
    
    // Display starting value
    cout << "The starting balance is $" << starting_val << '\n' << '\n';
    
    // Create Loop to run until the value is no longer less than 1
    while (starting_val < 1.00)
    {
        // Call the flip method for each coin to get the side
        penny.flip();
        nickel.flip();
        dime.flip();
        quarter.flip();
        
        // Display the penny side
        cout << "Penny:" << setw(15) << penny.getSide() << '\n';
        
        // If the penny landed heads add its value to the overall sum
        if (penny.getSide() == "heads")
        {
            starting_val += penny.getValue();
        }
        
        // Display the nickel side
        cout << "Nickel:" << setw(14) << nickel.getSide() << '\n';
        
        // If the nickel landed heads add its value to the overall sum
        if (nickel.getSide() == "heads")
        {
            starting_val += nickel.getValue();
        }
        
        // Display the dime side
        cout << "Dime:" << setw(16) << dime.getSide() << '\n';
        
        // If the dime landed heads add its value to the overall sum
        if (dime.getSide() == "heads")
        {
            starting_val += dime.getValue();
        }
        
        // Display the quarter side
        cout << "Quarter:" << setw(13) << quarter.getSide() << '\n';
        
        // If the quarter landed heads add its value to the overall sum
        if (quarter.getSide() == "heads")
        {
            starting_val += quarter.getValue();
        }
        
        // Display the current balance after each round of coin flipping
        cout << '\n'<< "After flipping the coins, the current balance is $" << starting_val << '\n';
        cout << "------------------------------------------------------" << '\n' << '\n';
        
    }
    
    // Display whether you won or lost determined by if you got exactly 1 dollar or not
    if (starting_val == 1.00)
    {
        cout << "The final balance is $" << starting_val << ". You won!" << '\n' << '\n';
    }
    else
    {
        cout << "The final balance is $" << starting_val << ". You lost." << '\n' << '\n';
    }
    
return 0;
}

//Code the constructors and methods for the Coin class after this line

// First coin constructor
Coin::Coin()
{
    coin_value = 0.01;
    flip();
}

// Second coin constructor
Coin::Coin(double initial_val)
{
    coin_value = initial_val;
    flip();
}

// Third coin constructor
Coin::Coin(double initial_val, string initial_side)
{
    coin_value = initial_val;
    coin_side = initial_side;
}

/*
 Method: flip()
 
 Use: Flips coin to determine if heads or tails
 
 Arguments: none
 
 returns: nothing
 */

void Coin::flip()
{
    int flipper;
    flipper = rand() % 2 + 1;
    
    if (flipper == 2)
    {
        coin_side = "tails";
    }
    else
    {
        coin_side = "heads";
    }
}

/*
 Method: getSide()
 
 Use: returns the side of the coin it landed on, heads/tails
 
 Arguments: none
 
 Returns: coin_side
 */

string Coin::getSide()
{
    return coin_side;
}

/*
 Method: getValue()
 
 Use: returns the value of the coin
 
 Arguments: none
 
 Returns: coin_value
 */

double Coin::getValue()
{
    return coin_value;
}

#include <iostream>

int MainMenu();
void CurrentToDo();
void AddToDo();

int main()
{   
    int app_state = true;
    
    while(app_state){
       app_state = MainMenu();
    }

}

int MainMenu(){
  std::cout << "Ten-A-Day\n";
  std::cout << "1. Current to-dos\n";
  std::cout << "2. Add new to-dos\n";
  std::cout << "3. Exit\n";
  int choice = 0;
  std::cin >> choice;
  if(choice == 1){
     CurrentToDo();
     return 1;
  }else if( choice == 2){
     // code for adding to-dos
     return 1;
  }
  else{
     return 0;
  }
}

void CurrentToDo(){
    std::cout << "Start 10 minute counter for...\n";
    std::cout << "1. Code\n";
    std::cout << "2. Exercise\n";
    std::cout << "3. Languages\n";
    std::cout << "4. Guitar\n";
    std::cout << "5. Arts\n";
    std::cout << "6. Study\n\n";
    int choice = 0;
    std::cin >> choice;
    // start 10 minute counter 

}